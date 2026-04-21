#pragma once

#include "SearchStrategy.h"
#include <memory>

class SearchContext
{
private:
  std::unique_ptr<SearchStrategy> strategy;

public:
  SearchContext() = default;

  explicit SearchContext(std::unique_ptr<SearchStrategy> strat)
      : strategy(std::move(strat)) {}

  void setStrategy(std::unique_ptr<SearchStrategy> strat)
  {
    strategy = std::move(strat);
  }

  SearchResponse executeSearch(
      const Graph &graph,
      const Profile &profile,
      int startNodeId,
      int endNodeId) const
  {
    if (!strategy)
    {
      return SearchResponse(); // Empty result if no strategy set
    }
    return strategy->search(graph, profile, startNodeId, endNodeId);
  }
};
