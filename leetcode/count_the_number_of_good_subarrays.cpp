//
// https://leetcode.cn/problems/count-the-number-of-good-subarrays/?envType=daily-question&envId=2025-04-16
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        const int N = nums.size();
        unordered_map<int, int> cnt;
        int left = 0;
        int pairs = 0;
        long long ans = 0;
        for (int right = 0; right < N; right++) {
            int x = nums[right];
            pairs += cnt[x];
            cnt[x]++;
            while (pairs >= k) {
                int lv = nums[left];
                cnt[lv]--;
                pairs -= cnt[lv];
                left++;
            }
            ans += left;
        }
        return ans;
    }
};

int main() {
//    auto f = [](vector<int>&& nums, int k, long long expect) {
//        auto output = Solution().countGood(nums, k);
//        leetcode_assert(output == expect, "count_the_number_of_good_subarrays nums={} k={} expect={} output={}", nums, k, expect, output);
//    };
//    f();
}
