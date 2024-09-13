//
// https://leetcode.com/problems/find-if-path-exists-in-graph/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination) {
        roots.resize(n);
        sizes.resize(n);
        for (int i = 0; i < n; i++) {
            roots[i] = i;
        }
        std::fill(sizes.begin(), sizes.end(), 1);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            connect(u, v);
        }
        return findRoot(source) == findRoot(destination);
    }

    void connect(int u, int v) {
        int ur = findRoot(u);
        int vr = findRoot(v);
        if (sizes[ur] > sizes[vr]) {
            roots[vr] = ur;
        } else if (sizes[ur] < sizes[vr]){
            roots[ur] = vr;
        } else {
            roots[vr] = ur;
            sizes[ur]++;
        }
    }

    int findRoot(int node) {
        while (roots[node] != node) {
            roots[node] = roots[roots[node]];
            node = roots[node];
        }
        return node;
    }

    vector<int> roots;
    vector<long> sizes;
};

class Solution2 {
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination) {
        this->graph.clear();
        this->source = source;
        this->destination = destination;
        this->visited = vector<bool>(n);
        for (auto &edge : edges) {
            int x = edge[0], y = edge[1];
            graph[x].insert(y);
            graph[y].insert(x);
        }

        queue<int> q;
        visited[source] = true;
        q.push(source);
        while (!q.empty()) {
            int top = q.front();
            if (top == destination) {
                return true;
            }
            q.pop();
            for (int nbr : graph[top]) {
                if (!visited[nbr]) {
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        return false;
    }

    bool dfs(int start) {
        if (start == destination) {
            return true;
        }
        visited[start] = true;
        auto it = graph.find(start);
        if (it == graph.end()) {
            return false;
        }
        if (it->second.contains(destination)) {
            return true;
        }
        for (auto nbr : it->second) {
            if (!visited[nbr] && dfs(nbr)) {
                return true;
            }
        }
        return false;
    }

    int source;
    int destination;
    map<int, set<int>> graph;
    vector<bool> visited;
};

int main() {
    auto f = [](int n, vector<vector<int>> &&edges, int source, int destination, bool expect) {
        auto output = Solution().validPath(n, edges, source, destination);
        leetcode_assert(output == expect,
                        "find_if_path_exists_in_graph n={} edges={} source={} destination={} expect={} output={}", n,
                        edges, source, destination, expect, output);
    };
    f(3, {{0, 1}, {1, 2}, {2, 0}}, 0, 2, true);
}
