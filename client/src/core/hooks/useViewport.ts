import type { UseViewportReturn } from "@domain/hooks";
import type { MapOptions, Bounds, Point } from "@domain/zix";

import { ref, computed } from "vue";
import { Viewport } from "@logic/viewport";
import { Projection } from "@logic/projection";

/**
 * Main hook for managing the map viewport
 */
export function useViewport(options: MapOptions = {}): UseViewportReturn {
  // Create the viewport instance
  const viewport = new Viewport(options);

  // Reactive state derived from the viewport
  const scale = ref(viewport.getTransform().scale);
  const offsetX = ref(viewport.getTransform().offsetX);
  const offsetY = ref(viewport.getTransform().offsetY);

  // Reactive transform matrix for CSS application
  const transformMatrix = computed(() =>
    Projection.getTransformMatrix({
      scale: scale.value,
      offsetX: offsetX.value,
      offsetY: offsetY.value
    })
  );

  /**
   * Sync refs with the current viewport state
   */
  function syncRefs(): void {
    const transform = viewport.getTransform();
    scale.value = transform.scale;
    offsetX.value = transform.offsetX;
    offsetY.value = transform.offsetY;
  };

  /**
   * Set the zoom level
   */
  function setZoom(zoom: number): void {
    viewport.setZoom(zoom);
    syncRefs();
  };

  /**
   * Apply zoom centered on a specific screen point
   */
  function zoomAt(cursorScreen: Point, newScale: number): void {
    viewport.zoomAt(cursorScreen, newScale);
    syncRefs();
  };

  /**
   * Apply a relative offset (pan)
   */
  function pan(deltaX: number, deltaY: number): void {
    viewport.pan(deltaX, deltaY);
    syncRefs();
  };

  /**
   * Set the absolute offset
   */
  function setOffset(x: number, y: number): void {
    viewport.setOffset(x, y);
    syncRefs();
  };

  /**
   * Fit the viewport to show a specific area
   */
  function fitToBounds(
    bounds: Bounds,
    viewportSize: { width: number; height: number },
    padding = 20
  ): void {
    const transform = Projection.calculateFitTransform(bounds, viewportSize, padding);
    viewport.setTransform(transform);
    syncRefs();
  };

  /**
   * Update the map bounds
   */
  function setBounds(bounds: Bounds | undefined): void {
    viewport.setBounds(bounds);
  };

  return {
    scale,
    offsetX,
    offsetY,
    transformMatrix,

    setZoom,
    zoomAt,
    pan,
    setOffset,
    fitToBounds,
    setBounds,

    viewport
  };
};
