import type { RouteRecordRaw } from "vue-router";
import Visualizer from "./containers/Visualizer.vue";

export const visualizerRoutes: RouteRecordRaw[] = [
  {
    path: "/visualizer",
    name: "Visualizer",
    component: Visualizer
  },
];
