//
// https://leetcode.cn/problems/smallest-string-with-swaps/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        const int N = s.size();
        ranks.resize(N, 0);
        parents.resize(N, 0);
        iota(parents.begin(), parents.end(), 0);
        for (auto &pair : pairs) {
            merge(pair[0], pair[1]);
        }
        for (int i = 0; i < N; i++) {
            pa2Nodes[findParent(parents[i])].push_back(i);
        }
        string ans(s);
        for (auto &&[pa, nodes] : pa2Nodes) {
            vector<char> chs;
            chs.reserve(nodes.size());
            for (int node : nodes) {
                chs.push_back(s[node]);
            }
            std::sort(chs.begin(), chs.end());
            for (int i = 0; i < nodes.size(); i++) {
                ans[nodes[i]] = chs[i];
            }
        }
        return ans;
    }

private:
    vector<int> parents;
    vector<int> ranks;
    unordered_map<int, vector<int>> pa2Nodes;

    void merge(int a, int b) {
        int pa = findParent(a);
        int pb = findParent(b);
        if (ranks[pa] > ranks[pb]) {
            parents[pb] = pa;
        } else if (ranks[pa] < ranks[pb]) {
            parents[pa] = pb;
        } else {
            parents[pb] = pa;
            ranks[pa]++;
        }
    }

    int findParent(int a) {
        while (a != parents[a]) {
            parents[a] = parents[parents[a]];
            a = parents[a];
        }
        return a;
    }
};

//class Solution {
//public:
//    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
//        N = s.size();
//        graph.resize(N, vector<int>());
//        for (auto &pair : pairs) {
//            int u = pair[0], v = pair[1];
//            graph[u].push_back(v);
//            graph[v].push_back(u);
//        }
//
//        visited.resize(N, false);
//        for (int i = 0; i < N; i++) {
//            if (graph[i].empty() || visited[i]) {
//                continue;
//            }
//            group.clear();
//            dfs(i);
//            conn.push_back(group);
//        }
//        string ans(s);
//        for (auto &indices : conn) {
//            vector<char> chs;
//            for (int i : indices) {
//                chs.push_back(s[i]);
//            }
//            std::sort(chs.begin(), chs.end());
//            std::sort(indices.begin(), indices.end());
//            for (int i = 0; i < indices.size(); i++) {
//                ans[indices[i]] = chs[i];
//            }
//        }
//        return ans;
//    }
//
//private:
//    int N;
//    vector<vector<int>> graph;
//    vector<vector<int>> conn;
//    vector<bool> visited;
//    vector<int> group;
//
//    void dfs(int node) {
//        visited[node] = true;
//        group.push_back(node);
//        for (int subNode : graph[node]) {
//            if (!visited[subNode]) {
//                dfs(subNode);
//            }
//        }
//    }
//};


int main() {
    auto f = [](string s, vector<vector<int>>&& pairs, string expect) {
        auto output = Solution().smallestStringWithSwaps(s, pairs);
        leetcode_assert(output == expect, "smallest_string_with_swaps s={} pairs={} expect={} output={}", s, pairs, expect, output);
    };
    f("dcab", {{0, 3}, {1, 2}, {0, 2}}, "abcd");
}
