import { createWebHistory, createRouter } from "vue-router";
import { visualizerRoutes } from "@features/visualizer/routes";
import { laboratoryRoutes } from "@features/laboratory/routes";

export const router = createRouter({
  history: createWebHistory(),
  routes: [
    ...visualizerRoutes,
    ...laboratoryRoutes,
  ],
});
