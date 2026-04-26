<script setup lang="ts">
import { ref } from "vue";
import { z } from "zod";
import { ArrowRight, Search } from "@lucide/vue";
import type { FormSubmitEvent } from "@nuxt/ui";

const schema = z.object({
  fromNodeId: z.coerce
    .number()
    .int("Debe ser un número entero")
    .positive("Debe ser mayor a 0"),
  toNodeId: z.coerce
    .number()
    .int("Debe ser un número entero")
    .positive("Debe ser mayor a 0"),
});

type Schema = z.output<typeof schema>;

const props = defineProps<{
  loading?: boolean;
}>();

const emit = defineEmits<{
  submit: [data: Schema];
}>();

const state = ref<Partial<Schema>>({
  fromNodeId: undefined,
  toNodeId: undefined,
});

function onSubmit(event: FormSubmitEvent<Schema>) {
  emit("submit", event.data);
}
</script>

<template>
  <UForm :schema="schema" :state="state" @submit="onSubmit">
    <div class="flex items-start gap-3 mb-5">
      <UFormField label="Nodo origen" name="fromNodeId" required class="flex-1">
        <UInput
          v-model.number="state.fromNodeId"
          type="number"
          placeholder="ID nodo origen"
          :disabled="props.loading"
          class="w-full"
        />
      </UFormField>

      <div class="flex items-center justify-center shrink-0 mt-6.5 w-7 h-9 text-muted-foreground">
        <ArrowRight :size="16" />
      </div>

      <UFormField label="Nodo destino" name="toNodeId" required class="flex-1">
        <UInput
          v-model.number="state.toNodeId"
          type="number"
          placeholder="ID nodo destino"
          :disabled="props.loading"
          class="w-full"
        />
      </UFormField>
    </div>

    <p class="text-xs text-muted-foreground mb-5">
      La búsqueda es bidireccional — se encontrará el edge sin importar el orden de los nodos.
    </p>

    <div class="flex justify-end">
      <UButton type="submit" :loading="props.loading">
        <Search :size="14" />
        Buscar Edge
      </UButton>
    </div>
  </UForm>
</template>
