#ifndef DFS_H
#define DFS_H

#include "graph.h"
#include <stack>
#include <unordered_map>

std::vector<Node> dfs(const Graph& graph, Node start, Node goal);

#endif // DFS_H
