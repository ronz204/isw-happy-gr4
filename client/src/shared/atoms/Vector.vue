<script setup lang="ts">
import type { Vector } from "@domain/zix";

const props = defineProps<{
  vector: Vector;
}>();
</script>

<template>
  <line
    :x1="props.vector.from.x"
    :y1="props.vector.from.y"
    :x2="props.vector.to.x"
    :y2="props.vector.to.y"
    :stroke="props.vector.color ?? '#60a5fa'"
    :stroke-width="props.vector.width ?? 2"
    stroke-linecap="round"
  />
</template>
