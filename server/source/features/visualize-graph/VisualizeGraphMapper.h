#pragma once

#include <crow.h>
#include <vector>
#include "../../database/models/Node.h"
#include "../../database/models/Edge.h"
#include "../../database/enums/NodeType.h"
#include "../../database/enums/EdgeStatus.h"
#include "../../database/enums/EdgeType.h"

class VisualizeGraphMapper
{
public:
  static crow::json::wvalue toResponse(const std::vector<Node> &nodes, const std::vector<Edge> &edges)
  {
    crow::json::wvalue response;

    // Map nodes
    response["nodes"] = crow::json::wvalue::list();
    auto &nodeList = response["nodes"];
    for (size_t i = 0; i < nodes.size(); i++)
    {
      const auto &node = nodes[i];
      nodeList[i]["id"] = node.id;
      nodeList[i]["type"] = toString(static_cast<NodeType>(node.type));
      nodeList[i]["floor"] = node.floor;
      nodeList[i]["px"] = node.px;
      nodeList[i]["py"] = node.py;
      nodeList[i]["code"] = node.code;
      nodeList[i]["label"] = node.label;
      nodeList[i]["isLandmark"] = node.isLandmark;
    }

    // Map edges
    response["edges"] = crow::json::wvalue::list();
    auto &edgeList = response["edges"];
    for (size_t i = 0; i < edges.size(); i++)
    {
      const auto &edge = edges[i];
      edgeList[i]["id"] = edge.id;
      edgeList[i]["type"] = toString(static_cast<EdgeType>(edge.type));
      edgeList[i]["status"] = toString(static_cast<EdgeStatus>(edge.status));
      edgeList[i]["weight"] = edge.weight;
      edgeList[i]["fromNodeId"] = edge.fromNodeId;
      edgeList[i]["toNodeId"] = edge.toNodeId;
    }

    return response;
  }
};