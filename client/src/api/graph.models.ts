export interface ApiNode {
  id: number;
  type: string;
  floor: number;
  px: number;
  py: number;
  code: string;
  label: string;
  isLandmark: boolean;
}

export interface ApiEdge {
  id: number;
  type: string;
  floor: number;
  status: string;
  weight: number;
  fromNodeId: number;
  toNodeId: number;
}

export interface FloorGraphResponse {
  nodes: ApiNode[];
  edges: ApiEdge[];
}

export interface LandmarksResponse {
  landmarks: ApiNode[];
}
