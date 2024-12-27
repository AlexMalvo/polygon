#include <iostream>
#include "../include/graph.h"
#include "../include/bfs.h"

void testBfsPathExists() {
    Graph graph = {
            {{1, 1}, {{{2, 2}, 1}, {{3, 3}, 2}}},
            {{2, 2}, {{{3, 3}, 1}}},
            {{3, 3}, {}}
    };
    Node start = {1, 1};
    Node goal = {3, 3};

    auto path = bfs(graph, start, goal);
    if (!path.empty() && path.front() == start && path.back() == goal) {
        std::cout << "BFS Test 1 Passed: Path exists." << std::endl;
    } else {
        std::cerr << "BFS Test 1 Failed: Path does not exist." << std::endl;
    }
}

void testBfsNoPath() {
    Graph graph = {
            {{1, 1}, {{{2, 2}, 1}}},
            {{2, 2}, {}}
    };
    Node start = {1, 1};
    Node goal = {3, 3};

    auto path = bfs(graph, start, goal);
    if (path.empty()) {
        std::cout << "BFS Test 2 Passed: No path exists." << std::endl;
    } else {
        std::cerr << "BFS Test 2 Failed: Path unexpectedly exists." << std::endl;
    }
}

void testBfsEmptyGraph() {
    Graph graph;
    Node start = {1, 1};
    Node goal = {2, 2};

    auto path = bfs(graph, start, goal);
    if (path.empty()) {
        std::cout << "BFS Test 3 Passed: Empty graph has no paths." << std::endl;
    } else {
        std::cerr << "BFS Test 3 Failed: Unexpected path in empty graph." << std::endl;
    }
}

int main() {
    testBfsPathExists();
    testBfsNoPath();
    testBfsEmptyGraph();
    return 0;
}
