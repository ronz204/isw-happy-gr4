<script setup lang="ts">
import { useMapStore } from "@stores/useMapStore";
import Zix6Map from "@molecules/Zix6Map.vue";
import OverlayPane from "@molecules/panes/OverlayPane.vue";
import VectorPane from "@molecules/panes/VectorPane.vue";
import MarkerPane from "@molecules/panes/MarkerPane.vue";
import FloorDriver from "@molecules/drivers/FloorDriver.vue";
import ZoomDriver from "@molecules/drivers/ZoomDriver.vue";
import { storeToRefs } from "pinia";

const store = useMapStore();
const { floors, currentFloor } = storeToRefs(store);
</script>

<template>
  <div class="w-full h-full">
    <Zix6Map :bounds="currentFloor.bounds">
      <template #layers>
        <OverlayPane :imagePath="currentFloor.imagePath" :bounds="currentFloor.bounds" />
        <VectorPane />
        <MarkerPane />
      </template>
      <template #controls>
        <FloorDriver :levels="floors" :initial-active="currentFloor.id" @update:active="store.setFloor" />
        <ZoomDriver position="bottom-right" />
      </template>
    </Zix6Map>
  </div>
</template>