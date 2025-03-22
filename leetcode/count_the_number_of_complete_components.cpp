//
// https://leetcode.com/problems/count-the-number-of-complete-components/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>> &edges) {
        graph.resize(n, vector<int>());
        visited.resize(n, false);
        for (auto &edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vertexCnt = 0;
                edgeCnt = 0;
                dfs(i);
                if (vertexCnt * (vertexCnt - 1) == edgeCnt) {
                    ans++;
                }
            }
        }
        return ans;
    }

private:
    vector<vector<int>> graph;
    vector<bool> visited;
    int edgeCnt;
    int vertexCnt;

    void dfs(int node) {
        visited[node] = true;
        vector<int> &subNodes = graph[node];
        vertexCnt++;
        edgeCnt += subNodes.size();
        for (int subNode : subNodes) {
            if (!visited[subNode]) {
                dfs(subNode);
            }
        }
    }
};

//class Solution {
//public:
//    int countCompleteComponents(int n, vector<vector<int>> &edges) {
//        parents.resize(n);
//        ranks.resize(n);
//        iota(parents.begin(), parents.end(), 0);
//        unordered_map<int, unordered_set<int>> graph;
//        for (auto &edge : edges) {
//            int a = edge[0], b = edge[1];
//            merge(a, b);
//            graph[a].insert(b);
//            graph[b].insert(a);
//        }
//        unordered_map<int, vector<int>> pa2Nodes;
//        for (int i = 0; i < n; i++) {
//            pa2Nodes[findParent(parents[i])].push_back(i);
//        }
//        int ans = 0;
//        for (auto &&[pa, nodes] : pa2Nodes) {
//            bool valid = true;
//            for (int i : nodes) {
//                for (int j : nodes) {
//                    if (i == j) {
//                        continue;
//                    }
//                    if (!graph[i].contains(j)) {
//                        valid = false;
//                        break;
//                    }
//                }
//                if (!valid) {
//                    break;
//                }
//            }
//            if (valid) {
//                ans++;
//            }
//        }
//        return ans;
//    }
//
//private:
//    vector<int> parents;
//    vector<int> ranks;
//
//    void merge(int a, int b) {
//        int pa = findParent(a);
//        int pb = findParent(b);
//        if (pa == pb) {
//            return;
//        }
//        if (ranks[pa] > ranks[pb]) {
//            parents[pb] = pa;
//        } else if (ranks[pa] < ranks[pb]) {
//            parents[pa] = pb;
//        } else {
//            parents[pb] = pa;
//            ranks[pa]++;
//        }
//    }
//
//    int findParent(int a) {
//        while (a != parents[a]) {
//            parents[a] = parents[parents[a]];
//            a = parents[a];
//        }
//        return a;
//    }
//};


int main() {
    auto f = [](int n, vector<vector<int>> &&edges, int expect) {
        auto output = Solution().countCompleteComponents(n, edges);
        leetcode_assert(output == expect, "count_the_number_of_complete_components n={} edges={} expect={} output={}",
                        n, edges, expect, output);
    };
    f(6, {{0, 1}, {0, 2}, {1, 2}, {3, 4}}, 3);
}
