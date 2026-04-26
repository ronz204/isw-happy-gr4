import { useMutation } from "@tanstack/vue-query";
import { api } from "@api/http.facade";
import type { PerformanceRequest, PerformanceResponse } from "@api/perform.models";

export function useGetPerformance() {
  return useMutation({
    mutationFn: (body: PerformanceRequest) =>
      api.post<PerformanceResponse>("/api/graph/performance", { body }),
  });
}
