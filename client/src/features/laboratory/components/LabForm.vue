<script setup lang="ts">
import { z } from "zod";
import { ref } from "vue";
import { ArrowRight, FlaskConical } from "@lucide/vue";
import type { FormSubmitEvent } from "@nuxt/ui";
import type { PerformanceRequest } from "@api/perform.models";
import { useGetLandmarks } from "@providers/useGetLandmarks";
import SelectAtom from "@atoms/Select.vue";

const { options: landmarkOptions } = useGetLandmarks();

const PROFILES = [
  { label: "Regular", value: "Regular" },
  { label: "Nuevo estudiante", value: "NewStudent" },
  { label: "Silla de ruedas", value: "Wheelchair" },
] as const;

const schema = z.object({
  startNodeId: z.coerce.number().int("Debe ser entero").positive("Debe ser mayor a 0"),
  endNodeId: z.coerce.number().int("Debe ser entero").positive("Debe ser mayor a 0"),
  profile: z.enum(["Regular", "NewStudent", "Wheelchair"]),
});

type Schema = z.output<typeof schema>;

const props = defineProps<{ loading?: boolean }>();

const emit = defineEmits<{ submit: [data: PerformanceRequest] }>();

const state = ref<Partial<Schema>>({
  startNodeId: undefined,
  endNodeId: undefined,
  profile: "Regular",
});

function onSubmit(event: FormSubmitEvent<Schema>) {
  emit("submit", event.data);
}
</script>

<template>
  <UForm :schema="schema" :state="state" @submit="onSubmit">
    <!-- Node inputs -->
    <div class="flex items-start gap-3 mb-4">
      <UFormField label="Nodo origen" name="startNodeId" required class="flex-1">
        <SelectAtom
          v-model="state.startNodeId"
          :options="landmarkOptions"
          placeholder="Selecciona origen"
          :disabled="props.loading"
        />
      </UFormField>

      <div class="flex items-center justify-center shrink-0 mt-6.5 w-7 h-9 text-muted-foreground">
        <ArrowRight :size="16" />
      </div>

      <UFormField label="Nodo destino" name="endNodeId" required class="flex-1">
        <SelectAtom
          v-model="state.endNodeId"
          :options="landmarkOptions"
          placeholder="Selecciona destino"
          :disabled="props.loading"
        />
      </UFormField>
    </div>

    <!-- Profile selector -->
    <UFormField label="Perfil de usuario" name="profile" required class="mb-5">
      <div class="flex gap-2">
        <button v-for="p in PROFILES" :key="p.value" type="button" :disabled="props.loading"
          class="flex-1 px-3 py-2 rounded-lg text-xs font-medium border transition-all"
          :class="state.profile === p.value
            ? 'bg-primary/15 border-primary/40 text-primary-lite'
            : 'bg-(--ui-bg-elevated) border-(--ui-border) text-muted-foreground hover:text-foreground hover:border-accented'" @click="state.profile = p.value">
          {{ p.label }}
        </button>
      </div>
    </UFormField>

    <div class="flex justify-end">
      <UButton type="submit" :loading="props.loading">
        <FlaskConical :size="14" />
        Ejecutar análisis
      </UButton>
    </div>
  </UForm>
</template>
