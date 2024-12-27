#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    static int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects;

        // Объединяем капитал и прибыль в один вектор пар
        for (int i = 0; i < n; ++i) {
            projects.emplace_back(capital[i], profits[i]);
        }

        // Сортируем проекты по требуемому капиталу (по возрастанию)
        sort(projects.begin(), projects.end());

        priority_queue<int> maxProfitHeap; // Использование очереди с приоритетом
        int i = 0;

        // Поиск k проектов
        while (k > 0) {
            // Добавляем все доступные проекты в кучу
            while (i < n && projects[i].first <= w) {
                maxProfitHeap.push(projects[i].second);
                ++i;
            }

            // Если нет доступных проектов, заканчиваем
            if (maxProfitHeap.empty()) {
                break;
            }

            // Выбираем проект с max прибылью
            w += maxProfitHeap.top();
            maxProfitHeap.pop();

            --k;
        }

        return w;
    }
};

void runTests() {
    Solution solution;

    // Test 1
    int k1 = 2, w1 = 0;
    vector<int> profits1 = {1, 2, 3};
    vector<int> capital1 = {0, 1, 1};
    assert(solution.findMaximizedCapital(k1, w1, profits1, capital1) == 4);

    // Test 2
    int k2 = 3, w2 = 0;
    vector<int> profits2 = {1, 2, 3};
    vector<int> capital2 = {0, 1, 2};
    assert(solution.findMaximizedCapital(k2, w2, profits2, capital2) == 6);

    // Test 3
    int k3 = 1, w3 = 0;
    vector<int> profits3 = {1, 2, 3};
    vector<int> capital3 = {0, 1, 2};
    assert(solution.findMaximizedCapital(k3, w3, profits3, capital3) == 1);

    // Test 4
    int k5 = 0, w5 = 10;
    vector<int> profits5 = {5, 5, 5};
    vector<int> capital5 = {0, 0, 0};
    assert(solution.findMaximizedCapital(k5, w5, profits5, capital5) == 10);

    // Test 5
    int k6 = 2, w6 = 0;
    vector<int> profits6 = {5, 5, 5};
    vector<int> capital6 = {10, 10, 10};
    assert(solution.findMaximizedCapital(k6, w6, profits6, capital6) == 0);

    // Test 6
    int k7 = 3, w7 = 10;
    vector<int> profits7 = {5, 15, 25};
    vector<int> capital7 = {1, 2, 3};
    assert(solution.findMaximizedCapital(k7, w7, profits7, capital7) == 55);

    cout << "All test cases passed!" << endl;
}

int main() {
    runTests();
    return 0;
}

// Сложность:
// Сортировка проектов: O(n log n)
// Обработка каждого проекта:
// 1. Добавление проекта в очередь: O(n)
// 2. Операции с очередью удаление / вставка: O(log n) (для каждого проекта)
// Общая: O(n log n + k log n)
