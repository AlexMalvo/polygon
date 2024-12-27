#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include "../include/graph.h"
#include "../include/dfs.h"
#include "../include/bfs.h"
#include "../include/dijkstra.h"

std::string formatPath(const std::vector<Node>& path) {
    if (path.empty()) return "Путь не найден.";
    std::string result;
    for (size_t i = 0; i < path.size(); ++i) {
        result += "(" + std::to_string(path[i].first) + ", " + std::to_string(path[i].second) + ")";
        if (i != path.size() - 1) result += " -> ";
    }
    return result;
}

void printAlgorithmResult(const std::string& algorithmName, double time, const std::vector<Node>& path) {
    std::cout << "Результат работы " << algorithmName << ":\n";
    std::cout << "Время: " << time << " секунд\n";
    std::cout << "Количество узлов: " << path.size() << "\n";
    std::cout << "Путь: " << formatPath(path) << "\n\n";
}

int main() {
    try {
        Graph graph = parseGraph("/home/alexander/CLionProjects/Lab8/data/spb_graph.txt");

        // Определение стартового и конечного узла
        Node start = {30.4140936, 59.9469059};
        Node goal = {30.4208036, 59.9464581};

        // BFS
        auto startBfs = std::chrono::high_resolution_clock::now();
        auto pathBfs = bfs(graph, start, goal);
        auto endBfs = std::chrono::high_resolution_clock::now();
        double timeBfs = std::chrono::duration<double>(endBfs - startBfs).count();
        printAlgorithmResult("BFS", timeBfs, pathBfs);

        // DFS
        auto startDfs = std::chrono::high_resolution_clock::now();
        auto pathDfs = dfs(graph, start, goal);
        auto endDfs = std::chrono::high_resolution_clock::now();
        double timeDfs = std::chrono::duration<double>(endDfs - startDfs).count();
        printAlgorithmResult("DFS", timeDfs, pathDfs);

        // Dijkstra
        auto startDijkstra = std::chrono::high_resolution_clock::now();
        auto pathDijkstra = dijkstra(graph, start, goal);
        auto endDijkstra = std::chrono::high_resolution_clock::now();
        double timeDijkstra = std::chrono::duration<double>(endDijkstra - startDijkstra).count();
        printAlgorithmResult("Dijkstra", timeDijkstra, pathDijkstra);

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
