#include "../include/dijkstra.h"
#include <algorithm>
#include <limits>

std::vector<Node> dijkstra(const Graph& graph, Node start, Node goal) {
    // Асимптотика: O(1) для поиска в std::unordered_map
    // Память: временные затраты на std::cerr (незначительно)
    if (graph.find(start) == graph.end() || graph.find(goal) == graph.end()) {
        std::cerr << "Ошибка: стартовый или конечный узел отсутствует в графе" << std::endl;
        return {}; // Асимптотика: O(1)
    }

    // Асимптотика: O(V), где V — количество узлов в графе
    // Память: O(V)
    std::unordered_map<Node, double, std::hash<Node>> dist;

    // Асимптотика: O(V) для инициализации, вставки и поиска
    // Память: O(V)
    std::unordered_map<Node, Node, std::hash<Node>> parent;

    // Очередь с приоритетом для выборки узлов с min расстоянием
    // Асимптотика: O(log V) для вставки и удаления
    // Память: O(V), (максимум узлов в графе)
    std::priority_queue<std::pair<double, Node>, std::vector<std::pair<double, Node>>, std::greater<>> pq;


    // Асимптотика: O(V)
    for (const auto& [node, _] : graph) {
        dist[node] = std::numeric_limits<double>::infinity();
    }

    // Асимптотика: O(1)
    dist[start] = 0;
    pq.push({0, start}); // Добавляем стартовый узел в очередь

    // Основной цикл алгоритма Dijkstra
    // Асимптотика: O((V + E) log V), так как каждое ребро обрабатывается один раз, а операции с очередью занимают log V
    while (!pq.empty()) {
        auto [currentDist, current] = pq.top();
        pq.pop();

        // Асимптотика: O(1)
        if (current == goal) break;

        // Обход всех соседей текущего узла
        // Асимптотика: O(d), где d — степень текущего узла
        for (const auto& [neighbor, weight] : graph.at(current)) { // O(1) для доступа к graph.at()
            double newDist = currentDist + weight; // Вычисляем новое расстояние
            // Асимптотика: O(1) для проверки и вставки в std::unordered_map
            if (newDist < dist[neighbor]) {
                dist[neighbor] = newDist;
                parent[neighbor] = current;
                pq.push({newDist, neighbor});
            }
        }
    }

    // Асимптотика: O(L), где L — длина пути
    // Память: O(L) для хранения вектора path
    std::vector<Node> path;
    if (dist[goal] == std::numeric_limits<double>::infinity()) return {};
    for (Node at = goal; at != start; at = parent[at]) { // O(L)
        path.push_back(at); // Асимптотика: O(1)
    }
    path.push_back(start); // Асимптотика: O(1)

    // Асимптотика: O(L), где L — длина пути
    // Память: временные затраты на перестановку элементов в path
    std::reverse(path.begin(), path.end());

    return path; // Асимптотика: O(1)
}
