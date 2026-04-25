import { defineStore } from "pinia";
import { ref, computed } from "vue";
import type { Floor, Marker, Vector } from "@domain/zix";

const FAKE_FLOORS: Floor[] = [
  {
    id: 4,
    label: "P4",
    imagePath: "/src/assets/images/eco-campus-f4.svg",
    bounds: { min: { x: 0, y: 0 }, max: { x: 1200, y: 800 } },
  },
  {
    id: 5,
    label: "P5",
    imagePath: "/src/assets/images/eco-campus-f5.svg",
    bounds: { min: { x: 0, y: 0 }, max: { x: 1200, y: 800 } },
  },
];

const FAKE_MARKERS: Marker<null>[] = [
  { id: 1, data: null, label: "A101", floor: 4, position: { x: 200, y: 150 } },
  { id: 2, data: null, label: "A102", floor: 4, position: { x: 520, y: 280 } },
  { id: 3, data: null, label: "A103", floor: 4, position: { x: 850, y: 500 } },
  { id: 4, data: null, label: "B101", floor: 4, position: { x: 400, y: 620 } },
  { id: 5, data: null, label: "C201", floor: 5, position: { x: 300, y: 200 } },
  { id: 6, data: null, label: "C202", floor: 5, position: { x: 700, y: 380 } },
  { id: 7, data: null, label: "C203", floor: 5, position: { x: 950, y: 600 } },
];

const FAKE_VECTORS: Vector[] = [
  { id: 1, floor: 4, from: { x: 200, y: 150 }, to: { x: 520, y: 280 } },
  { id: 2, floor: 4, from: { x: 520, y: 280 }, to: { x: 850, y: 500 } },
  { id: 3, floor: 4, from: { x: 850, y: 500 }, to: { x: 400, y: 620 } },
  { id: 4, floor: 5, from: { x: 300, y: 200 }, to: { x: 700, y: 380 } },
  { id: 5, floor: 5, from: { x: 700, y: 380 }, to: { x: 950, y: 600 } },
];

export const useMapStore = defineStore("map", () => {
  const currentFloorId = ref<number>(4);

  const floors = ref<Floor[]>(FAKE_FLOORS);
  const markers = ref<Marker<null>[]>(FAKE_MARKERS);
  const vectors = ref<Vector[]>(FAKE_VECTORS);

  const currentFloor = computed(
    () => floors.value.find((f) => f.id === currentFloorId.value) ?? floors.value[0]
  );

  const currentMarkers = computed(() =>
    markers.value.filter((m) => m.floor === currentFloorId.value)
  );

  const currentVectors = computed(() =>
    vectors.value.filter((v) => v.floor === currentFloorId.value)
  );

  function setFloor(id: number): void {
    currentFloorId.value = id;
  }

  return {
    floors,
    markers,
    vectors,
    currentFloorId,
    currentFloor,
    currentMarkers,
    currentVectors,
    setFloor,
  };
});
