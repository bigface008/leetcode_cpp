//
// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/?envType=daily-question&envId=2024-11-17
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int> &nums, int k) {
        const int N = nums.size();
        int ans = INT_MAX;
        deque<int> dq;
        vector<long> preSum(N + 1);
        for (int i = 0; i < N; i++) {
            preSum[i + 1] = preSum[i] + nums[i];
        }
        for (int i = 0; i < N + 1; i++) {
            long curS = preSum[i];
            while (!dq.empty() && curS - preSum[dq.front()] >= k) {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && preSum[dq.back()] >= curS) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return ans < INT_MAX ? ans : -1;
    }
};

//class Solution {
//public:
//    int shortestSubarray(vector<int> &nums, int k) {
//        const int N = nums.size();
//        int sum = 0;
//        int right = 0, left = 0;
//        bool valid = false;
//        int ans = N;
//        for (; right < N; right++) {
//            sum += nums[right];
//            while (sum >= k) {
//                ans = min(ans, right - left + 1);
//                valid = true;
//                sum -= nums[left];
//                left++;
//            }
//        }
//        return valid ? ans : -1;
//    }
//};
//
//class Solution2 {
//public:
//    int shortestSubarray(vector<int> &nums, int k) {
//        const int N = nums.size();
//        int sum = 0;
//        int right = 0, left = 0;
//        bool valid = false;
//        int ans = N;
//        for (; right < N; right++) {
//            //            if (sum >= k) {
//            //                valid = true;
//            //                while (sum >= k) {
//            //                    ans = min(ans, right - left + 1);
//            //                    sum -= nums[left];
//            //                    left++;
//            //                }
//            //                break;
//            //            }
//            sum += nums[right];
//            if (sum >= k) {
//                break;
//            }
//        }
//        if (sum < k) {
//            return -1;
//        }
//        for (; right < N; right++) {
//            sum += nums[right];
//            while (sum >= k) {
//                ans = min(ans, right - left + 1);
//                sum -= nums[left];
//                left++;
//            }
//        }
//        return ans;
//    }
//};


int main() {
    auto f = [](vector<int> &&nums, int k, int expect) {
        auto output = Solution().shortestSubarray(nums, k);
        leetcode_assert(output == expect, "shortest_subarray_with_sum_at_least_k nums={} k={} expect={} output={}",
                        nums, k, expect, output);
    };
    //    f({1}, 1, 1);
    //    f({17, 85, 93, -45, -21}, 150, 2);
    f({84, -37, 32, 40, 95}, 167, 3);
}
