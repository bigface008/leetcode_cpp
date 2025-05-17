//
// https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/?envType=daily-question&envId=2025-05-10
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    long long minSum(vector<int> &nums1, vector<int> &nums2) {
        const int N1 = nums1.size(), N2 = nums2.size();
        long long sum1 = 0, sum2 = 0;
        int zero_cnt1 = 0, zero_cnt2 = 0;
        for (int i = 0; i < N1; i++) {
            sum1 += nums1[i];
            if (nums1[i] == 0) {
                zero_cnt1++;
            }
        }
        for (int i = 0; i < N2; i++) {
            sum2 += nums2[i];
            if (nums2[i] == 0) {
                zero_cnt2++;
            }
        }
        long long t1 = sum1 + zero_cnt1;
        long long t2 = sum2 + zero_cnt2;
        if (t1 < t2) {
            swap(t1, t2);
            swap(sum1, sum2);
            swap(zero_cnt1, zero_cnt2);
        }
        if (t1 != t2 && zero_cnt2 == 0) {
            return -1;
        }
        return max(t1, t2);
    }
};


int main() {
    auto f = [](vector<int> &&nums1, vector<int> &&nums2, long long expect) {
        auto output = Solution().minSum(nums1, nums2);
        leetcode_assert(output == expect,
                        "minimum_equal_sum_of_two_arrays_after_replacing_zeros nums1={} nums2={} expect={} output={}",
                        nums1, nums2, expect, output);
    };
    f({0, 16, 28, 12, 10, 15, 25, 24, 6, 0, 0}, {20, 15, 19, 5, 6, 29, 25, 8, 12}, 139);
}
