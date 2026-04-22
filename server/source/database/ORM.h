#pragma once

#include <sqlite_orm/sqlite_orm.h>
#include "./models/Node.h"
#include "./models/Edge.h"

namespace sql = sqlite_orm;

inline auto initStorage(const std::string &path)
{
  return sql::make_storage(
      path,
      sql::make_table(
          "nodes",
          sql::make_column("id", &Node::id, sql::primary_key().autoincrement()),
          sql::make_column("floor", &Node::floor, sql::not_null()),
          sql::make_column("px", &Node::px, sql::not_null()),
          sql::make_column("py", &Node::py, sql::not_null()),
          sql::make_column("code", &Node::code, sql::not_null()),
          sql::make_column("label", &Node::label, sql::not_null()),
          sql::make_column("type", &Node::type, sql::not_null()),
          sql::make_column("isLandmark", &Node::isLandmark, sql::default_value(false))),
      sql::make_table(
          "edges",
          sql::make_column("id", &Edge::id, sql::primary_key().autoincrement()),
          sql::make_column("type", &Edge::type, sql::not_null()),
          sql::make_column("weight", &Edge::weight, sql::not_null()),
          sql::make_column("fromNodeId", &Edge::fromNodeId, sql::not_null()),
          sql::make_column("toNodeId", &Edge::toNodeId, sql::not_null()),
          sql::make_column("status", &Edge::status, sql::not_null()),
          sql::foreign_key(&Edge::fromNodeId).references(&Node::id),
          sql::foreign_key(&Edge::toNodeId).references(&Node::id)));
}

using Storage = decltype(initStorage(""));
