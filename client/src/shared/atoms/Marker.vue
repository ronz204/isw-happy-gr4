<script setup lang="ts">
import type { Marker } from "@domain/zix";

const props = defineProps<{
  marker: Marker<unknown>;
}>();
</script>

<template>
  <div
    class="absolute -translate-x-1/2 -translate-y-1/2 flex flex-col items-center gap-0.5 pointer-events-auto cursor-pointer group"
    :style="{ left: `${props.marker.position.x}px`, top: `${props.marker.position.y}px` }"
  >
    <div
      class="w-3 h-3 rounded-full bg-blue-500 border-2 border-white shadow-md ring-2 ring-blue-400/50 group-hover:bg-blue-400 transition-colors"
    />
    <span
      class="text-[9px] font-semibold text-white bg-black/70 px-1 rounded leading-tight whitespace-nowrap opacity-0 group-hover:opacity-100 transition-opacity"
    >
      {{ props.marker.label }}
    </span>
  </div>
</template>
