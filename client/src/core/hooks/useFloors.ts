import { ref } from "vue";
import type { Floor } from "@domain/zix";
import type { UseLevelsReturn } from "@domain/hooks";

export function useFloors(
  levels: Floor[],
  initialId?: number
): UseLevelsReturn {
  const initial = levels.find(l => l.id === initialId) ?? levels[0];
  const activeLevel = ref<Floor>(initial);

  function setLevel(id: number): void {
    const found = levels.find(l => l.id === id);
    if (found) activeLevel.value = found;
  };

  return { activeLevel, setLevel };
};
