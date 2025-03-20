//
// https://leetcode.cn/problems/minimum-reverse-operations/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int> &banned, int k) {
        unordered_set<int> isBanned(banned.begin(), banned.end());
        set<int> graph[2];
        for (int i = 0; i < n; i++) {
            if (i != p && !isBanned.contains(i)) {
                graph[i % 2].insert(i);
            }
        }
        vector<int> ans(n, -1);
        ans[p] = 0;
        deque<int> dq;
        dq.push_back(p);
        while (!dq.empty()) {
            int node = dq.front();
            dq.pop_front();
            int mn = max(node - k + 1, k - node - 1);
            int mx = min(node + k - 1, n * 2 - k - node - 1);
            auto &st = graph[node % 2];
            for (auto it = st.lower_bound(mn); *it <= mx && it != st.end(); it = st.erase(it)) {
                ans[*it] = ans[node] += 1;
                dq.push_back(*it);
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> minReverseOperations(int n, int p, vector<int> &banned, int k) {
//         vector<int> ans(n, -1);
//         unordered_set<int> isBanned(banned.begin(), banned.end());
//         deque<int> dq;
//         vector<bool> visited(n, false);
//         visited[p] = true;
//         ans[p] = 0;
//         dq.push_back(p);
//         while (!dq.empty()) {
//             int node = dq.front();
//             dq.pop_front();
//
//             int start = max(0, node - k + 1);
//             int end = min(n - k, node);
//             for (int j = start; j <= end; j += 1) {
//                 int subNode = k - 1 - (node - j) + j;
//                 if (subNode != node && !isBanned.contains(subNode) && !visited[subNode]) {
//                     visited[subNode] = true;
//                     ans[subNode] = ans[node] + 1;
//                     dq.push_back(subNode);
//                 }
//             }
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<int> minReverseOperations(int n, int p, vector<int> &banned, int k) {
//         vector<int> ans(n, -1);
//         unordered_set<int> isBanned(banned.begin(), banned.end());
//         deque<int> dq;
//         vector<bool> visited(n, false);
//         visited[p] = true;
//         dq.push_back(p);
//         int step = 0;
//         while (!dq.empty()) {
//             int levelSize = dq.size();
//             for (int i = 0; i < levelSize; i++) {
//                 int node = dq.front();
//                 ans[node] = step;
//                 dq.pop_front();
//
//                 int start = max(0, node - k + 1);
//                 int end = min(n - k, node);
//                 for (int j = start; j <= end; j += 1) {
//                     int subNode = k - 1 - (node - j) + j;
//                     if (subNode != node && !isBanned.contains(subNode) && !visited[subNode]) {
//                         visited[subNode] = true;
//                         dq.push_back(subNode);
//                     }
//                 }
//             }
//             step++;
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<int> minReverseOperations(int n, int p, vector<int> &banned, int k) {
//         vector<int> ans(n, -1);
//         vector<vector<int>> graph(n, vector<int>());
//         unordered_set<int> isBanned;
//         for (int x : banned) {
//             isBanned.insert(x);
//         }
//         for (int i = 0; i < n; i++) {
//             if (isBanned.contains(i)) {
//                 continue;
//             }
//             int start = max(0, i - k + 1);
//             int end = min(n - k, i);
//             for (int j = start; j <= end; j += 1) {
//                 int target = k - 1 - (i - j) + j;
//                 if (target != i && !isBanned.contains(target)) {
//                     graph[i].push_back(target);
//                 }
//             }
//         }
//         deque<int> dq;
//         vector<bool> visited(n, false);
//         visited[p] = true;
//         dq.push_back(p);
//         int step = 0;
//         while (!dq.empty()) {
//             int levelSize = dq.size();
//             for (int i = 0; i < levelSize; i++) {
//                 int node = dq.front();
//                 ans[node] = step;
//                 dq.pop_front();
//                 for (int subNode : graph[node]) {
//                     if (!visited[subNode]) {
//                         visited[subNode] = true;
//                         dq.push_back(subNode);
//                     }
//                 }
//             }
//             step++;
//         }
//         return ans;
//     }
// };


int main() {
    auto f = [](int n, int p, vector<int> &&banned, int k, vector<int> expect) {
        auto output = Solution().minReverseOperations(n, p, banned, k);
        leetcode_assert(output == expect, "minimum_reverse_operations n={} p={} banned={} k={} expect={} output={}", n,
                        p, banned, k, expect, output);
    };
    //    f(4, 0, {1, 2}, 4, {0, -1, -1, 1});
    //    f(5, 0, {}, 2, {0, 1, 2, 3, 4});
    //    f(2, 1, {}, 2, {1, 0});
    f(8, 6, {0}, 5, {-1, -1, 1, -1, 1, -1, 0, -1});
}
