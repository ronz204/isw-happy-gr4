<script setup lang="ts">
import { storeToRefs } from "pinia";
import { useMapStore } from "@stores/useMapStore";
import { useGetNodesByFloor } from "@providers/useGetNodesByFloor";
import MarkerAtom from "@atoms/Marker.vue";

const { currentFloorId } = storeToRefs(useMapStore());
const { markers } = useGetNodesByFloor(currentFloorId);
</script>

<template>
  <div class="absolute inset-0 pointer-events-none" style="z-index: 3">
    <MarkerAtom v-for="marker in markers" :key="marker.id" :marker="marker" />
  </div>
</template>
