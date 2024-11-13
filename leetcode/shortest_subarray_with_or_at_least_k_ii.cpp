//
// https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/description/?envType=daily-question&envId=2024-11-10
//

#include "leetcode_utils.hpp"

using namespace std;

//class Solution {
//public:
//    int minimumSubarrayLength(vector<int> &nums, int k) {
//        if (nums[0] >= k) {
//            return 1;
//        }
//        int all_xor = 0;
//        for (int x : nums) {
//            all_xor |= x;
//        }
//        if (all_xor < k) {
//            return -1;
//        }
//
//        const int N = nums.size();
//        int ans = N;
//        for (int i = 1; i < N; i++) {
//            int x = nums[i];
//            if (x >= k) {
//                return 1;
//            }
//            if (i > 0 && nums[i - 1] == x) {
//                continue;
//            }
//            if ((nums[0] | x) < k) {
//                for (int j = 0; j < i; j++) {
//                    nums[j] |= x;
//                }
//                continue;
//            }
//            int start = max(0, i - ans), end = i;
//            while (start < end) {
//                int mid = start + (end - start) / 2;
//                int val = nums[mid];
//                if ((val | x) >= k) {
//                    ans = min(ans, i - mid + 1);
//                    start = mid + 1;
//                } else {
//                    end = mid;
//                }
//            }
//            for (int j = start; j < i; j++) {
//                nums[j] |= x;
//            }
//        }
//        return ans;
//    }
//};

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int all_xor = 0;
        for (int x : nums) {
            all_xor |= x;
        }
        if (all_xor < k) {
            return -1;
        }
        const int N = nums.size();
        int ans = N;
        for (int i = 0; i < N; i++) {
            int x = nums[i];
            if (x >= k) {
                return 1;
            }
            if (i > 0 && x == nums[i - 1]) {
                continue;
            }
            for (int j = i - 1; j >= 0; j--) {
                int new_val = nums[j] | x;
                if ((i - j + 1) >= ans) {
                    break;
                }
                if (new_val >= k) {
                    ans = min(ans, i - j + 1);
                    break;
                }
                if (nums[j] == new_val) {
                    break;
                }
                nums[j] |= x;
            }
        }
        return ans;
    }
};

int main() {
    auto f = [](vector<int> &&nums, int k, int expect) {
        auto output = Solution().minimumSubarrayLength(nums, k);
        leetcode_assert(output == expect, "shortest_subarray_with_or_at_least_k_ii nums={} k={} expect={} output={}", nums, k, expect, output);
    };
//    f({2, 1, 8}, 10, 3);
    f({2, 32, 27, 1}, 59, 2);
}
