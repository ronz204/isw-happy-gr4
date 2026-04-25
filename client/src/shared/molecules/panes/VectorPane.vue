<script setup lang="ts">
import { computed } from "vue";
import { useMapStore } from "@stores/useMapStore";
import VectorAtom from "@atoms/Vector.vue";

const store = useMapStore();

const viewBox = computed(() => {
  const b = store.currentFloor.bounds;
  return `${b.min.x} ${b.min.y} ${b.max.x - b.min.x} ${b.max.y - b.min.y}`;
});

const svgWidth = computed(() => {
  const b = store.currentFloor.bounds;
  return b.max.x - b.min.x;
});

const svgHeight = computed(() => {
  const b = store.currentFloor.bounds;
  return b.max.y - b.min.y;
});
</script>

<template>
  <svg class="absolute top-0 left-0 pointer-events-none overflow-visible" :viewBox="viewBox" :width="svgWidth"
    :height="svgHeight" style="z-index: 2">
    <VectorAtom v-for="vector in store.currentVectors" :key="vector.id" :vector="vector" />
  </svg>
</template>
