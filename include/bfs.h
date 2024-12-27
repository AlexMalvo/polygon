#ifndef BFS_H
#define BFS_H

#include "graph.h"
#include <queue>
#include <unordered_map>

std::vector<Node> bfs(const Graph& graph, Node start, Node goal);

#endif // BFS_H

