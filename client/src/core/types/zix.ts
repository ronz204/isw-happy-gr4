export interface Point {
  x: number;
  y: number;
};

export interface Bounds {
  min: Point;
  max: Point;
};

export interface Floor {
  id: number;
  label: string;
  imagePath: string;
  bounds: Bounds;
};

export interface Viewport {
  width: number;
  height: number;
};

export interface Marker<Data> {
  id: number;
  data: Data;
  label: string;
  floor: number;
  position: Point;
};

export interface MapOptions {
  minZoom?: number;
  maxZoom?: number;

  initialZoom?: number;
  initialCenter?: Point;

  bounds?: Bounds;
  clampToBounds?: boolean;
  wheelSensitivity?: number;
};

export interface Transform {
  scale: number;
  offsetX: number;
  offsetY: number;
};
