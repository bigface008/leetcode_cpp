//
// https://leetcode.com/problems/split-array-largest-sum/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        const int N = nums.size();
        if (N < k) {
            return 0;
        }
        if (N == k) {
            return *max_element(nums.begin(), nums.end());
        }
        int sum = 0;
        int prevKSum = 0;
        int prevKMax = 0;
        for (int i = 0; i < N; i++) {
            int x = nums[i];
            sum += x;
            if (i <= k - 2) {
                prevKMax = max(prevKMax, x);
                prevKSum = sum;
            }
        }
        int left = 1, right = max(sum - prevKSum, prevKMax);
        while (left < right) {
            int mid = (left + right) / 2;
            if (isValid(nums, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool isValid(vector<int> &nums, int k, int limit) {
        int groupCnt = 1;
        int groupSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if (x > limit) {
                return false;
            }
            int newGroupSum = groupSum + x;
            if (newGroupSum > limit) {
                groupSum = x;
                groupCnt++;
                if (groupCnt > k) {
                    return false;
                }
            } else {
                groupSum = newGroupSum;
            }
        }
        return true;
    }
};

int main() {
    auto f = [](vector<int> &&nums, int k, int expect) {
        auto output = Solution().splitArray(nums, k);
        leetcode_assert(output == expect, "split_array_largest_sum nums={} k={} expect={} output={}", nums, k, expect, output);
    };
//    f({7, 2, 5, 10, 8}, 2, 18);
//    f({1, 4, 4}, 3, 4);
    f({2, 3, 1, 2, 4, 3}, 5, 4);
}
