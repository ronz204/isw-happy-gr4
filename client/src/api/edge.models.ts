export interface ApiEdgeDetail {
  id: number;
  type: string;
  floor: number;
  status: string;
  weight: number;
  fromNodeId: number;
  toNodeId: number;
}

export interface ApiEdgeSearchResponse {
  found: boolean;
  message: string;
  edge: ApiEdgeDetail | null;
}
