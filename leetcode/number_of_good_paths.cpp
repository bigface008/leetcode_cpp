//
// https://leetcode.cn/problems/number-of-good-paths/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        const int N = vals.size();
        vector<vector<int>> graph(N, vector<int>());
        for (auto &edge : edges) {
            int x = edge[0], y = edge[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        vector<int> id(N, 0), parents(N, 0), sizes(N, 1);
        iota(id.begin(), id.end(), 0);
        iota(parents.begin(), parents.end(), 0);

        auto findParent = [&](int x) -> int {
            while (x != parents[x]) {
                parents[x] = parents[parents[x]];
                x = parents[x];
            }
            return x;
        };

        int ans = N;
        sort(id.begin(), id.end(), [&](int i, int j) {
            return vals[i] < vals[j];
        });
        fmt::println("id={} parents={} sizes={}", id, parents, sizes);
        for (int x : id) {
            int vx = vals[x], fx = findParent(x);
            for (int y : graph[x]) {
                y = findParent(y);
                if (y == fx || vals[y] > vx) {
                    continue;
                }
                if (vals[y] == vx) {
                    ans += sizes[fx] * sizes[y];
                    sizes[fx] += sizes[y];
                }
                parents[y] = fx;
            }
        }
        fmt::println("id={} parents={} sizes={}", id, parents, sizes);
        return ans;
    }
};


int main() {
    auto f = [](vector<int>&& vals, vector<vector<int>>&& edges, int expect) {
        auto output = Solution().numberOfGoodPaths(vals, edges);
        leetcode_assert(output == expect, "number_of_good_paths vals={} edges={} expect={} output={}", vals, edges, expect, output);
    };
    f({1,3,2,1,3}, make2DIntVecByStr("[[0,1],[0,2],[2,3],[2,4]]"), 6);
}
