//
// https://leetcode.cn/problems/network-delay-time/description/?envType=daily-question&envId=2024-11-25
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
        for (auto &info : times) {
            int u = info[0], v = info[1], w = info[2];
            graph[u - 1].emplace_back(v, w);
        }
        vector<int> distances(n, INT_MAX);
        distances[k - 1] = 0;
        priority_queue<pair<int, int>> pq;
        pq.emplace(0, k);
        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
            if (d > distances[node - 1]) {
                continue;
            }
            for (auto [neighbor, neighborDist] : graph[node - 1]) {
                int temp = neighborDist + d;
                if (temp < distances[neighbor - 1]) {
                    distances[neighbor - 1] = temp;
                    pq.emplace(temp, neighbor);
                }
            }
        }
        int ans = *max_element(distances.begin(), distances.end());
        if (ans == INT_MAX) {
            return -1;
        }
        return ans;
    }
};

void doSomething(string &&s) {
    fmt::println("s={}", s);
}

int main() {
//    auto f = [](vector<vector<int>> &&times, int n, int k, int expect) {
//        auto output = Solution().networkDelayTime(times, n, k);
//        leetcode_assert(output == expect, "network_delay_time times={} n={} k={} expect={} output={}", times, n, k,
//                        expect, output);
//    };
//    f(make2DIntVecByStr("[[2,1,1],[2,3,1],[3,4,1]]"), 4, 2, 2);
    string s("justwe");
    doSomething(std::move(s));
    fmt::println("ns={}", s);
}
