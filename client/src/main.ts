import App from "./App.vue";
import { createApp } from "vue";
import "@assets/styles/main.css";

import { router } from "./router";
import ui from "@nuxt/ui/vue-plugin";
import { createPinia } from "pinia";
import { VueQueryPlugin } from "@tanstack/vue-query";

const app = createApp(App);

app.use(createPinia());
app.use(ui);
app.use(router);
app.use(VueQueryPlugin);
app.mount("#app");
