<script setup lang="ts">
import { Building2, MapPin, FlaskConical, PanelLeftClose, PanelLeftOpen } from "@lucide/vue";
import { useRoute } from "vue-router";

const props = defineProps<{
  collapsed: boolean;
}>();

const emit = defineEmits<{
  "update:collapsed": [value: boolean];
}>();

const route = useRoute();

const navItems = [
  { name: "Visualizer", path: "/visualizer", icon: MapPin, label: "Visualizador" },
  { name: "Laboratory", path: "/laboratory", icon: FlaskConical, label: "Laboratorio" },
];

function isActive(path: string) {
  return route.path.startsWith(path);
}

function toggle() {
  emit("update:collapsed", !props.collapsed);
}
</script>

<template>
  <nav
    class="relative flex flex-col h-full border-r border-sidebar-border shrink-0 transition-[width] duration-300 ease-in-out overflow-hidden"
    :class="collapsed ? 'w-16' : 'w-60'" :style="{ background: 'var(--sidebar-bg)' }">
    <!-- Brand header -->
    <div class="flex items-center gap-3 px-4 h-16 border-b border-sidebar-border shrink-0">
      <div class="flex items-center justify-center shrink-0 w-8 h-8 rounded-lg"
        style="background: oklch(0.60 0.22 250 / 0.18); color: oklch(0.70 0.20 250);">
        <Building2 :size="17" />
      </div>
      <Transition name="label-fade">
        <div v-if="!collapsed" class="overflow-hidden">
          <p class="text-sm font-semibold text-foreground leading-none whitespace-nowrap">Happy GR4</p>
          <p class="text-xs text-muted-foreground mt-0.5 whitespace-nowrap">Campus Navigation</p>
        </div>
      </Transition>
    </div>

    <!-- Navigation items -->
    <div class="flex-1 flex flex-col gap-0.5 p-2 pt-3">
      <RouterLink v-for="item in navItems" :key="item.name" :to="item.path"
        class="relative flex items-center gap-3 px-3 py-2.5 rounded-lg text-sm font-medium transition-all duration-150 group"
        :class="isActive(item.path)
          ? 'text-[oklch(0.72_0.20_250)] bg-[oklch(0.60_0.22_250/0.12)] ring-1 ring-[oklch(0.60_0.22_250/0.25)]'
          : 'text-muted-foreground hover:text-foreground hover:bg-(--ui-bg-accented)'">
        <!-- Active left pill -->
        <span v-if="isActive(item.path)" class="absolute left-0 top-1/2 -translate-y-1/2 w-0.75 h-5 rounded-full"
          style="background: oklch(0.65 0.22 250);" />

        <component :is="item.icon" :size="17" class="shrink-0" />

        <Transition name="label-fade">
          <span v-if="!collapsed" class="whitespace-nowrap overflow-hidden text-ellipsis">
            {{ item.label }}
          </span>
        </Transition>
      </RouterLink>
    </div>

    <!-- Divider + collapse toggle -->
    <div class="p-2 border-t border-sidebar-border shrink-0">
      <button @click="toggle"
        class="flex items-center justify-center w-full h-9 rounded-lg text-muted-foreground hover:text-foreground hover:bg-(--ui-bg-accented) transition-all duration-150 gap-2">
        <PanelLeftClose v-if="!collapsed" :size="15" />
        <PanelLeftOpen v-else :size="15" />
        <Transition name="label-fade">
          <span v-if="!collapsed" class="text-xs font-medium whitespace-nowrap overflow-hidden">Colapsar</span>
        </Transition>
      </button>
    </div>
  </nav>
</template>

<style scoped>
.label-fade-enter-active {
  transition: opacity 0.18s ease 0.1s, transform 0.18s ease 0.1s;
}

.label-fade-leave-active {
  transition: opacity 0.10s ease, transform 0.10s ease;
}

.label-fade-enter-from,
.label-fade-leave-to {
  opacity: 0;
  transform: translateX(-6px);
}
</style>