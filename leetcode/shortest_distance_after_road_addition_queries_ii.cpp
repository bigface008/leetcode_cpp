//
// https://leetcode.cn/problems/shortest-distance-after-road-addition-queries-ii/?envType=daily-question&envId=2024-11-20
//

#include "leetcode_utils.hpp"

using namespace std;

// 0---1---2---3---4
//     |-----------|
//         |-------|

// 0---1---2---3---4---5---6---7---8---9--10--11
//                 |-----------|
//                                 |-------|
// |---------------------------|

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries) {
        const int NQ = queries.size();
        vector<int> ans(NQ);
        vector<int> fa(n - 1);
        iota(fa.begin(), fa.end(), 0);
        int minDist = n - 1;
        for (int q = 0; q < NQ; q++) {
            int u = queries[q][0], v = queries[q][1];
            int fv = dfs(v - 1, fa);
            int i = dfs(u, fa);
            while (i < v - 1) {
                minDist--;
                fa[i] = fv;
                i = dfs(i + 1, fa);
            }
            ans[q] = minDist;
        }
        return ans;
    }

private:
    int dfs(int x, vector<int>& fa) {
        int root = x;
        while (fa[root] != root) {
            fa[root] = fa[fa[root]];
            root = fa[root];
        }
        return root;
    }
};

class Solution5 {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries) {
        const int NQ = queries.size();
        vector<int> ans(NQ);
        vector<int> next(n);
        iota(next.begin(), next.end(), 1);
        next[n - 1] = n - 1;
        int minDist = n - 1;
        for (int q = 0; q < NQ; q++) {
            int u = queries[q][0], v = queries[q][1];
            if (0 < next[u] && next[u] < v) {
                int i = next[u];
                while (i < v) {
                    minDist--;
                    int tmp = next[i];
                    next[i] = 0;
                    i = tmp;
                }
                next[u] = v;
            }
            ans[q] = minDist;
        }
        return ans;
    }
};

class Solution3 {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries) {
        const int NQ = queries.size();
        vector<int> ans(NQ);
        vector<int> farthest(n);
        for (int i = 1; i < n; i++) {
            farthest[i - 1] = i;
        }
        vector<int> dist2Start(n);
        iota(dist2Start.begin(), dist2Start.end(), 0);
        for (int q = 0; q < NQ; q++) {
            int u = queries[q][0], v = queries[q][1];
            if (v > farthest[u]) {
                farthest[u] = v;
                dist2Start[v] = min(dist2Start[v], 1 + dist2Start[u]);
                updateMemo(dist2Start, farthest, v);

//                int idx = v, next = farthest[v];
//                while (1 + dist2Start[idx] < dist2Start[next]) {
//                    dist2Start[next] = 1 + dist2Start[idx];
//                    idx = next;
//                    next = farthest[idx];
//                }
            }
            ans[q] = dist2Start[n - 1];
        }
        return ans;
    }

    void updateMemo(vector<int> &dist2Start, vector<int> &farthest, int idx) {
        const int N = farthest.size();
        if (idx == N - 1) {
            return;
        }
        int next = farthest[idx];
        int val = min(dist2Start[next], 1 + dist2Start[idx]);
        if (val < dist2Start[next]) {
            dist2Start[next] = val;
            updateMemo(dist2Start, farthest, next);
        }
    }
};

class Solution3 {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries) {
        const int NQ = queries.size();
        vector<int> ans(NQ, n - 1);
        vector<int> farthest(n);
        vector<int> dist2Last(n);
        dist2Last[0] = n - 1;
        for (int i = 1; i < n; i++) {
            farthest[i - 1] = i;
            dist2Last[i] = n - i - 1;
        }
        farthest[n - 1] = n - 1;
        vector<int> dist2Start(n);
        iota(dist2Start.begin(), dist2Start.end(), 0);
        int minDist = n - 1;
        for (int q = 0; q < NQ; q++) {
            int u = queries[q][0], v = queries[q][1];
            if (v > farthest[u]) {
                farthest[u] = v;
                dist2Start[v] = min(dist2Start[v], 1 + dist2Start[u]);
                dist2Last[u] = dist2Last[v] + 1;
            }
            if (q == 0) {
            }
            minDist = min(minDist, dist2Last[u] + dist2Start[u]);
            ans[q] = minDist;
        }
        return ans;
    }
    //
    //    void updateMemo(vector<int> &memo, vector<int> &farthest, int idx) {
    //        const int N = farthest.size();
    //        if (idx == N - 1) {
    //            return;
    //        }
    //        int next = farthest[idx];
    //        int val = min(memo[next], 1 + memo[idx]);
    //        if (val < memo[next]) {
    //            memo[next] = val;
    //            updateMemo(memo, farthest, next);
    //        }
    //    }
};

class Solution2 {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries) {
        const int NQ = queries.size();
        vector<int> ans(NQ);
        vector<vector<int>> graph(n, vector<int>());
        for (int i = 1; i < n; i++) {
            graph[i - 1].push_back(i);
        }
        vector<int> memo(n);
        iota(memo.begin(), memo.end(), 0);
        for (int q = 0; q < NQ; q++) {
            int u = queries[q][0], v = queries[q][1];
            graph[u].push_back(v);
            memo[v] = min(memo[v], 1 + memo[u]);
            updateMemo(memo, graph, v);
            ans[q] = memo[n - 1];
        }
        return ans;
    }

    void updateMemo(vector<int> &memo, vector<vector<int>> &graph, int idx) {
        const int N = graph.size();
        if (idx == N - 1) {
            return;
        }
        for (int next : graph[idx]) {
            int val = min(memo[next], 1 + memo[idx]);
            if (val < memo[next]) {
                memo[next] = val;
                updateMemo(memo, graph, next);
            }
        }
    }
};


int main() {
    auto f = [](int n, vector<vector<int>> &&queries, vector<int> expect) {
        auto output = Solution().shortestDistanceAfterQueries(n, queries);
        leetcode_assert(output == expect,
                        "shortest_distance_after_road_addition_queries_ii n={} queries={} expect={} output={}", n,
                        queries, expect, output);
    };
    //    f(5, make2DIntVecByStr("[[2,4],[0,2],[0,4]]"), {3, 2, 1});
    //    f(5, make2DIntVecByStr("[[1,4],[2,4]]"), {2, 2});
    f(12, make2DIntVecByStr("[[4,7],[8,10],[0,7]]"), {9, 8, 4});
}
