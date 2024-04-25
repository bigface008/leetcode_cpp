//
// Created by 汪喆昊 on 2024/4/19.
//

#include "leetcode_utils.hpp"

using namespace std;

// 一棵树有N个节点，N-1条边，已知每个节点之间有且仅有1个路径，每个节点的值只可能是1或者2,现有
// 一条件，要求路径上所有节点的值的乘积为完全平方数，求符合这个条件的所有路径的数量。
// 边无向。

// 解决思路是dfs+dp。首先根据已经给出的每一条单边，以单边为起点，先后向两边延伸。这就是一个
// dfs的递归函数。在这个递归函数中，计算/累积一个cnt变量，来保存当前路径上的值为2的节点的个数。
// 并且在dp数组中填入cnt。注意一开始把dp的每个元素初始化为-1。
// dfs的终止条件是路径的开始结束在dp中的对应位置的值不为-1，相当于有人已经计算过了。

void dfs_v2(vector<int> &path, int &cnt2, vector<vector<int>> &dp, vector<bool> &visited, const map<int, set<int>> &mp,
            const vector<int> &values) {
    if (path.size() < 2) {
        return;
    }
    int start = path.front();
    int end = path.back();
    if (dp[start][end] != -1) {
        return;
    }
    if (values[start] == 2) {
        cnt2++;
    }
    if (values[end] == 2) {
        cnt2++;
    }
    dp[start][end] = cnt2;
    dp[end][start] = cnt2;
    auto sit = mp.find(start);
    if (sit == mp.end()) {
        return;
    }
    for (int neighbor : sit->second) {
        if (neighbor != path[1]) {
            path.insert(path.begin(), neighbor);
            dfs_v2(path, cnt2, dp, visited, mp, values);
            path.erase(path.begin());
        }
    }
    auto eit = mp.find(end);
    if (eit == mp.end()) {
        return;
    }
    for (int neighbor : eit->second) {
        if (neighbor != path[path.size() - 2]) {
            path.push_back(neighbor);
            dfs_v2(path, cnt2, dp, visited, mp, values);
            path.pop_back();
        }
    }
}

int solution(int N, vector<int> &values, vector<pair<int, int>> &edges) {
    vector<vector<int>> dp(N, vector<int>(N, -1));
    map<int, set<int>> mp;
    for (auto &&[p1, p2] : edges) {
        mp[p1].insert(p2);
        mp[p2].insert(p1);
    }
    for (auto &&[p1, p2] : edges) {
        vector<bool> visited(N, false);
        vector<int> path{p1, p2};
        int cnt2 = 0;
        dfs_v2(path, cnt2, dp, visited, mp, values);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (dp[i][j] != -1 && dp[i][j] % 2 == 0) {
                ans++;
            }
        }
    }
    return ans;
}

class Solution {
public:
    // 用于存储树的邻接表
    vector<vector<int>> adj;
    // 用于记录每种状态（0或1）的数量
    vector<int> count;

    // DFS函数，遍历树并统计状态
    void dfs(int node, int parent, int state, vector<int> &values) {
        // 更新当前状态，基于节点值是否为2
        state ^= (values[node] == 2);
        // 统计当前状态的数量
        count[state]++;

        // 遍历所有邻接节点
        for (int next : adj[node]) {
            if (next != parent) {
                dfs(next, node, state, values);
            }
        }
    }

    int countSquareProductPaths(int n, vector<pair<int, int>> &edges, vector<int> &values) {
        // 初始化邻接表和状态计数器
        adj.assign(n, vector<int>());
        count.assign(2, 0);

        // 构建邻接表
        for (auto &[p1, p2] : edges) {
            int u = p1 - 1;
            int v = p2 - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // 从节点0开始DFS遍历
        dfs(0, -1, 0, values);

        // 计算所有有效路径的数量
        int result = n; // 每个节点到自己是一个有效路径
        for (int c : count) {
            if (c > 1) {
                result += c * (c - 1) / 2;
            }
        }

        return result;
    }
};

int main() {
    vector<int> values{1, 2, 2};
    vector<pair<int, int>> edges{{0, 1}, {1, 2}};
    // 1->2, 0->1->2
    auto s = Solution();
    auto res = solution(3, values, edges);
    //    auto res = s.countSquareProductPaths(3, edges, values);
    leetcode_assert(res == 2, "meituan res {}", res);
}
