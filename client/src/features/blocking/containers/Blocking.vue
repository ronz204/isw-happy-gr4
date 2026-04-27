<script setup lang="ts">
import { ref, computed } from "vue";
import { useQueryClient } from "@tanstack/vue-query";
import type { ApiEdge, ApiNode } from "@api/graph.models";
import { useGetNodesByFloor } from "@providers/useGetNodesByFloor";
import { ShieldBan, ShieldCheck, ArrowRight, Route } from "@lucide/vue";
import { usePatchCloseEdge, usePatchOpenEdge } from "@providers/usePatchEdgeStatus";

const FLOORS = [
  { id: 2, label: "P2" },
  { id: 4, label: "P4" },
  { id: 5, label: "P5" },
];

const queryClient = useQueryClient();
const floorId = ref<number>(4);
const showOnlyClosed = ref(false);
const pendingEdgeId = ref<number | null>(null);

const { data, isFetching } = useGetNodesByFloor(floorId);
const closeEdgeMutation = usePatchCloseEdge();
const openEdgeMutation = usePatchOpenEdge();

interface EnrichedEdge extends ApiEdge {
  fromCode: string;
  toCode: string;
}

const enrichedEdges = computed<EnrichedEdge[]>(() => {
  const nodeMap = new Map<number, ApiNode>(
    (data.value?.nodes ?? []).map((n) => [n.id, n])
  );

  const HIDDEN_TYPES = new Set(["Stairs", "Elevator"]);

  return (data.value?.edges ?? [])
    .filter((e) => !HIDDEN_TYPES.has(e.type))
    .filter((e) => !showOnlyClosed.value || e.status === "Closed")
    .map((e) => ({
      ...e,
      fromCode: nodeMap.get(e.fromNodeId)?.code ?? String(e.fromNodeId),
      toCode: nodeMap.get(e.toNodeId)?.code ?? String(e.toNodeId),
    }));
});

const closedCount = computed(
  () => {
    const HIDDEN_TYPES = new Set(["Stairs", "Elevator"]);
    return (data.value?.edges ?? []).filter((e) => e.status === "Closed" && !HIDDEN_TYPES.has(e.type)).length;
  }
);

function onClose(edgeId: number) {
  pendingEdgeId.value = edgeId;
  closeEdgeMutation.mutate(edgeId, {
    onSuccess: () => {
      pendingEdgeId.value = null;
      queryClient.invalidateQueries({ queryKey: ["floor", floorId.value] });
    },
    onError: () => { pendingEdgeId.value = null; },
  });
}

function onOpen(edgeId: number) {
  pendingEdgeId.value = edgeId;
  openEdgeMutation.mutate(edgeId, {
    onSuccess: () => {
      pendingEdgeId.value = null;
      queryClient.invalidateQueries({ queryKey: ["floor", floorId.value] });
    },
    onError: () => { pendingEdgeId.value = null; },
  });
}
</script>

<template>
  <div class="w-full h-full overflow-auto" style="background: var(--ui-bg)">
    <div class="max-w-2xl mx-auto px-6 py-10">

      <!-- Header -->
      <div class="flex items-start gap-4 mb-8">
        <div
          class="flex items-center justify-center w-11 h-11 rounded-xl shrink-0 mt-0.5 bg-primary/12 text-primary-lite">
          <ShieldBan :size="20" />
        </div>
        <div class="flex-1 min-w-0">
          <h1 class="text-xl font-bold text-foreground leading-tight">Bloqueo de Edges</h1>
          <p class="text-sm text-muted-foreground mt-1">
            Selecciona un piso para ver y gestionar el estado de sus edges.
          </p>
        </div>
        <Transition name="fade">
          <UBadge v-if="closedCount > 0" color="error" variant="subtle" size="md" class="shrink-0 mt-1">
            {{ closedCount }} bloqueado{{ closedCount !== 1 ? 's' : '' }}
          </UBadge>
        </Transition>
      </div>

      <!-- Floor selector + filter -->
      <div class="flex items-center justify-between gap-4 mb-5">
        <div class="flex gap-2">
          <button v-for="floor in FLOORS" :key="floor.id" type="button"
            class="px-4 py-1.5 rounded-lg text-sm font-medium border transition-all"
            :class="floorId === floor.id
              ? 'bg-primary/15 border-primary/40 text-primary-lite'
              : 'bg-(--ui-bg-elevated) border-(--ui-border) text-muted-foreground hover:text-foreground hover:border-accented'" @click="floorId = floor.id">
            {{ floor.label }}
          </button>
        </div>

        <label class="flex items-center gap-2 cursor-pointer select-none">
          <UCheckbox v-model="showOnlyClosed" />
          <span class="text-xs text-muted-foreground">Solo bloqueadas</span>
        </label>
      </div>

      <!-- Loading skeleton -->
      <div v-if="isFetching" class="space-y-2">
        <div v-for="i in 6" :key="i" class="h-14 rounded-xl animate-pulse" style="background: var(--ui-bg-elevated)" />
      </div>

      <!-- Empty state -->
      <Transition name="fade">
        <div v-if="!isFetching && enrichedEdges.length === 0" class="flex flex-col items-center py-16 gap-3">
          <div class="flex items-center justify-center w-12 h-12 rounded-full bg-(--ui-bg-accented)">
            <Route :size="20" class="text-muted-foreground" />
          </div>
          <p class="text-sm font-semibold text-foreground">Sin edges</p>
          <p class="text-xs text-muted-foreground">
            {{ showOnlyClosed ? 'No hay edges bloqueadas en este piso.' : 'Este piso no tiene edges registradas.' }}
          </p>
        </div>
      </Transition>

      <!-- Edge list -->
      <Transition name="fade">
        <div v-if="!isFetching && enrichedEdges.length > 0" class="space-y-2">
          <div v-for="edge in enrichedEdges" :key="edge.id"
            class="flex items-center gap-3 px-4 py-3 rounded-xl transition-colors"
            style="background: var(--ui-bg-elevated); border: 1px solid var(--ui-border)">
            <!-- Route label -->
            <div class="flex items-center gap-1.5 flex-1 min-w-0 font-mono text-xs">
              <span class="text-foreground font-semibold truncate">{{ edge.fromCode }}</span>
              <ArrowRight :size="12" class="text-muted-foreground shrink-0" />
              <span class="text-foreground font-semibold truncate">{{ edge.toCode }}</span>
            </div>

            <!-- Status dot -->
            <div class="flex items-center gap-1.5 shrink-0">
              <div class="w-1.5 h-1.5 rounded-full shrink-0"
                :class="edge.status === 'Open' ? 'bg-green-400' : 'bg-red-400'" />
              <span class="text-xs text-muted-foreground w-16">
                {{ edge.status === 'Open' ? 'Abierto' : 'Bloqueado' }}
              </span>
            </div>

            <!-- Action button -->
            <UButton v-if="edge.status === 'Open'" color="error" variant="ghost" size="xs"
              :loading="pendingEdgeId === edge.id" :disabled="pendingEdgeId !== null" @click="onClose(edge.id)">
              <ShieldBan :size="13" />
              Bloquear
            </UButton>
            <UButton v-else color="success" variant="ghost" size="xs" :loading="pendingEdgeId === edge.id"
              :disabled="pendingEdgeId !== null" @click="onOpen(edge.id)">
              <ShieldCheck :size="13" />
              Abrir
            </UButton>
          </div>
        </div>
      </Transition>

    </div>
  </div>
</template>

<style scoped>
.fade-enter-active,
.fade-leave-active {
  transition: opacity 0.15s ease, transform 0.15s ease;
}

.fade-enter-from,
.fade-leave-to {
  opacity: 0;
  transform: translateY(4px);
}
</style>
