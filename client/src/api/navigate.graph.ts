export interface RouteRequest {
  startNodeId: number;
  endNodeId: number;
  profile: "Regular" | "NewStudent" | "Wheelchair";
  strategy: "BFS" | "DFS" | "Dijkstra";
}

export interface RoutePathNode {
  code: string;
  px: number;
  py: number;
  type: string;
  floor: number;
}

export interface RouteResponse {
  success: boolean;
  algorithm: string;
  distance: number;
  time: number;
  path: RoutePathNode[];
  message?: string;
}
