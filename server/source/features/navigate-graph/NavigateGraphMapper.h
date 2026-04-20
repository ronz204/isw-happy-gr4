#pragma once

#include <crow.h>
#include "../../core/response/PathResult.h"
#include "../../database/models/Graph.h"
#include "../../database/enums/NodeType.h"

class NavigateGraphMapper
{
public:
  static crow::json::wvalue toResponse(const PathResult &result, const Graph &graph)
  {
    crow::json::wvalue response;

    response["pathExists"] = result.pathExists;
    response["algorithm"] = result.algorithm;
    response["executionTimeMicros"] = result.executionTimeMicros;
    response["totalDistance"] = result.totalDistance;

    // Map path with full node details
    response["path"] = crow::json::wvalue::list();
    for (size_t i = 0; i < result.path.size(); i++)
    {
      int nodeId = result.path[i];
      const Node *node = graph.getNode(nodeId);

      if (node)
      {
        crow::json::wvalue nodeDetail;
        nodeDetail["id"] = node->id;
        nodeDetail["code"] = node->code;
        nodeDetail["label"] = node->label;
        nodeDetail["type"] = toString(static_cast<NodeType>(node->type));
        nodeDetail["floor"] = node->floor;
        nodeDetail["px"] = node->px;
        nodeDetail["py"] = node->py;
        nodeDetail["isLandmark"] = node->isLandmark;
        nodeDetail["landmarkLvl"] = node->landmarkLvl;

        response["path"][i] = std::move(nodeDetail);
      }
      else
      {
        // Fallback if node not found
        crow::json::wvalue nodeDetail;
        nodeDetail["id"] = nodeId;
        nodeDetail["error"] = "Node not found";
        response["path"][i] = std::move(nodeDetail);
      }
    }

    // Map segment distances
    response["segmentDistances"] = crow::json::wvalue::list();
    for (size_t i = 0; i < result.segmentDistances.size(); i++)
    {
      response["segmentDistances"][i] = result.segmentDistances[i];
    }

    return response;
  }
};
