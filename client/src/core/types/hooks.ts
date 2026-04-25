import type { Ref } from "vue";
import type { Bounds, Point, Viewport, Floor } from "./zix";
import { Viewport as LogicViewport } from "@logic/viewport";

export interface UseViewportReturn {
  scale: Ref<number>;
  offsetX: Ref<number>;
  offsetY: Ref<number>;
  transformMatrix: Ref<string>;

  setZoom: (zoom: number) => void;
  zoomAt: (cursorScreen: Point, newScale: number) => void;

  pan: (deltaX: number, deltaY: number) => void;
  setOffset: (x: number, y: number) => void;

  fitToBounds: (bounds: Bounds, viewportSize: Viewport, padding?: number) => void;
  setBounds: (bounds: Bounds | undefined) => void;

  viewport: LogicViewport;
};

export interface UseLevelsReturn {
  activeLevel: Ref<Floor>;
  setLevel: (id: number) => void;
};

export interface UseGesturesOptions {
  wheelSensitivity?: number;
};
