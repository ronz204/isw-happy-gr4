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
  <img :src="imagePath" class="block pointer-events-none" />
</template>
