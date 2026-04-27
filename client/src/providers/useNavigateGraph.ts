import { useMutation } from "@tanstack/vue-query";
import { api } from "@api/http.facade";
import type { RouteRequest, RouteResponse } from "@api/navigate.graph";

export function useNavigateGraph() {
  return useMutation({
    mutationFn: (request: RouteRequest) =>
      api.post<RouteResponse>("/api/graph/route", { body: request }),
  });
}
