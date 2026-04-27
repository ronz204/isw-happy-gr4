<script setup lang="ts">
import { ref, computed } from "vue";
import { useQueryClient } from "@tanstack/vue-query";
import type { ApiNode } from "@api/graph.models";
import { useGetNodesByFloor } from "@providers/useGetNodesByFloor";
import { usePatchCloseEdge, usePatchOpenEdge } from "@providers/usePatchEdgeStatus";
import type { EnrichedEdge } from "../types";
import BlockingHeader from "../components/BlockingHeader.vue";
import BlockingToolbar from "../components/BlockingToolbar.vue";
import BlockingEdgeList from "../components/BlockingEdgeList.vue";

const HIDDEN_TYPES = new Set(["Stairs", "Elevator", "Vertical"]);

const queryClient = useQueryClient();
const floorId = ref<number>(4);
const showOnlyClosed = ref(false);
const searchQuery = ref("");
const pendingEdgeId = ref<number | null>(null);

const { data, isFetching } = useGetNodesByFloor(floorId);
const closeEdgeMutation = usePatchCloseEdge();
const openEdgeMutation = usePatchOpenEdge();

const enrichedEdges = computed<EnrichedEdge[]>(() => {
  const nodeMap = new Map<number, ApiNode>(
    (data.value?.nodes ?? []).map((n) => [n.id, n])
  );

  const query = searchQuery.value.trim().toUpperCase();

  return (data.value?.edges ?? [])
    .filter((e) => !HIDDEN_TYPES.has(e.type))
    .filter((e) => !showOnlyClosed.value || e.status === "Closed")
    .map((e) => ({
      ...e,
      fromCode: nodeMap.get(e.fromNodeId)?.code ?? String(e.fromNodeId),
      toCode: nodeMap.get(e.toNodeId)?.code ?? String(e.toNodeId),
    }))
    .filter((e) =>
      !query || e.fromCode.toUpperCase().includes(query) || e.toCode.toUpperCase().includes(query)
    );
});

const closedCount = computed(() =>
  (data.value?.edges ?? []).filter((e) => e.status === "Closed" && !HIDDEN_TYPES.has(e.type)).length
);

const emptyMessage = computed(() => {
  if (searchQuery.value.trim()) return `No hay edges que coincidan con "${searchQuery.value}".`;
  if (showOnlyClosed.value) return "No hay edges bloqueadas en este piso.";
  return "Este piso no tiene edges registradas.";
});

function onClose(edgeId: number) {
  pendingEdgeId.value = edgeId;
  closeEdgeMutation.mutate(edgeId, {
    onSuccess: () => {
      pendingEdgeId.value = null;
      queryClient.invalidateQueries({ queryKey: ["floor", floorId.value] });
    },
    onError: () => { pendingEdgeId.value = null; },
  });
}

function onOpen(edgeId: number) {
  pendingEdgeId.value = edgeId;
  openEdgeMutation.mutate(edgeId, {
    onSuccess: () => {
      pendingEdgeId.value = null;
      queryClient.invalidateQueries({ queryKey: ["floor", floorId.value] });
    },
    onError: () => { pendingEdgeId.value = null; },
  });
}
</script>

<template>
  <div class="w-full h-full overflow-auto" style="background: var(--ui-bg)">
    <div class="max-w-2xl mx-auto px-6 py-10">
      <BlockingHeader :closed-count="closedCount" />
      <BlockingToolbar
        v-model:floor-id="floorId"
        v-model:show-only-closed="showOnlyClosed"
        v-model:search-query="searchQuery"
      />
      <BlockingEdgeList
        :edges="enrichedEdges"
        :is-fetching="isFetching"
        :empty-message="emptyMessage"
        :pending-edge-id="pendingEdgeId"
        @close="onClose"
        @open="onOpen"
      />
    </div>
  </div>
</template>
