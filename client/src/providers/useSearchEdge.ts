import { useMutation } from "@tanstack/vue-query";
import { api } from "@api/http.facade";
import type { ApiEdgeSearchResponse } from "@api/edge.models";

export function useSearchEdge() {
  return useMutation({
    mutationFn: ({ fromNodeId, toNodeId }: { fromNodeId: number; toNodeId: number }) =>
      api.get<ApiEdgeSearchResponse>("/api/edge/search", {
        params: { fromNodeId, toNodeId },
      }),
  });
}
