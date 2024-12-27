#include <iostream>
#include "../include/graph.h"
#include "../include/dijkstra.h"

void testDijkstraPathExists() {
    Graph graph = {
            {{1, 1}, {{{2, 2}, 1}, {{3, 3}, 2}}},
            {{2, 2}, {{{3, 3}, 1}}},
            {{3, 3}, {}}
    };
    Node start = {1, 1};
    Node goal = {3, 3};

    auto path = dijkstra(graph, start, goal);
    if (!path.empty() && path.front() == start && path.back() == goal) {
        std::cout << "Dijkstra Test 1 Passed: Path exists." << std::endl;
    } else {
        std::cerr << "Dijkstra Test 1 Failed: Path does not exist." << std::endl;
    }
}

void testDijkstraNoPath() {
    Graph graph = {
            {{1, 1}, {{{2, 2}, 1}}},
            {{2, 2}, {}}
    };
    Node start = {1, 1};
    Node goal = {3, 3};

    auto path = dijkstra(graph, start, goal);
    if (path.empty()) {
        std::cout << "Dijkstra Test 2 Passed: No path exists." << std::endl;
    } else {
        std::cerr << "Dijkstra Test 2 Failed: Path unexpectedly exists." << std::endl;
    }
}

void testDijkstraEmptyGraph() {
    Graph graph;
    Node start = {1, 1};
    Node goal = {2, 2};

    auto path = dijkstra(graph, start, goal);
    if (path.empty()) {
        std::cout << "Dijkstra Test 3 Passed: Empty graph has no paths." << std::endl;
    } else {
        std::cerr << "Dijkstra Test 3 Failed: Unexpected path in empty graph." << std::endl;
    }
}

int main() {
    testDijkstraPathExists();
    testDijkstraNoPath();
    testDijkstraEmptyGraph();
    return 0;
}
