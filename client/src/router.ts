import { createWebHistory, createRouter } from "vue-router";
import { visualizerRoutes } from "@features/visualizer/routes";

export const router = createRouter({
  history: createWebHistory(),
  routes: [...visualizerRoutes],
});
