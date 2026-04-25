import App from "./App.vue";
import { createApp } from "vue";
import "@assets/styles/main.css";

import { router } from "./router";
import ui from "@nuxt/ui/vue-plugin";

const app = createApp(App);

app.use(ui);
app.use(router);
app.mount("#app");
