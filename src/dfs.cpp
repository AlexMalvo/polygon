#include "../include/dfs.h"
#include <algorithm>

std::vector<Node> dfs(const Graph& graph, Node start, Node goal) {
    // Асимптотика: O(1) для поиска в std::unordered_map
    // Память: временные затраты на std::cerr (незначительно)
    if (graph.find(start) == graph.end() || graph.find(goal) == graph.end()) {
        std::cerr << "Ошибка: стартовый или конечный узел отсутствует в графе" << std::endl;
        return {}; // Асимптотика: O(1)
    }

    // Асимптотика: O(1) на вставку в std::unordered_map
    // Память: O(V), где V — кол-во узлов, так как для каждого узла может быть запись
    std::unordered_map<Node, Node, std::hash<Node>> parent;

    // Асимптотика: O(1) на добавление и удаление из std::stack
    // Память: O(V), (max узлов на одном пути графа)
    std::stack<Node> s;
    s.push(start); // Асимптотика: O(1)
    parent[start] = start; // Асимптотика: O(1)

    // Асимптотика: O(V + E), где V — кол-во узлов, E — кол-во рёбер
    // Память: O(V + E) для хранения графа в памяти
    while (!s.empty()) {
        Node current = s.top(); // Асимптотика: O(1)
        s.pop(); // Асимптотика: O(1)

        // Асимптотика: O(1), так как сравнение узлов — константная операция
        if (current == goal) break;

        // Асимптотика: O(d), где d — степень текущего узла
        for (const auto& [neighbor, weight] : graph.at(current)) { // O(1)
            // Асимптотика: O(1) для std::unordered_map
            if (parent.find(neighbor) == parent.end()) {
                parent[neighbor] = current; // Асимптотика: O(1)
                s.push(neighbor); // Асимптотика: O(1)
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
    // Память: временные затраты на перестановку элементов в path
    std::reverse(path.begin(), path.end());

    return path; // Асимптотика: O(1)
}
