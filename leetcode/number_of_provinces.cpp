//
// https://leetcode.com/problems/number-of-provinces/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

void dfs(int index, vector<vector<int>> &graph, vector<bool> &visited) {
    if (visited[index]) {
        return;
    }
    visited[index] = true;
    auto &connected = graph[index];
    for (int i = 0; i < graph.size(); i++) {
        if (i != index && connected[i]) {
            dfs(i, graph, visited);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int cnt = 0;
    vector<bool> visited(isConnected.size(), false);
    for (int i = 0; i < isConnected.size(); i++) {
        if (!visited[i]) {
            dfs(i, isConnected, visited);
            cnt++;
        }
    }
    return cnt;
}

int main() {
    auto f = [](vector<vector<int>> &&isConnected, int expect) {
        auto output = findCircleNum(isConnected);
        leetcode_assert(output == expect, "number_of_provinces isConnected={} expect={} output={}", isConnected, expect, output);
    };
    f(make2DIntVecByStr("[[1,1,0],[1,1,0],[0,0,1]]"), 2);
    f(make2DIntVecByStr("[[1,0,0],[0,1,0],[0,0,1]]"), 3);
}
