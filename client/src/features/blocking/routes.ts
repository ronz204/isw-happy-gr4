import type { RouteRecordRaw } from "vue-router";
import Blocking from "./containers/Blocking.vue";

export const blockingRoutes: RouteRecordRaw[] = [
  {
    path: "/blocking",
    name: "Blocking",
    component: Blocking
  },
];
