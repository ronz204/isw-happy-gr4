<script setup lang="ts">
export interface SelectOption {
  label: string;
  value: number | string;
}

const props = defineProps<{
  options: SelectOption[];
  placeholder?: string;
  disabled?: boolean;
}>();

const model = defineModel<number | string | undefined>();
</script>

<template>
  <USelect v-model="model" :items="props.options" value-key="value" label-key="label" :placeholder="props.placeholder"
    :disabled="props.disabled" class="w-full" />
</template>
