import { useQuery } from "@tanstack/vue-query";
import { computed } from "vue";
import { api } from "@api/http.facade";
import type { LandmarksResponse } from "@api/graph.models";

export interface LandmarkOption {
  label: string;
  value: number;
}

export function useGetLandmarks() {
  const query = useQuery({
    queryKey: ["landmarks"],
    queryFn: () => api.get<LandmarksResponse>("/api/graph/landmarks"),
  });

  const options = computed<LandmarkOption[]>(() =>
    (query.data.value?.landmarks ?? []).map((node) => ({
      label: node.label || node.code,
      value: node.id,
    }))
  );

  return { ...query, options };
}
