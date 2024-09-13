//
// https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/description/
//

#include "leetcode_utils.hpp"

using namespace std;

vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries) {
    vector<vector<int>> from(n, vector<int>());
    vector<int> dp(n, 0);
    iota(dp.begin(), dp.end(), 0);
    vector<int> ans;
    for (auto &query : queries) {
        int u = query[0], v = query[1];
        from[v].push_back(u);
        dp[v] = dp[u] + 1;
        for (int i = v; i < n; i++) {
            dp[i] = min(dp[i], dp[i - 1] + 1);
            for (int j : from[i]) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        ans.push_back(dp.back());
    }
    return ans;
}

vector<int> shortestDistanceAfterQueries2(int n, vector<vector<int>> &queries) {
    vector<vector<int>> graph(n, vector<int>());
    vector<int> ans;
    for (int i = 0; i < n - 1; i++) {
        graph[i].push_back(i + 1);
    }
    for (auto &query : queries) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap; // (dist, target_idx)
        int u = query[0], v = query[1];
        graph[u].push_back(v);
        min_heap.emplace(0, 0);
        vector<int> distances(n, INT_MAX);
        distances[0] = 0;
        while (!min_heap.empty()) {
            auto [dist, idx] = min_heap.top();
            min_heap.pop();
            if (distances[idx] < dist) {
                continue;
            }
            for (int nbr : graph[idx]) {
                int d = distances[idx] + 1;
                if (d < distances[nbr]) {
                    distances[nbr] = d;
                    min_heap.emplace(d, nbr);
                }
            }
        }
        ans.push_back(distances[n - 1]);
    }
    return ans;
}

int main() {
    auto f = [](int n, vector<vector<int>> &&queries, vector<int> &&expect) {
        auto output = shortestDistanceAfterQueries(n, queries);
        leetcode_assert(output == expect,
                        "shortest_distance_after_road_addition_queries_i n={} queries={} expect={} output={}", n,
                        queries, expect, output);
    };
    f(5, {{2, 4}, {0, 2}, {0, 4}}, {3, 2, 1});
}
