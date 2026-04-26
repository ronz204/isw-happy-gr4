import { useMutation } from "@tanstack/vue-query";
import { api } from "@api/http.facade";
import type { ApiEdgeDetail } from "@api/edge.models";

export function usePatchCloseEdge() {
  return useMutation({
    mutationFn: (edgeId: number) =>
      api.patch<ApiEdgeDetail>(`/api/edge/${edgeId}/close`),
  });
}

export function usePatchOpenEdge() {
  return useMutation({
    mutationFn: (edgeId: number) =>
      api.patch<ApiEdgeDetail>(`/api/edge/${edgeId}/open`),
  });
}
