<script setup lang="ts">
import { Route } from "@lucide/vue";
import type { EnrichedEdge } from "../types";
import BlockingEdgeItem from "./BlockingEdgeItem.vue";

defineProps<{
  edges: EnrichedEdge[];
  isFetching: boolean;
  emptyMessage: string;
  pendingEdgeId: number | null;
}>();

const emit = defineEmits<{
  close: [id: number];
  open: [id: number];
}>();
</script>

<template>
  <!-- Loading skeleton -->
  <div v-if="isFetching" class="space-y-2">
    <div
      v-for="i in 6"
      :key="i"
      class="h-14 rounded-xl animate-pulse"
      style="background: var(--ui-bg-elevated)"
    />
  </div>

  <!-- Empty state -->
  <Transition name="fade">
    <div
      v-if="!isFetching && edges.length === 0"
      class="flex flex-col items-center py-16 gap-3"
    >
      <div class="flex items-center justify-center w-12 h-12 rounded-full bg-(--ui-bg-accented)">
        <Route :size="20" class="text-muted-foreground" />
      </div>
      <p class="text-sm font-semibold text-foreground">Sin edges</p>
      <p class="text-xs text-muted-foreground">{{ emptyMessage }}</p>
    </div>
  </Transition>

  <!-- Edge list -->
  <Transition name="fade">
    <div v-if="!isFetching && edges.length > 0" class="space-y-2">
      <BlockingEdgeItem
        v-for="edge in edges"
        :key="edge.id"
        :edge="edge"
        :is-pending="pendingEdgeId === edge.id"
        :any-pending="pendingEdgeId !== null"
        @close="emit('close', $event)"
        @open="emit('open', $event)"
      />
    </div>
  </Transition>
</template>

<style scoped>
.fade-enter-active,
.fade-leave-active {
  transition: opacity 0.15s ease, transform 0.15s ease;
}

.fade-enter-from,
.fade-leave-to {
  opacity: 0;
  transform: translateY(4px);
}
</style>
