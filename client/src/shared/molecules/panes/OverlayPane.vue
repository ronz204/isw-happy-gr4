<script setup lang="ts">
import type { Bounds } from "@domain/zix";
import type { UseViewportReturn } from "@domain/hooks";

import { inject, watch } from "vue";

const props = defineProps<{
  imagePath: string
  bounds: Bounds
}>()

const viewport = inject<UseViewportReturn>('zixViewport')
watch(() => props.bounds, (b) => { viewport?.setBounds(b) }, { immediate: true })
</script>

<template>
  <img
    :src="imagePath"
    :width="bounds.max.x - bounds.min.x"
    :height="bounds.max.y - bounds.min.y"
    class="block pointer-events-none"
  />
</template>
