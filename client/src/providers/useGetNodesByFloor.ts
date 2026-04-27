import { useQuery } from "@tanstack/vue-query";
import { computed, type Ref } from "vue";
import { api } from "@api/http.facade";
import type { Marker, Vector } from "@domain/zix";
import type { ApiNode, FloorGraphResponse } from "@api/graph.models";

export function useGetNodesByFloor(floorId: Ref<number>) {
  const query = useQuery({
    queryKey: computed(() => ["floor", floorId.value]),
    queryFn: () => api.get<FloorGraphResponse>(`/api/graph/floor/${floorId.value}`),
  });

  const markers = computed<Marker<ApiNode>[]>(() =>
    (query.data.value?.nodes ?? []).map((node) => ({
      id: node.id,
      data: node,
      label: node.label || node.code,
      code: node.code,
      floor: node.floor,
      position: { x: node.px, y: node.py },
    }))
  );

  const vectors = computed<Vector[]>(() => {
    const nodeMap = new Map(
      (query.data.value?.nodes ?? []).map((n) => [n.id, n])
    );

    const HIDDEN_TYPES = new Set(["Stairs", "Elevator"]);

    return (query.data.value?.edges ?? [])
      .filter((e) => !HIDDEN_TYPES.has(e.type))
      .reduce<Vector[]>((acc, edge) => {
        const from = nodeMap.get(edge.fromNodeId);
        const to = nodeMap.get(edge.toNodeId);
        if (from && to) {
          acc.push({
            id: edge.id,
            floor: edge.floor,
            from: { x: from.px, y: from.py },
            to: { x: to.px, y: to.py },
            color: edge.status === "Closed" ? "#ef4444" : undefined,
          });
        }
        return acc;
      }, []);
  });

  return { ...query, markers, vectors };
}
