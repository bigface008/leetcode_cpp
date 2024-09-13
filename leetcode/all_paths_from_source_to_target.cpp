//
// https://leetcode.com/problems/all-paths-from-source-to-target/description/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        this->graph = graph;
        N = graph.size();
        ans.clear();
        path.clear();
        path.push_back(0);
        dfs(0);
        return ans;
    }

    void dfs(int i) {
        if (i == N - 1) {
            ans.push_back(path);
            return;
        }
        for (int nbr : graph[i]) {
            path.push_back(nbr);
            dfs(nbr);
            path.pop_back();
        }
    }

    int N;
    vector<int> path;
    vector<vector<int>> graph;
    vector<vector<int>> ans;
};

int main() {
    auto f = [](vector<vector<int>> &&graph, vector<vector<int>> &&expect) {
        auto output = Solution().allPathsSourceTarget(graph);
        leetcode_assert(output == expect, "all_paths_from_source_to_target graph={} expect={} output={}", graph, expect, output);
    };
    f();
}
