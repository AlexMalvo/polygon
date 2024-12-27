#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <vector>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>

using Node = std::pair<double, double>; // (долгота, широта)
using Graph = std::unordered_map<Node, std::vector<std::pair<Node, double>>, std::hash<Node>>;

// Кастомный хэш для std::pair
namespace std {
    template <>
    struct hash<std::pair<double, double>> {
        size_t operator()(const std::pair<double, double>& p) const {
            auto h1 = std::hash<double>{}(p.first);
            auto h2 = std::hash<double>{}(p.second);
            return h1 ^ (h2 << 1); // Комбинирование хэшей через XOR и сдвиг
        }
    };
}

// Функция для парсинга графа
Graph parseGraph(const std::string& filename);

#endif // GRAPH_H
