import { defineStore } from "pinia";
import { ref, computed } from "vue";
import type { Floor } from "@domain/zix";

const FLOORS: Floor[] = [
  {
    id: 4,
    label: "P4",
    imagePath: "/src/assets/images/eco-campus-f4.svg",
    bounds: { min: { x: 0, y: 0 }, max: { x: 700, y: 450 } },
  },
  {
    id: 5,
    label: "P5",
    imagePath: "/src/assets/images/eco-campus-f5.svg",
    bounds: { min: { x: 0, y: 0 }, max: { x: 700, y: 450 } },
  },
];

export const useMapStore = defineStore("map", () => {
  const currentFloorId = ref<number>(4);
  const floors = ref<Floor[]>(FLOORS);

  const currentFloor = computed(
    () => floors.value.find((f) => f.id === currentFloorId.value) ?? floors.value[0]
  );

  function setFloor(id: number): void {
    currentFloorId.value = id;
  }

  return {
    floors,
    currentFloorId,
    currentFloor,
    setFloor,
  };
});
