//
// https://leetcode.com/problems/redundant-connection/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int N = 0;
        for (vector<int> &edge : edges) {
            N = max(N, max(edge[0], edge[1]));
        }
        roots.resize(N);
        ranks.resize(N);
        iota(roots.begin(), roots.end(), 0);

        for (vector<int> &edge : edges) {
            int u = edge[0] - 1, v = edge[1] - 1;
            if (!connect(u, v)) {
                return edge;
            }
        }
        return {};
    }

private:
    vector<int> roots;
    vector<int> ranks;

    bool connect(int u, int v) {
        int ru = findRoot(u);
        int rv = findRoot(v);
        if (ru == rv) {
            return false;
        }
        if (ranks[ru] > ranks[rv]) {
            roots[rv] = ru;
        } else if (ranks[u] < ranks[v]) {
            roots[ru] = rv;
        } else {
            roots[rv] = ru;
            ranks[ru]++;
        }
        return true;
    }

    int findRoot(int u) {
        while (roots[u] != u) {
            roots[u] = roots[roots[u]];
            u = roots[u];
        }
        return u;
    }
};

int main() {
    auto f = [](vector<vector<int>> &&edges, vector<int> &&expect) {
        auto output = Solution().findRedundantConnection(edges);
        leetcode_assert(output == expect, "redundant_connection edges={} expect={} output={}", edges, expect, output);
    };
//    f({{1, 2}, {1, 3}, {2, 3}}, {2, 3});
    f({{1, 4}, {3, 4}, {1, 3}, {1, 2}, {4, 5}}, {1, 3});
}
