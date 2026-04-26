<script setup lang="ts">
import { computed } from "vue";
import { FlaskConical, Timer, Ruler, TrendingDown, CheckCircle, XCircle } from "@lucide/vue";
import LabForm from "../components/LabForm.vue";
import PerformanceChart from "../components/PerformanceChart.vue";
import { useGetPerformance } from "@providers/useGetPerformance";
import type { PerformanceRequest, AlgorithmResult } from "@api/perform.models";

const mutation = useGetPerformance();

const results = computed<AlgorithmResult[]>(() => mutation.data.value?.results ?? []);

const bestDistance = computed(() => {
  const successful = results.value.filter((r) => r.success);
  if (!successful.length) return null;
  return successful.reduce((a, b) => (a.distance <= b.distance ? a : b));
});

const bestTime = computed(() => {
  const successful = results.value.filter((r) => r.success);
  if (!successful.length) return null;
  return successful.reduce((a, b) => (a.time <= b.time ? a : b));
});

const ALGO_COLOR: Record<string, string> = {
  BFS: "text-blue-400",
  DFS: "text-violet-400",
  Dijkstra: "text-emerald-400",
};

const ALGO_BG: Record<string, string> = {
  BFS: "bg-blue-500/10 border-blue-500/20",
  DFS: "bg-violet-500/10 border-violet-500/20",
  Dijkstra: "bg-emerald-500/10 border-emerald-500/20",
};

function onSubmit(data: PerformanceRequest) {
  mutation.mutate(data);
}
</script>

<template>
  <div class="w-full h-full overflow-auto" style="background: var(--ui-bg)">
    <div class="max-w-3xl mx-auto px-6 py-10">

      <!-- Header -->
      <div class="flex items-start gap-4 mb-8">
        <div
          class="flex items-center justify-center w-11 h-11 rounded-xl shrink-0 mt-0.5 bg-primary/12 text-primary-lite">
          <FlaskConical :size="20" />
        </div>
        <div>
          <h1 class="text-xl font-bold text-foreground leading-tight">Laboratorio de Rendimiento</h1>
          <p class="text-sm text-muted-foreground mt-1">
            Compara BFS, DFS y Dijkstra sobre el mismo grafo. Analiza distancia y tiempo de ejecución.
          </p>
        </div>
      </div>

      <!-- Form card -->
      <UCard class="mb-6">
        <template #header>
          <div class="flex items-center gap-2">
            <FlaskConical :size="14" class="text-muted-foreground" />
            <span class="text-sm font-semibold text-foreground">Configurar análisis</span>
          </div>
        </template>
        <LabForm :loading="mutation.isPending.value" @submit="onSubmit" />
      </UCard>

      <!-- Error -->
      <Transition name="fade">
        <UAlert v-if="mutation.isError.value" color="error" variant="soft" title="Error al ejecutar análisis"
          :description="(mutation.error.value as any)?.message ?? 'No se pudo conectar con el servidor'" class="mb-6" />
      </Transition>

      <!-- Results -->
      <Transition name="fade">
        <div v-if="mutation.isSuccess.value && results.length">

          <!-- Algorithm cards -->
          <div class="grid grid-cols-3 gap-3 mb-5">
            <div v-for="result in results" :key="result.algorithm"
              class="relative flex flex-col gap-3 px-4 py-4 rounded-xl border" :class="ALGO_BG[result.algorithm]">
              <!-- Name + status -->
              <div class="flex items-center justify-between">
                <span class="text-sm font-bold" :class="ALGO_COLOR[result.algorithm]">
                  {{ result.algorithm }}
                </span>
                <CheckCircle v-if="result.success" :size="14" class="text-emerald-400" />
                <XCircle v-else :size="14" class="text-red-400" />
              </div>

              <!-- Distance -->
              <div class="flex flex-col gap-0.5">
                <div class="flex items-center gap-1 text-muted-foreground">
                  <Ruler :size="11" />
                  <span class="text-[10px] uppercase tracking-wide font-medium">Distancia</span>
                </div>
                <span class="text-lg font-bold text-foreground font-mono leading-none">
                  {{ result.success ? result.distance.toFixed(1) : "—" }}
                  <span v-if="result.success" class="text-xs font-normal text-muted-foreground">m</span>
                </span>
                <!-- Best badge -->
                <span v-if="result.success && bestDistance?.algorithm === result.algorithm"
                  class="text-[10px] font-semibold text-emerald-400">
                  ↓ menor distancia
                </span>
              </div>

              <!-- Time -->
              <div class="flex flex-col gap-0.5">
                <div class="flex items-center gap-1 text-muted-foreground">
                  <Timer :size="11" />
                  <span class="text-[10px] uppercase tracking-wide font-medium">Tiempo</span>
                </div>
                <span class="text-lg font-bold text-foreground font-mono leading-none">
                  {{ result.success ? result.time.toFixed(3) : "—" }}
                  <span v-if="result.success" class="text-xs font-normal text-muted-foreground">ms</span>
                </span>
                <span v-if="result.success && bestTime?.algorithm === result.algorithm"
                  class="text-[10px] font-semibold text-blue-400">
                  ↓ menor tiempo
                </span>
              </div>
            </div>
          </div>

          <!-- Charts -->
          <div class="grid grid-cols-2 gap-4">
            <!-- Distance chart -->
            <UCard>
              <template #header>
                <div class="flex items-center gap-2">
                  <Ruler :size="13" class="text-muted-foreground" />
                  <span class="text-sm font-semibold text-foreground">Distancia</span>
                  <span class="text-xs text-muted-foreground ml-auto">metros</span>
                </div>
              </template>
              <PerformanceChart :results="results" metric="distance" label="Distancia" unit="m" />
            </UCard>

            <!-- Time chart -->
            <UCard>
              <template #header>
                <div class="flex items-center gap-2">
                  <Timer :size="13" class="text-muted-foreground" />
                  <span class="text-sm font-semibold text-foreground">Tiempo</span>
                  <span class="text-xs text-muted-foreground ml-auto">milisegundos</span>
                </div>
              </template>
              <PerformanceChart :results="results" metric="time" label="Tiempo" unit="ms" />
            </UCard>
          </div>

          <!-- Summary footer -->
          <div class="mt-4 flex items-center gap-3 px-4 py-3 rounded-xl text-sm"
            style="background: var(--ui-bg-elevated); border: 1px solid var(--ui-border)">
            <TrendingDown :size="15" class="text-emerald-400 shrink-0" />
            <span class="text-muted-foreground">
              Menor distancia:
              <span class="font-semibold" :class="ALGO_COLOR[bestDistance?.algorithm ?? '']">
                {{ bestDistance?.algorithm }} ({{ bestDistance?.distance.toFixed(1) }} m)
              </span>
            </span>
            <span class="mx-1 text-muted-foreground/30">·</span>
            <Timer :size="13" class="text-blue-400 shrink-0" />
            <span class="text-muted-foreground">
              Menor tiempo:
              <span class="font-semibold" :class="ALGO_COLOR[bestTime?.algorithm ?? '']">
                {{ bestTime?.algorithm }} ({{ bestTime?.time.toFixed(3) }} ms)
              </span>
            </span>
          </div>

        </div>
      </Transition>

    </div>
  </div>
</template>

<style scoped>
.fade-enter-active,
.fade-leave-active {
  transition: opacity 0.2s ease, transform 0.2s ease;
}

.fade-enter-from,
.fade-leave-to {
  opacity: 0;
  transform: translateY(8px);
}
</style>
