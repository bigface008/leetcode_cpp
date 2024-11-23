//
// https://leetcode.cn/problems/maximum-score-of-spliced-array/
//

#include "leetcode_utils.hpp"

using namespace std;

//class Solution {
//public:
//    int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2) {
//        const int N = nums1.size();
//        vector<int> diff(N);
//        int dp1 = 0, dp2 = 0;
//        int max1 = 0, max2 = 0;
//        for (int i = 0; i < N; i++) {
//            diff[i] = nums2[i] - nums1[i];
//            if (i == 0) {
//                dp1 = diff[i];
//                dp2 = diff[i];
//            } else {
//                dp
//            }
//        }
//    }
//};

class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        const int N = nums1.size();
        vector<int> diff(N);
        int dp1 = 0, dp2 = 0;
        int sum1 = 0, sum2 = 0;
        int max1 = 0, max2 = 0;
        for (int i = 0; i < N; i++) {
            sum1 += nums1[i];
            sum2 += nums2[i];
            diff[i] = nums2[i] - nums1[i];
            if (i == 0) {
                dp1 = diff[i];
                dp2 = -diff[i];
            } else {
                if (dp1 >= 0) {
                    dp1 += diff[i];
                } else {
                    dp1 = diff[i];
                }
                if (dp2 >= 0) {
                    dp2 += -diff[i];
                } else {
                    dp2 = -diff[i];
                }
            }
            max1 = max(max1, dp1);
            max2 = max(max2, dp2);
        }
        int ans = max(max1 + sum1, max2 + sum2);
        ans = max(ans, sum1);
        ans = max(ans, sum2);
        return ans;
    }
};


int main() {
    auto f = [](vector<int>&& nums1, vector<int>&& nums2, int expect) {
        auto output = Solution().maximumsSplicedArray(nums1, nums2);
        leetcode_assert(output == expect, "maximum_score_of_spliced_array nums1={} nums2={} expect={} output={}", nums1, nums2, expect, output);
    };
    f();
}
