//
// https://leetcode.com/problems/total-cost-to-hire-k-workers/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

using Pair = pair<int, bool>;

long long totalCost(vector<int> &costs, int k, int candidates) {
    long long res = 0;
    priority_queue<Pair, vector<Pair>, greater<>> min_heap;
    const int cand2 = 2 * candidates;
    if (costs.size() < cand2) {
        for (int i = 0; i < costs.size(); i++) {
            min_heap.emplace(costs[i], false);
        }
        costs.clear();
    } else {
        for (int i = 0; i < candidates; i++) {
            min_heap.emplace(costs.front(), false);
            min_heap.emplace(costs.back(), true);
            costs.erase(costs.begin());
            costs.erase(costs.end() - 1);
        }
    }

    int cnt = 0;
    vector<int> output;
    while (cnt < k) {
        auto p = min_heap.top();
        res += p.first;
        output.push_back(p.first);
        min_heap.pop();
        cnt++;
        if (cnt >= k) {
            break;
        }

        if (!costs.empty()) {
            if (!p.second) {
                min_heap.emplace(costs[0], false);
                costs.erase(costs.begin());
            } else {
                min_heap.emplace(costs.back(), true);
                costs.erase(costs.end() - 1);
            }
        }
    }
    return res;
}

int main() {
    auto f = [](vector<int> &&costs, int k, int candidates, long expect) {
        auto output = totalCost(costs, k, candidates);
        leetcode_assert(output == expect,
                        "total_cost_to_hire_k_workers costs={} k={} candidates={} expect={} output={}", costs, k,
                        candidates, expect, output);
    };
    f({17, 12, 10, 2, 7, 2, 11, 20, 8}, 3, 4, 11);
    f({1, 2, 4, 1}, 3, 3, 4);
    f({31, 25, 72, 79, 74, 65, 84, 91, 18, 59, 27, 9, 81, 33, 17, 58}, 11, 2, 423);
}
