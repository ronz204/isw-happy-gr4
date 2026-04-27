<script setup lang="ts">
import { ArrowRight, ShieldBan, ShieldCheck } from "@lucide/vue";
import type { EnrichedEdge } from "../types";

const props = defineProps<{
  edge: EnrichedEdge;
  isPending: boolean;
  anyPending: boolean;
}>();

const emit = defineEmits<{
  close: [id: number];
  open: [id: number];
}>();
</script>

<template>
  <div
    class="flex items-center gap-3 px-4 py-3 rounded-xl transition-colors"
    style="background: var(--ui-bg-elevated); border: 1px solid var(--ui-border)"
  >
    <!-- Route label -->
    <div class="flex items-center gap-1.5 flex-1 min-w-0 font-mono text-xs">
      <span class="text-foreground font-semibold truncate">{{ edge.fromCode }}</span>
      <ArrowRight :size="12" class="text-muted-foreground shrink-0" />
      <span class="text-foreground font-semibold truncate">{{ edge.toCode }}</span>
    </div>

    <!-- Status dot -->
    <div class="flex items-center gap-1.5 shrink-0">
      <div
        class="w-1.5 h-1.5 rounded-full shrink-0"
        :class="edge.status === 'Open' ? 'bg-green-400' : 'bg-red-400'"
      />
      <span class="text-xs text-muted-foreground w-16">
        {{ edge.status === 'Open' ? 'Abierto' : 'Bloqueado' }}
      </span>
    </div>

    <!-- Action button -->
    <UButton
      v-if="edge.status === 'Open'"
      color="error"
      variant="ghost"
      size="xs"
      :loading="isPending"
      :disabled="anyPending"
      @click="emit('close', edge.id)"
    >
      <ShieldBan :size="13" />
      Bloquear
    </UButton>
    <UButton
      v-else
      color="success"
      variant="ghost"
      size="xs"
      :loading="isPending"
      :disabled="anyPending"
      @click="emit('open', edge.id)"
    >
      <ShieldCheck :size="13" />
      Abrir
    </UButton>
  </div>
</template>
