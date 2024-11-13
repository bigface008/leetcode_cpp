//
// https://leetcode.cn/problems/count-the-number-of-good-nodes/?envType=daily-question&envId=2024-11-14
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        ans = 0;
        for (vector<int>& edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        dfs(0, -1);
        return ans;
    }

private:
    int ans = 0;

    unordered_map<int, vector<int>> graph;

    int dfs(int i, int pa) {
        vector<int>& neighbors = graph[i];
        vector<int> sub;
        for (int x : neighbors) {
            if (x != pa) {
                sub.push_back(x);
            }
        }
        int N = sub.size();
        int subTreeSize = N > 0 ? dfs(sub[0], i) : 0;
        bool good = true;
        int size = subTreeSize + 1;
        for (int j = 1; j < N; j++) {
            int s = dfs(sub[j], i);
            if (s != subTreeSize) {
                good = false;
            }
            size += s;
        }
        if (good) {
            ans++;
        }
        return size;
    }
};

int main() {
    auto f = [](vector<vector<int>> &&edges, int expect) {
        auto output = Solution().countGoodNodes(edges);
        leetcode_assert(output == expect, "count_the_number_of_good_nodes edges={} expect={} output={}", edges, expect, output);
    };
//    f(make2DIntVecByStr("[[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]"), 7);
    f(make2DIntVecByStr("[[0,1],[1,2],[1,3],[1,4],[0,5],[5,6],[6,7],[7,8],[0,9],[9,10],[9,12],[10,11]]"), 12);
}
