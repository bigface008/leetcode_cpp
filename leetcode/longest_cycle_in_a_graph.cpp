//
// https://leetcode.cn/problems/longest-cycle-in-a-graph/?envType=daily-question&envId=2025-03-29
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int longestCycle(vector<int> &edges) {
        const int N = edges.size();
        vector<int> in_degrees(N, 0);
        for (int i = 0; i < N; i++) {
            if (edges[i] != -1) {
                in_degrees[edges[i]]++;
            }
        }

        deque<int> dq;
        for (int i = 0; i < N; i++) {
            if (in_degrees[i] == 0) {
                dq.push_back(i);
            }
        }
        while (!dq.empty()) {
            int node = dq.front();
            dq.pop_front();
            int sub_node = edges[node];
            if (sub_node == -1) {
                continue;
            }
            in_degrees[sub_node]--;
            if (in_degrees[sub_node] == 0) {
                dq.push_back(sub_node);
            }
        }
        int ans = -1;
        for (int i = 0; i < N; i++) {
            int degree = in_degrees[i];
            if (degree == 0) {
                continue;
            }
            int ring_size = 1;
            int node = edges[i];
            while (node != i) {
                in_degrees[node] = 0;
                ring_size++;
                node = edges[node];
            }
            ans = max(ans, ring_size);
        }
        return ans;
    }
};


int main() {
    auto f = [](vector<int> &&edges, int expect) {
        auto output = Solution().longestCycle(edges);
        leetcode_assert(output == expect, "longest_cycle_in_a_graph edges={} expect={} output={}", edges, expect,
                        output);
    };
    f({3, 3, 4, 2, 3}, 3);
}
