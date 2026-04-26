export interface AlgorithmResult {
  algorithm: string;
  success: boolean;
  distance: number;
  time: number;
}

export interface PerformanceResponse {
  results: AlgorithmResult[];
}

export interface PerformanceRequest {
  startNodeId: number;
  endNodeId: number;
  profile: "Regular" | "NewStudent" | "Wheelchair";
}
