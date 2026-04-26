<script setup lang="ts">
import { ref, computed } from "vue";
import { Search, ShieldBan, ShieldCheck, ArrowRight, Route, Layers, Weight } from "@lucide/vue";
import BlockForm from "../components/BlockForm.vue";
import { useSearchEdge } from "@providers/useSearchEdge";
import { usePatchCloseEdge, usePatchOpenEdge } from "@providers/usePatchEdgeStatus";

const searchMutation = useSearchEdge();
const closeEdgeMutation = usePatchCloseEdge();
const openEdgeMutation = usePatchOpenEdge();

const lastSearchParams = ref<{ fromNodeId: number; toNodeId: number } | null>(null);

const edge = computed(() => searchMutation.data.value?.edge ?? null);
const found = computed(() => searchMutation.data.value?.found ?? false);

const isLoading = computed(
  () =>
    searchMutation.isPending.value ||
    closeEdgeMutation.isPending.value ||
    openEdgeMutation.isPending.value
);

const canClose = computed(() => found.value && edge.value?.status === "Open");
const canOpen = computed(() => found.value && edge.value?.status === "Closed");

function onSearch(data: { fromNodeId: number; toNodeId: number }) {
  lastSearchParams.value = data;
  searchMutation.mutate(data);
}

function onClose() {
  if (!edge.value) return;
  closeEdgeMutation.mutate(edge.value.id, {
    onSuccess: () => lastSearchParams.value && searchMutation.mutate(lastSearchParams.value),
  });
}

function onOpen() {
  if (!edge.value) return;
  openEdgeMutation.mutate(edge.value.id, {
    onSuccess: () => lastSearchParams.value && searchMutation.mutate(lastSearchParams.value),
  });
}
</script>

<template>
  <div class="w-full h-full overflow-auto" style="background: var(--ui-bg)">
    <div class="max-w-2xl mx-auto px-6 py-10">

      <!-- Header -->
      <div class="flex items-start gap-4 mb-8">
        <div
          class="flex items-center justify-center w-11 h-11 rounded-xl shrink-0 mt-0.5"
          :class="found && edge
            ? edge.status === 'Open' ? 'bg-green-500/12 text-green-400' : 'bg-red-500/12 text-red-400'
            : 'bg-primary/12 text-primary-lite'"
        >
          <ShieldBan :size="20" />
        </div>
        <div class="flex-1 min-w-0">
          <h1 class="text-xl font-bold text-foreground leading-tight">Bloqueo de Edges</h1>
          <p class="text-sm text-muted-foreground mt-1">
            Busca un edge por sus nodos para cambiar su estado de acceso.
          </p>
        </div>
        <!-- Status pill when result is loaded -->
        <Transition name="fade">
          <UBadge
            v-if="found && edge"
            :color="edge.status === 'Open' ? 'success' : 'error'"
            variant="subtle"
            size="md"
            class="shrink-0 mt-1"
          >
            {{ edge.status === "Open" ? "Abierto" : "Bloqueado" }}
          </UBadge>
        </Transition>
      </div>

      <!-- Search card -->
      <UCard class="mb-5">
        <template #header>
          <div class="flex items-center gap-2">
            <Search :size="14" class="text-muted-foreground" />
            <span class="text-sm font-semibold text-foreground">Buscar Edge</span>
          </div>
        </template>
        <BlockForm :loading="isLoading" @submit="onSearch" />
      </UCard>

      <!-- Error state -->
      <Transition name="fade">
        <UAlert
          v-if="searchMutation.isError.value"
          color="error"
          variant="soft"
          title="Error al buscar"
          :description="(searchMutation.error.value as any)?.message ?? 'No se pudo conectar con el servidor'"
          class="mb-5"
        />
      </Transition>

      <!-- Not found state -->
      <Transition name="fade">
        <UCard v-if="searchMutation.isSuccess.value && !found" class="mb-5">
          <div class="flex flex-col items-center py-10 gap-3">
            <div class="flex items-center justify-center w-12 h-12 rounded-full bg-(--ui-bg-accented)">
              <Search :size="20" class="text-muted-foreground" />
            </div>
            <div class="text-center">
              <p class="text-sm font-semibold text-foreground">Sin resultados</p>
              <p class="text-xs text-muted-foreground mt-0.5">No existe un edge con esos nodos.</p>
            </div>
          </div>
        </UCard>
      </Transition>

      <!-- Result card -->
      <Transition name="fade">
        <UCard v-if="found && edge">
          <template #header>
            <div class="flex items-center gap-2">
              <Route :size="14" class="text-muted-foreground" />
              <span class="text-sm font-semibold text-foreground">Edge #{{ edge.id }}</span>
            </div>
          </template>

          <!-- Node route row -->
          <div
            class="flex items-center gap-3 px-4 py-3 rounded-xl mb-5 font-mono text-sm"
            style="background: var(--ui-bg-elevated); border: 1px solid var(--ui-border)"
          >
            <div class="flex flex-col items-center gap-0.5">
              <span class="text-[10px] font-sans uppercase tracking-wide text-muted-foreground">Origen</span>
              <span class="font-bold text-foreground text-base">{{ edge.fromNodeId }}</span>
            </div>
            <div class="flex-1 flex items-center gap-1">
              <div class="flex-1 h-px" style="background: var(--ui-border-accented)"></div>
              <ArrowRight :size="14" class="text-muted-foreground shrink-0" />
              <div class="flex-1 h-px" style="background: var(--ui-border-accented)"></div>
            </div>
            <div class="flex flex-col items-center gap-0.5">
              <span class="text-[10px] font-sans uppercase tracking-wide text-muted-foreground">Destino</span>
              <span class="font-bold text-foreground text-base">{{ edge.toNodeId }}</span>
            </div>
          </div>

          <!-- Metadata grid -->
          <div class="grid grid-cols-3 gap-3 mb-6">
            <div
              class="flex flex-col gap-1.5 px-4 py-3 rounded-xl"
              style="background: var(--ui-bg-elevated); border: 1px solid var(--ui-border)"
            >
              <div class="flex items-center gap-1.5 text-muted-foreground">
                <Route :size="12" />
                <span class="text-[10px] uppercase tracking-wide font-medium">Tipo</span>
              </div>
              <p class="text-sm font-semibold text-foreground">{{ edge.type }}</p>
            </div>

            <div
              class="flex flex-col gap-1.5 px-4 py-3 rounded-xl"
              style="background: var(--ui-bg-elevated); border: 1px solid var(--ui-border)"
            >
              <div class="flex items-center gap-1.5 text-muted-foreground">
                <Layers :size="12" />
                <span class="text-[10px] uppercase tracking-wide font-medium">Piso</span>
              </div>
              <p class="text-sm font-semibold text-foreground">{{ edge.floor }}</p>
            </div>

            <div
              class="flex flex-col gap-1.5 px-4 py-3 rounded-xl"
              style="background: var(--ui-bg-elevated); border: 1px solid var(--ui-border)"
            >
              <div class="flex items-center gap-1.5 text-muted-foreground">
                <Weight :size="12" />
                <span class="text-[10px] uppercase tracking-wide font-medium">Peso</span>
              </div>
              <p class="text-sm font-semibold text-foreground">{{ edge.weight.toFixed(2) }}</p>
            </div>
          </div>

          <!-- Status + Actions -->
          <div
            class="flex items-center justify-between gap-3 pt-4"
            style="border-top: 1px solid var(--ui-border)"
          >
            <div class="flex items-center gap-2">
              <div
                class="w-2 h-2 rounded-full"
                :class="edge.status === 'Open' ? 'bg-green-400' : 'bg-red-400'"
              />
              <span class="text-xs text-muted-foreground">
                {{ edge.status === "Open" ? "Este edge permite tránsito" : "Este edge está bloqueado al tránsito" }}
              </span>
            </div>

            <div class="flex gap-2">
              <UButton
                v-if="canClose"
                color="error"
                variant="soft"
                :loading="closeEdgeMutation.isPending.value"
                :disabled="isLoading"
                @click="onClose"
              >
                <ShieldBan :size="14" />
                Bloquear
              </UButton>
              <UButton
                v-if="canOpen"
                color="success"
                variant="soft"
                :loading="openEdgeMutation.isPending.value"
                :disabled="isLoading"
                @click="onOpen"
              >
                <ShieldCheck :size="14" />
                Abrir
              </UButton>
            </div>
          </div>
        </UCard>
      </Transition>

    </div>
  </div>
</template>

<style scoped>
.fade-enter-active,
.fade-leave-active {
  transition: opacity 0.18s ease, transform 0.18s ease;
}
.fade-enter-from,
.fade-leave-to {
  opacity: 0;
  transform: translateY(6px);
}
</style>
