import type { ApiEdge } from "@api/graph.models";

export interface EnrichedEdge extends ApiEdge {
  fromCode: string;
  toCode: string;
}
