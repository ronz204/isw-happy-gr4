<script setup lang="ts">
import { ref } from "vue";
import type { Marker } from "@domain/zix";

const props = defineProps<{
  marker: Marker<unknown>;
}>();

const copied = ref(false);

function copyCode() {
  navigator.clipboard.writeText(props.marker.code);
  copied.value = true;
  setTimeout(() => { copied.value = false; }, 1500);
}
</script>

<template>
  <div
    class="absolute -translate-x-1/2 -translate-y-1/2 flex flex-col items-center gap-0.5 pointer-events-auto cursor-pointer group"
    :style="{ left: `${props.marker.position.x}px`, top: `${props.marker.position.y}px` }" @click="copyCode">
    <div class="w-3 h-3 rounded-full border-2 border-white shadow-md ring-2 transition-colors" :class="copied
      ? 'bg-green-400 ring-green-400/50'
      : 'bg-blue-500 ring-blue-400/50 group-hover:bg-blue-400'" />
    <span
      class="text-[9px] font-semibold text-white px-1 rounded leading-tight whitespace-nowrap opacity-0 group-hover:opacity-100 transition-opacity"
      :class="copied ? 'bg-green-600/80' : 'bg-black/70'">
      {{ copied ? 'copiado!' : props.marker.label }}
    </span>
  </div>
</template>
