import { defineStore } from "pinia";
import { ref } from "vue";
import type { RouteResponse } from "@api/navigate.graph";

export const useRouteStore = defineStore("route", () => {
  const route = ref<RouteResponse | null>(null);

  function setRoute(r: RouteResponse): void {
    route.value = r;
  }

  function clear(): void {
    route.value = null;
  }

  return { route, setRoute, clear };
});
