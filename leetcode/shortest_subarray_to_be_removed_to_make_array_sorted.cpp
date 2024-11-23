//
// https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/?envType=daily-question&envId=2024-11-15
//

#include "leetcode_utils.hpp"

using namespace std;

// ...... i-1  i
// ....|  i-1|

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int> &arr) {
        const int N = arr.size();
        if (N <= 1) {
            return 0;
        }
        int right = N - 1;
        while (right > 0 && arr[right - 1] <= arr[right]) {
            right--;
        }
        if (right == 0) {
            return 0;
        }
        int ans = right;
        for (int left = 0; left < N; left++) {
            if (left == 0 || arr[left - 1] <= arr[left]) {
                while (right < N && arr[left] > arr[right]) {
                    right++;
                }
                ans = min(ans, right - left - 1);
            } else {
                break;
            }
        }
        return ans;
    }
};

class Solution4 {
public:
    int findLengthOfShortestSubarray(vector<int> &arr) {
        const int N = arr.size();
        vector<bool> prefix(N, false);
        prefix[0] = true;
        vector<bool> suffix(N, false);
        suffix[N - 1] = true;
        int prefixLen = 0;
        for (int i = 1; i < N; i++) {
            if (arr[i - 1] <= arr[i]) {
                prefix[i] = prefix[i - 1];
            } else {
                prefixLen = i;
                break;
            }
        }
        int suffixLen = 0;
        for (int i = N - 2; i >= 0; i--) {
            if (arr[i] <= arr[i + 1]) {
                suffix[i] = suffix[i + 1];
            } else {
                suffixLen = N - 1 - i;
                break;
            }
        }
        int ans = min(min(N - 1, N - prefixLen), N - suffixLen);
        for (int i = 0; i < N; i++) {
            int vi = arr[i];
            for (int j = N - 1; j > i; j--) {
                int vj = arr[j];
                if (prefix[i] && suffix[j] && (vi <= vj)) {
                    ans = min(ans, j - i - 1);
                }
            }
        }
        return ans;
    }
};

// class Solution3 {
// public:
//     int findLengthOfShortestSubarray(vector<int> &arr) {
//         N = arr.size();
//         prefix.resize(N);
//         suffix.resize(N);
//         prefix[0] = true;
//         suffix[N - 1] = true;
//         for (int i = 1; i < N; i++) {
//             if (arr[i - 1] <= arr[i]) {
//                 prefix[i] = prefix[i - 1];
//             } else {
//                 prefix[i] = false;
//             }
//             if (arr[N - i - 1] <= arr[N - i]) {
//                 suffix[N - i - 1] = suffix[N - i];
//             } else {
//                 suffix[N - i - 1] = false;
//             }
//         }
//         int i = 0, j = N - 1;
//         while (i < j) {
//             if (i == 0 || arr[i] >= arr[i - 1]) {
//                 i++;
//             }
//             if () {
//             }
//         }
//     }
//
// private:
//     int N;
//     vector<bool> prefix;
//     vector<bool> suffix;
//
//     bool dfs2(int i, int j, vector<int> &arr) {
//         if (i == j) {
//             return false;
//         }
//         int vi = arr[i], vj = arr[j];
//         if (vi <= vj) {
//             return prefix[i] && suffix[j];
//         }
//         return false;
//     }
//
//     bool dfs(int i, int j, vector<int> &arr) {
//         if (i > j) {
//             return false;
//         }
//         if (!(prefix[i] && suffix[j])) {
//             return false;
//         }
//         int ans = N - 1;
//         int vi = arr[i], vj = arr[j];
//         if (vi <= vj) {
//             ans = j - i - 1;
//         }
//     }
// };


// class Solution2 {
// public:
//     int findLengthOfShortestSubarray(vector<int> &arr) {
//         const int N = arr.size();
//         memo.resize(N, -1);
//         ret = N - 1;
//         return dfs(N - 1, arr);
//     }
//
// private:
//     vector<int> memo;
//     int ret;
//
//     int dfs(int idx, vector<int> &arr) {
//         if (idx == 0) {
//             return 0;
//         }
//         if (idx == 1) {
//             return arr[0] <= arr[1] ? 0 : 1;
//         }
//         if (memo[idx] != -1) {
//             return memo[idx];
//         }
//         int curr = arr[idx];
//         int ans = idx;
//         for (int i = 0; i < idx; i++) {
//             int len = dfs(i, arr);
//             if (arr[i - len] <= curr) {
//                 ans = min(ans, idx - i + len);
//             }
//         }
//         memo[idx] = ans;
//         return ans;
//     }
// };


int main() {
    auto f = [](vector<int> &&arr, int expect) {
        auto output = Solution().findLengthOfShortestSubarray(arr);
        leetcode_assert(output == expect,
                        "shortest_subarray_to_be_removed_to_make_array_sorted arr={} expect={} output={}", arr, expect,
                        output);
    };
    //    f({1, 2, 3, 10, 4, 2, 3, 5}, 3);
    f({2, 2, 2, 1, 1, 1}, 3);
}
