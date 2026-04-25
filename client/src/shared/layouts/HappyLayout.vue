<script setup lang="ts">
import { ref } from "vue";
import Sidebar from "@molecules/Sidebar.vue";

const collapsed = ref(false);
</script>

<template>
  <div class="flex h-screen w-screen overflow-hidden bg-background text-foreground">
    <Sidebar v-model:collapsed="collapsed" />
    <main class="flex-1 overflow-hidden min-w-0">
      <RouterView />
    </main>
  </div>
</template>