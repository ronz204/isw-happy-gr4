import type { Point, Bounds, Viewport, Transform } from "@domain/zix";

/**
 * Converts a point from image coordinates to screen coordinates
 */
export function imageToScreen(point: Point, transform: Transform): Point {
  return {
    x: point.x * transform.scale + transform.offsetX,
    y: point.y * transform.scale + transform.offsetY
  };
};

/**
 * Converts a point from screen coordinates to image coordinates
 */
export function screenToImage(point: Point, transform: Transform): Point {
  return {
    x: (point.x - transform.offsetX) / transform.scale,
    y: (point.y - transform.offsetY) / transform.scale
  };
};

/**
 * Builds the CSS transform matrix to apply to the map container
 */
export function getTransformMatrix(transform: Transform): string {
  const { scale, offsetX, offsetY } = transform
  return `matrix(${scale}, 0, 0, ${scale}, ${offsetX}, ${offsetY})`
};

/**
 * Calculates the zoom and offset needed to fit an area within the viewport
 */
export function calculateFitTransform(
  imageBounds: Bounds,
  viewportSize: Viewport,
  padding = 20,
): Transform {
  const imageWidth = imageBounds.max.x - imageBounds.min.x;
  const imageHeight = imageBounds.max.y - imageBounds.min.y;
  
  const availableWidth = viewportSize.width - padding * 2;
  const availableHeight = viewportSize.height - padding * 2;
  
  // Scale that fits the entire area with padding
  const scaleX = availableWidth / imageWidth;
  const scaleY = availableHeight / imageHeight;
  const scale = Math.min(scaleX, scaleY);
  
  // Offset to center the area
  const scaledWidth = imageWidth * scale;
  const scaledHeight = imageHeight * scale;
  
  const offsetX = (viewportSize.width - scaledWidth) / 2 - imageBounds.min.x * scale;
  const offsetY = (viewportSize.height - scaledHeight) / 2 - imageBounds.min.y * scale;
  
  return { scale, offsetX, offsetY };
};

export const Projection = Object.freeze({
  imageToScreen,
  screenToImage,
  getTransformMatrix,
  calculateFitTransform
});
