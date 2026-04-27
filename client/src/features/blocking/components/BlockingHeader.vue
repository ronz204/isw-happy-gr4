<script setup lang="ts">
import { ShieldBan } from "@lucide/vue";

defineProps<{
  closedCount: number;
}>();
</script>

<template>
  <div class="flex items-start gap-4 mb-8">
    <div class="flex items-center justify-center w-11 h-11 rounded-xl shrink-0 mt-0.5 bg-primary/12 text-primary-lite">
      <ShieldBan :size="20" />
    </div>
    <div class="flex-1 min-w-0">
      <h1 class="text-xl font-bold text-foreground leading-tight">Bloqueo de Edges</h1>
      <p class="text-sm text-muted-foreground mt-1">
        Selecciona un piso para ver y gestionar el estado de sus edges.
      </p>
    </div>
    <Transition name="fade">
      <UBadge v-if="closedCount > 0" color="error" variant="subtle" size="md" class="shrink-0 mt-1">
        {{ closedCount }} bloqueado{{ closedCount !== 1 ? 's' : '' }}
      </UBadge>
    </Transition>
  </div>
</template>

<style scoped>
.fade-enter-active,
.fade-leave-active {
  transition: opacity 0.15s ease, transform 0.15s ease;
}

.fade-enter-from,
.fade-leave-to {
  opacity: 0;
  transform: translateY(4px);
}
</style>
