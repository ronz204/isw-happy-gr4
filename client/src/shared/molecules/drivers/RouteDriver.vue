<script setup lang="ts">
import { ref, computed } from "vue";
import { Navigation, X, ChevronDown, ChevronUp, ArrowRight } from "@lucide/vue";
import SelectAtom from "@atoms/Select.vue";
import { useGetLandmarks } from "@providers/useGetLandmarks";
import { useNavigateGraph } from "@providers/useNavigateGraph";
import { useRouteStore } from "@stores/useRouteStore";
import type { RouteRequest } from "@api/navigate.graph";

const PROFILES = [
  { label: "Regular", value: "Regular" },
  { label: "Nuevo estudiante", value: "NewStudent" },
  { label: "Silla de ruedas", value: "Wheelchair" },
] as const;

const STRATEGIES = [
  { label: "Dijkstra", value: "Dijkstra" },
  { label: "BFS", value: "BFS" },
  { label: "DFS", value: "DFS" },
] as const;

const { options: landmarkOptions, isLoading: loadingLandmarks } = useGetLandmarks();
const mutation = useNavigateGraph();
const routeStore = useRouteStore();

const expanded = ref(true);
const startNodeId = ref<number | undefined>(undefined);
const endNodeId = ref<number | undefined>(undefined);
const profile = ref<RouteRequest["profile"]>("Regular");
const strategy = ref<RouteRequest["strategy"]>("Dijkstra");

const hasRoute = computed(() => routeStore.route !== null);
const canSearch = computed(
  () => startNodeId.value !== undefined && endNodeId.value !== undefined && !mutation.isPending.value
);

const resultInfo = computed(() => {
  const r = routeStore.route;
  if (!r) return null;
  return {
    success: r.success,
    algorithm: r.algorithm,
    distance: r.distance.toFixed(1),
    stops: r.path.length,
  };
});

function onSearch() {
  if (!canSearch.value) return;
  mutation.mutate(
    {
      startNodeId: startNodeId.value!,
      endNodeId: endNodeId.value!,
      profile: profile.value,
      strategy: strategy.value,
    },
    {
      onSuccess: (data) => routeStore.setRoute(data),
    }
  );
}

function onClear() {
  routeStore.clear();
  mutation.reset();
  startNodeId.value = undefined;
  endNodeId.value = undefined;
}
</script>

<template>
  <div class="absolute top-4 left-4 z-1000 w-72 select-none">
    <!-- Collapsed toggle -->
    <button class="flex items-center gap-2 px-3 py-2 rounded-xl shadow-lg text-sm font-semibold transition-all w-full"
      :class="expanded
        ? 'bg-gray-900 border border-gray-700 text-white rounded-b-none border-b-0'
        : 'bg-gray-900 border border-gray-700 text-white hover:bg-gray-800'" @click="expanded = !expanded">
      <Navigation :size="15" class="shrink-0 text-amber-400" />
      <span class="flex-1 text-left">Buscar Ruta</span>
      <div v-if="hasRoute && !expanded" class="w-2 h-2 rounded-full bg-amber-400 shrink-0" />
      <component :is="expanded ? ChevronUp : ChevronDown" :size="14" class="text-gray-400 shrink-0" />
    </button>

    <!-- Panel body -->
    <Transition name="panel">
      <div v-if="expanded"
        class="bg-gray-900 border border-gray-700 border-t-0 rounded-b-xl px-4 pt-3 pb-4 shadow-lg space-y-3">
        <!-- Start node -->
        <div>
          <label class="block text-[10px] uppercase tracking-wide text-gray-400 mb-1 font-medium">Origen</label>
          <SelectAtom v-model="startNodeId" :options="landmarkOptions" placeholder="Selecciona origen"
            :disabled="mutation.isPending.value || loadingLandmarks" />
        </div>

        <!-- Arrow separator -->
        <div class="flex items-center justify-center">
          <ArrowRight :size="14" class="text-gray-500" />
        </div>

        <!-- End node -->
        <div>
          <label class="block text-[10px] uppercase tracking-wide text-gray-400 mb-1 font-medium">Destino</label>
          <SelectAtom v-model="endNodeId" :options="landmarkOptions" placeholder="Selecciona destino"
            :disabled="mutation.isPending.value || loadingLandmarks" />
        </div>

        <!-- Profile -->
        <div>
          <label class="block text-[10px] uppercase tracking-wide text-gray-400 mb-1.5 font-medium">Perfil</label>
          <div class="flex gap-1.5">
            <button v-for="p in PROFILES" :key="p.value" type="button"
              class="flex-1 py-1.5 rounded-lg text-[11px] font-medium border transition-all" :class="profile === p.value
                ? 'bg-amber-500/20 border-amber-500/50 text-amber-300'
                : 'bg-gray-800 border-gray-700 text-gray-400 hover:text-gray-200 hover:border-gray-600'"
              :disabled="mutation.isPending.value" @click="profile = p.value">
              {{ p.label }}
            </button>
          </div>
        </div>

        <!-- Strategy -->
        <div>
          <label class="block text-[10px] uppercase tracking-wide text-gray-400 mb-1.5 font-medium">Algoritmo</label>
          <div class="flex gap-1.5">
            <button v-for="s in STRATEGIES" :key="s.value" type="button"
              class="flex-1 py-1.5 rounded-lg text-[11px] font-medium border transition-all" :class="strategy === s.value
                ? 'bg-amber-500/20 border-amber-500/50 text-amber-300'
                : 'bg-gray-800 border-gray-700 text-gray-400 hover:text-gray-200 hover:border-gray-600'"
              :disabled="mutation.isPending.value" @click="strategy = s.value">
              {{ s.value }}
            </button>
          </div>
        </div>

        <!-- Actions -->
        <div class="flex gap-2 pt-1">
          <button
            class="flex-1 flex items-center justify-center gap-1.5 py-2 rounded-lg text-xs font-semibold transition-all disabled:opacity-50 disabled:cursor-not-allowed"
            :class="canSearch
              ? 'bg-amber-500 hover:bg-amber-400 text-gray-900'
              : 'bg-gray-800 border border-gray-700 text-gray-500'" :disabled="!canSearch" @click="onSearch">
            <Navigation :size="13" />
            {{ mutation.isPending.value ? 'Buscando…' : 'Buscar ruta' }}
          </button>

          <button v-if="hasRoute"
            class="flex items-center justify-center w-9 h-9 rounded-lg border border-gray-700 bg-gray-800 hover:bg-gray-700 text-gray-400 hover:text-white transition-all"
            title="Limpiar ruta" @click="onClear">
            <X :size="14" />
          </button>
        </div>

        <!-- Result summary -->
        <Transition name="fade">
          <div v-if="resultInfo" class="pt-1">
            <!-- No path found -->
            <div v-if="!resultInfo.success"
              class="flex items-center gap-2 px-3 py-2 rounded-lg bg-red-500/10 border border-red-500/30">
              <div class="w-1.5 h-1.5 rounded-full bg-red-400 shrink-0" />
              <span class="text-xs text-red-300">Sin ruta entre estos nodos</span>
            </div>

            <!-- Path found -->
            <div v-else
              class="flex items-center justify-between px-3 py-2 rounded-lg bg-amber-500/10 border border-amber-500/30">
              <div class="flex items-center gap-2">
                <div class="w-1.5 h-1.5 rounded-full bg-amber-400 shrink-0" />
                <span class="text-xs text-amber-300 font-semibold">{{ resultInfo.algorithm }}</span>
              </div>
              <div class="flex items-center gap-3 text-[11px] text-gray-400">
                <span>{{ resultInfo.distance }} u</span>
                <span>{{ resultInfo.stops }} nodos</span>
              </div>
            </div>
          </div>
        </Transition>

        <!-- Error -->
        <Transition name="fade">
          <div v-if="mutation.isError.value"
            class="px-3 py-2 rounded-lg bg-red-500/10 border border-red-500/30 text-xs text-red-300">
            Error al conectar con el servidor
          </div>
        </Transition>
      </div>
    </Transition>
  </div>
</template>

<style scoped>
.panel-enter-active,
.panel-leave-active {
  transition: opacity 0.15s ease, transform 0.15s ease;
}

.panel-enter-from,
.panel-leave-to {
  opacity: 0;
  transform: translateY(-6px);
}

.fade-enter-active,
.fade-leave-active {
  transition: opacity 0.15s ease;
}

.fade-enter-from,
.fade-leave-to {
  opacity: 0;
}
</style>
