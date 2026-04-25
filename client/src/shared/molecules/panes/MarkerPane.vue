<script setup lang="ts">
import { useMapStore } from "@stores/useMapStore";
import MarkerAtom from "@atoms/Marker.vue";

const store = useMapStore();
</script>

<template>
  <div class="absolute inset-0 pointer-events-none" style="z-index: 3">
    <MarkerAtom v-for="marker in store.currentMarkers" :key="marker.id" :marker="marker" />
  </div>
</template>
