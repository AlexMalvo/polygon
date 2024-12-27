#include "../include/graph.h"

Graph parseGraph(const std::string& filename) {
    // Асимптотика: O(1) для создания пустого объекта
    // Память: O(V + E), где V — кол-во узлов, E — кол-во рёбер
    Graph graph;

    // Асимптотика: O(1)
    // Память: O(1), используется только для работы с файлом
    std::ifstream file(filename);

    // Асимптотика: O(1) для создания строки
    // Память: O(L), где L — max длина строки в файле
    std::string line;

    // Асимптотика: O(N), где N — количество строк в файле
    // Память: O(1) на каждый вызов getline
    while (std::getline(file, line)) {
        // Асимптотика: O(L), где L — длина строки
        size_t colonPos = line.find(':');
        if (colonPos == std::string::npos) {
            std::cerr << "Ошибка формата строки: " << line << std::endl;
            continue;
        }

        // Асимптотика: O(L)
        // Память: O(L), т. к. создаётся новая строка
        std::string parentStr = line.substr(0, colonPos);

        // Асимптотика: O(L)
        // Память: O(L)
        std::string neighborsStr = line.substr(colonPos + 1);

        // Асимптотика: O(L)
        size_t commaPos = parentStr.find(',');
        if (commaPos == std::string::npos) {
            std::cerr << "Ошибка формата родительского узла: " << parentStr << std::endl;
            continue;
        }

        // Асимптотика: O(1) для std::stod
        // Память: O(1) временные затраты для хранения значений
        Node parentNode = {std::stod(parentStr.substr(0, commaPos)), std::stod(parentStr.substr(commaPos + 1))};

        // Асимптотика: O(1)
        // Память: O(L), где L — длина строки neighborsStr
        std::stringstream neighborsStream(neighborsStr);

        // Асимптотика: O(1) для создания строки
        // Память: O(L), где L — длина строки соседа
        std::string neighborStr;

        // Асимптотика: O(E), где E — кол-во соседей (рёбер)
        while (std::getline(neighborsStream, neighborStr, ';')) {
            if (neighborStr.empty()) continue;

            // Асимптотика: O(L) на каждую find
            size_t firstComma = neighborStr.find(',');
            size_t secondComma = neighborStr.find(',', firstComma + 1);
            if (firstComma == std::string::npos || secondComma == std::string::npos) {
                std::cerr << "Ошибка формата дочернего узла: " << neighborStr << std::endl;
                continue;
            }

            // Асимптотика: O(1) для std::stod
            // Память: O(1) временные затраты
            Node neighborNode = {
                    std::stod(neighborStr.substr(0, firstComma)),
                    std::stod(neighborStr.substr(firstComma + 1, secondComma - firstComma - 1))
            };

            // Асимптотика: O(1) для std::stod
            double weight = std::stod(neighborStr.substr(secondComma + 1));

            // Асимптотика: O(1) для добавления в std::unordered_map
            // Память: O(1)
            graph[parentNode].push_back({neighborNode, weight});

            // Асимптотика: O(1) для проверки и добавления
            if (graph.find(neighborNode) == graph.end()) {
                graph[neighborNode] = {}; // Память: O(1)
            }
        }
    }

    return graph;
}
