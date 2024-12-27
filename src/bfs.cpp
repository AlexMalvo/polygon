#include "../include/bfs.h"
#include <algorithm>

std::vector<Node> bfs(const Graph& graph, Node start, Node goal) {
    // Асимптотика: O(1) для поиска в std::unordered_map
    // Память: временные затраты на хранение результата std::cerr (незначительно)
    if (graph.find(start) == graph.end() || graph.find(goal) == graph.end()) {
        std::cerr << "Ошибка: стартовый или конечный узел отсутствует в графе" << std::endl;
        return {}; // Асимптотика: O(1)
    }

    // Асимптотика: O(1) на вставку в std::unordered_map
    // Память: O(V), где V — количество узлов
    std::unordered_map<Node, Node, std::hash<Node>> parent;

    // Асимптотика: O(1) на добавление и удаление из std::queue
    // Память: O(V), (max узлов на одном уровне графа)
    std::queue<Node> q;
    q.push(start); // Асимптотика: O(1)
    parent[start] = start; // Асимптотика: O(1)

    // Асимптотика: O(V + E), где V — кол-во узлов, E — кол-во рёбер
    // Память: O(V + E)
    while (!q.empty()) {
        Node current = q.front(); // Асимптотика: O(1)
        q.pop(); // Асимптотика: O(1)

        // Асимптотика: O(1), так как сравнение узлов — константная операция
        if (current == goal) break;

        // Обход соседей текущего узла
        // Асимптотика: O(d), где d — степень текущего узла
        for (const auto& [neighbor, weight] : graph.at(current)) { // O(1)
            // Асимптотика: O(1) для std::unordered_map
            if (parent.find(neighbor) == parent.end()) {
                parent[neighbor] = current; // Асимптотика: O(1)
                q.push(neighbor); // Асимптотика: O(1)
            }
        }
    }

    // Асимптотика: O(L), где L — длина пути
    // Память: O(L) для хранения вектора path
    std::vector<Node> path;
    if (parent.find(goal) == parent.end()) return {}; // Асимптотика: O(1)

    for (Node at = goal; at != start; at = parent[at]) { // O(L)
        path.push_back(at); // Асимптотика: O(1) (амортизировано)
    }
    path.push_back(start); // Асимптотика: O(1)

    // Асимптотика: O(L), где L — длина пути
    std::reverse(path.begin(), path.end());

    return path; // Асимптотика: O(1)
}
