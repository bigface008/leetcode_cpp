//
// https://leetcode.com/problems/ipo/description/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap; // capital, profit
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> max_heap; // profit, capital

    for (int i = 0; i < capital.size(); i++) {
        if (w >= capital[i]) {
            max_heap.push({profits[i], capital[i]});
        } else {
            min_heap.push({capital[i], profits[i]});
        }
    }
    int ans = w;
    while (!max_heap.empty() && k) {
        ans += max_heap.top().first;
        k--;
        max_heap.pop();
        while (!min_heap.empty() && min_heap.top().first <= ans) {
            max_heap.push({min_heap.top().second, min_heap.top().first});
            min_heap.pop();
        }
    }
    return ans;
}

int main() {
    auto f = [](int k, int w, vector<int> &&profits, vector<int> &&capital, int expect) {
        auto output = findMaximizedCapital(k, w, profits, capital);
        leetcode_assert(output == expect, "ipo expect={} output={}", expect, output);
    };
    f(2, 0, {1, 2, 3}, {0, 1, 1}, 4);
    f(3, 0, {1, 2, 3}, {0, 1, 2}, 6);
}
