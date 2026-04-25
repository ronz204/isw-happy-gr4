import { defineConfig } from "vite";
import vue from "@vitejs/plugin-vue";
import ui from "@nuxt/ui/vite";

// https://vite.dev/config/
export default defineConfig({
  plugins: [vue(), ui()],
  resolve: { alias: {
    "@api": "/src/api",
    "@assets": "/src/assets",
    "@features": "/src/features",
    "@shared": "/src/shared",

    "@logic": "/src/core/logic",
    "@hooks": "/src/core/hooks",
    "@domain": "/src/core/types",

    "@atoms": "/src/shared/atoms",
    "@layouts": "/src/shared/layouts",
    "@molecules": "/src/shared/molecules",
    "@organisms": "/src/shared/organisms",
  }},
});
