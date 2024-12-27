#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"
#include <queue>
#include <unordered_map>
#include <limits>

std::vector<Node> dijkstra(const Graph& graph, Node start, Node goal);

#endif // DIJKSTRA_H
