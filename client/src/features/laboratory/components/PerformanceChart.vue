<script setup lang="ts">
import {
  ref,
  onMounted,
  onBeforeUnmount,
  watch,
} from "vue";
import {
  Chart,
  BarController,
  BarElement,
  CategoryScale,
  LinearScale,
  Tooltip,
} from "chart.js";
import type { AlgorithmResult } from "@api/perform.models";

Chart.register(BarController, BarElement, CategoryScale, LinearScale, Tooltip);

const ALGO_STYLE: Record<string, { bg: string; border: string }> = {
  BFS: { bg: "rgba(96,  165, 250, 0.75)", border: "rgba(96,  165, 250, 1)" },
  DFS: { bg: "rgba(167, 139, 250, 0.75)", border: "rgba(167, 139, 250, 1)" },
  Dijkstra: { bg: "rgba(52,  211, 153, 0.75)", border: "rgba(52,  211, 153, 1)" },
};

const props = defineProps<{
  results: AlgorithmResult[];
  metric: "distance" | "time";
  label: string;
  unit: string;
}>();

const canvas = ref<HTMLCanvasElement | null>(null);
let chart: Chart | null = null;

function buildChart() {
  if (!canvas.value) return;
  chart?.destroy();

  const successful = props.results.filter((r) => r.success);

  chart = new Chart(canvas.value, {
    type: "bar",
    data: {
      labels: successful.map((r) => r.algorithm),
      datasets: [
        {
          label: props.label,
          data: successful.map((r) => r[props.metric]),
          backgroundColor: successful.map((r) => ALGO_STYLE[r.algorithm]?.bg ?? "rgba(148,163,184,0.7)"),
          borderColor: successful.map((r) => ALGO_STYLE[r.algorithm]?.border ?? "rgba(148,163,184,1)"),
          borderWidth: 1.5,
          borderRadius: 6,
          borderSkipped: false,
        },
      ],
    },
    options: {
      responsive: true,
      maintainAspectRatio: false,
      plugins: {
        legend: { display: false },
        tooltip: {
          backgroundColor: "rgba(15, 17, 24, 0.92)",
          borderColor: "rgba(255,255,255,0.08)",
          borderWidth: 1,
          titleColor: "rgba(255,255,255,0.85)",
          bodyColor: "rgba(255,255,255,0.55)",
          padding: 10,
          callbacks: {
            label: (ctx) => ` ${Number(ctx.parsed.y).toFixed(3)} ${props.unit}`,
          },
        },
      },
      scales: {
        x: {
          grid: { color: "rgba(255,255,255,0.04)" },
          border: { color: "rgba(255,255,255,0.06)" },
          ticks: { color: "rgba(255,255,255,0.45)", font: { size: 12 } },
        },
        y: {
          grid: { color: "rgba(255,255,255,0.04)" },
          border: { color: "rgba(255,255,255,0.06)" },
          ticks: {
            color: "rgba(255,255,255,0.45)",
            font: { size: 11 },
            callback: (v) => `${Number(v).toFixed(2)}`,
          },
          beginAtZero: true,
        },
      },
    },
  });
}

onMounted(buildChart);
watch(() => props.results, buildChart, { deep: true });
onBeforeUnmount(() => chart?.destroy());
</script>

<template>
  <div class="relative h-44">
    <canvas ref="canvas" />
  </div>
</template>
