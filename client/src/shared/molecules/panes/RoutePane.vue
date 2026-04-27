<script setup lang="ts">
import { computed } from "vue";
import { storeToRefs } from "pinia";
import { useMapStore } from "@stores/useMapStore";
import { useRouteStore } from "@stores/useRouteStore";
import type { RoutePathNode } from "@api/navigate.graph";

const TRANSITION_TYPES = new Set(["StairsUp", "StairsDown", "Elevator"]);

const mapStore = useMapStore();
const routeStore = useRouteStore();
const { currentFloor, currentFloorId } = storeToRefs(mapStore);
const { route } = storeToRefs(routeStore);

const viewBox = computed(() => {
  const b = currentFloor.value.bounds;
  return `${b.min.x} ${b.min.y} ${b.max.x - b.min.x} ${b.max.y - b.min.y}`;
});
const svgWidth = computed(() => currentFloor.value.bounds.max.x - currentFloor.value.bounds.min.x);
const svgHeight = computed(() => currentFloor.value.bounds.max.y - currentFloor.value.bounds.min.y);

interface Segment {
  x1: number; y1: number;
  x2: number; y2: number;
}

// Consecutive pairs where both nodes are on the current floor
const segments = computed<Segment[]>(() => {
  const path = route.value?.path ?? [];
  const floor = currentFloorId.value;
  const result: Segment[] = [];

  for (let i = 0; i < path.length - 1; i++) {
    const a = path[i];
    const b = path[i + 1];
    if (a.floor === floor && b.floor === floor) {
      result.push({ x1: a.px, y1: a.py, x2: b.px, y2: b.py });
    }
  }
  return result;
});

// Nodes on the current floor that are part of the route
const routeNodes = computed<RoutePathNode[]>(() =>
  (route.value?.path ?? []).filter((n) => n.floor === currentFloorId.value)
);

// Nodes that are first/last of the full path (origin/destination)
const startNode = computed(() => route.value?.path[0] ?? null);
const endNode = computed(() => route.value?.path[route.value.path.length - 1] ?? null);

function isStart(n: RoutePathNode) {
  return startNode.value?.code === n.code;
}

function isEnd(n: RoutePathNode) {
  return endNode.value?.code === n.code;
}

function isTransition(n: RoutePathNode) {
  return TRANSITION_TYPES.has(n.type);
}
</script>

<template>
  <svg v-if="route && routeNodes.length > 0" class="absolute top-0 left-0 pointer-events-none overflow-visible"
    :viewBox="viewBox" :width="svgWidth" :height="svgHeight" style="z-index: 4">
    <!-- Path segments -->
    <line v-for="(seg, i) in segments" :key="`seg-${i}`" :x1="seg.x1" :y1="seg.y1" :x2="seg.x2" :y2="seg.y2"
      stroke="#f59e0b" stroke-width="4" stroke-linecap="round" stroke-linejoin="round" opacity="0.9" />

    <!-- Route nodes -->
    <g v-for="node in routeNodes" :key="node.code">
      <!-- Transition node (stairs/elevator) -->
      <template v-if="isTransition(node) && !isStart(node) && !isEnd(node)">
        <circle :cx="node.px" :cy="node.py" r="7" fill="#7c3aed" stroke="white" stroke-width="2" />
        <circle :cx="node.px" :cy="node.py" r="3" fill="white" />
      </template>

      <!-- Start node -->
      <template v-else-if="isStart(node)">
        <circle :cx="node.px" :cy="node.py" r="8" fill="#22c55e" stroke="white" stroke-width="2.5" />
        <circle :cx="node.px" :cy="node.py" r="3.5" fill="white" />
      </template>

      <!-- End node -->
      <template v-else-if="isEnd(node)">
        <circle :cx="node.px" :cy="node.py" r="8" fill="#ef4444" stroke="white" stroke-width="2.5" />
        <circle :cx="node.px" :cy="node.py" r="3.5" fill="white" />
      </template>

      <!-- Intermediate waypoint -->
      <template v-else>
        <circle :cx="node.px" :cy="node.py" r="4" fill="#f59e0b" stroke="white" stroke-width="1.5" />
      </template>
    </g>
  </svg>
</template>
