#pragma once

#include <crow.h>
#include <vector>
#include "../../database/models/Node.h"
#include "../../database/enums/NodeType.h"

class GetLandMarksMapper
{
public:
  static crow::json::wvalue toResponse(const std::vector<Node> &landmarks)
  {
    crow::json::wvalue response;

    // Map landmarks
    response["landmarks"] = crow::json::wvalue::list();
    auto &landmarkList = response["landmarks"];
    
    for (size_t i = 0; i < landmarks.size(); i++)
    {
      const auto &node = landmarks[i];
      landmarkList[i]["id"] = node.id;
      landmarkList[i]["type"] = toString(static_cast<NodeType>(node.type));
      landmarkList[i]["floor"] = node.floor;
      landmarkList[i]["px"] = node.px;
      landmarkList[i]["py"] = node.py;
      landmarkList[i]["code"] = node.code;
      landmarkList[i]["label"] = node.label;
      landmarkList[i]["isLandmark"] = node.isLandmark;
    }

    return response;
  }
};
