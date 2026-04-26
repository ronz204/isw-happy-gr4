import type { RouteRecordRaw } from "vue-router";
import Laboratory from "./containers/Laboratory.vue";

export const laboratoryRoutes: RouteRecordRaw[] = [
  {
    path: "/laboratory",
    name: "Laboratory",
    component: Laboratory,
  },
];
