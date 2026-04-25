#pragma once

#include "SearchStrategy.h"
#include "algorithms/BFSStrategy.h"
#include "algorithms/DFSStrategy.h"
#include "algorithms/DijkstraStrategy.h"
#include <memory>
#include <string>
#include <stdexcept>

class SearchFactory
{
public:
  // Create a search strategy instance from strategy name
  static std::unique_ptr<SearchStrategy> createStrategy(const std::string &strategyName)
  {
    if (strategyName == "BFS")
    {
      return std::make_unique<BFSStrategy>();
    }
    else if (strategyName == "DFS")
    {
      return std::make_unique<DFSStrategy>();
    }
    else if (strategyName == "Dijkstra")
    {
      return std::make_unique<DijkstraStrategy>();
    }
    else
    {
      throw std::invalid_argument("Invalid strategy name: " + strategyName);
    }
  }

  // Check if a strategy name is valid
  static bool isValidStrategy(const std::string &strategyName)
  {
    return strategyName == "BFS" || strategyName == "DFS" || strategyName == "Dijkstra";
  }
};
