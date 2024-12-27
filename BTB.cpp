#include <vector>    // O(1)
#include <algorithm> // O(1)
#include <iostream>  // O(1)
#include <cassert>   // O(1)
using namespace std;

class Solution {
public:
    static int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        // Проверка на пустой вектор: O(1), память O(1)

        int n = prices.size();
        // Получение размера вектора: O(1), память O(1)

        vector<vector<int>> dp(3, vector<int>(n, 0));
        // Создание DP-таблицы размером 3 x n: O(3 * n) времени и памяти

        for (int k = 1; k <= 2; ++k) {
            // Два прохода по количеству транзакций: O(2), память O(1)

            int maxDiff = -prices[0];
            // Инициализация максимальной разницы: O(1), память O(1)

            for (int i = 1; i < n; ++i) {
                // Один проход по ценам: O(n) на каждую транзакцию, итого O(2 * n)

                dp[k][i] = max(dp[k][i - 1], prices[i] + maxDiff);
                // Обновление DP для текущего дня: O(1), память O(1)

                maxDiff = max(maxDiff, dp[k - 1][i] - prices[i]);
                // Пересчет максимальной разницы: O(1), память O(1)
            }
        }

        return dp[2][n - 1];
        // Возврат результата из DP-таблицы: O(1), память O(1)
    }
};


void runTests() {
    Solution solution;

    // Тест 1
    vector<int> prices1 = {3, 3, 5, 0, 0, 3, 1, 4};
    assert(solution.maxProfit(prices1) == 6);

    // Тест 2
    vector<int> prices2 = {1, 2, 3, 4, 5};
    assert(solution.maxProfit(prices2) == 4);

    // Тест 3
    vector<int> prices3 = {7, 6, 4, 3, 1};
    assert(solution.maxProfit(prices3) == 0);

    // Тест 4
    vector<int> prices4 = {1, 2, 4, 2, 5, 7, 2, 4, 9, 0};
    assert(solution.maxProfit(prices4) == 13);

    // Тест 5
    vector<int> prices5 = {1};
    assert(solution.maxProfit(prices5) == 0);

    // Тест 6
    vector<int> prices6 = {};
    assert(solution.maxProfit(prices6) == 0);

    cout << "All tests passed successfully!" << endl;
}

int main() {
    runTests();
    return 0;
}
