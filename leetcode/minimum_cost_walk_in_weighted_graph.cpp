//
// https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        graph.resize(n, vector<pair<int, int>>());
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }
        connIds.resize(n, -1);
        vector<int> andValues;
        for (int i = 0; i < n; i++) {
            if (connIds[i] == -1) {
                andValues.push_back(dfs(i, andValues.size()));
            }
        }
        vector<int> ans;
        ans.reserve(query.size());
        for (auto &q : query) {
            int u = q[0], v = q[1];
            ans.push_back(connIds[u] == connIds[v] ? andValues[connIds[u]] : -1);
        }
        return ans;
    };

private:
    vector<vector<pair<int, int>>> graph;
    vector<int> connIds;

    int dfs(int node, int connId) {
        int res = -1;
        connIds[node] = connId;
        for (auto [subNode, w] : graph[node]) {
            res &= w;
            if (connIds[subNode] == -1) {
                res &= dfs(subNode, connId);
            }
        }
        return res;
    }
};


int main() {
    auto f = [](int n, vector<vector<int>>&& edges, vector<vector<int>>&& query, vector<int> expect) {
        auto output = Solution().minimumCost(n, edges, query);
        leetcode_assert(output == expect, "minimum_cost_walk_in_weighted_graph n={} edges={} query={} expect={} output={}", n, edges, query, expect, output);
    };
    f();
}
