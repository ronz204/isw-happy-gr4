#pragma once

#include <crow.h>
#include <vector>
#include "../../database/models/Node.h"

struct GetLandMarksResponse
{
  std::vector<Node> landmarks;
};

class GetLandMarksSchema
{
public:
  // No request validation needed for GET endpoint without parameters
  // This schema only defines the response structure
};
