<script setup lang="ts">
import { Search } from "@lucide/vue";

const FLOORS = [
  { id: 1, label: "P1" },
  { id: 2, label: "P2" },
  { id: 3, label: "P3" },
  { id: 4, label: "P4" },
  { id: 5, label: "P5" },
];

const floorId = defineModel<number>("floorId", { required: true });
const showOnlyClosed = defineModel<boolean>("showOnlyClosed", { required: true });
const searchQuery = defineModel<string>("searchQuery", { required: true });
</script>

<template>
  <div class="flex flex-col gap-3 mb-5">
    <!-- Floor selector + checkbox -->
    <div class="flex items-center justify-between gap-4">
      <div class="flex gap-2">
        <button
          v-for="floor in FLOORS"
          :key="floor.id"
          type="button"
          class="px-4 py-1.5 rounded-lg text-sm font-medium border transition-all"
          :class="floorId === floor.id
            ? 'bg-primary/15 border-primary/40 text-primary-lite'
            : 'bg-(--ui-bg-elevated) border-(--ui-border) text-muted-foreground hover:text-foreground hover:border-accented'"
          @click="floorId = floor.id"
        >
          {{ floor.label }}
        </button>
      </div>

      <label class="flex items-center gap-2 cursor-pointer select-none">
        <UCheckbox v-model="showOnlyClosed" />
        <span class="text-xs text-muted-foreground">Solo bloqueadas</span>
      </label>
    </div>

    <!-- Search bar -->
    <div class="relative">
      <Search
        :size="14"
        class="absolute left-3 top-1/2 -translate-y-1/2 text-muted-foreground pointer-events-none"
      />
      <input
        v-model="searchQuery"
        type="text"
        placeholder="Buscar por código de nodo (ej: WP-F4-09)"
        class="w-full pl-8 pr-3 py-2 rounded-lg text-xs border bg-(--ui-bg-elevated) border-(--ui-border) text-foreground placeholder:text-muted-foreground focus:outline-none focus:border-primary/50 transition-colors"
      />
    </div>
  </div>
</template>
