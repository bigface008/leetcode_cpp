//
// https://leetcode.com/problems/count-the-number-of-fair-pairs/description/?envType=daily-question&envId=2024-11-13
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper) {
        const int N = nums.size();
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> data{{nums[0], 1}};
        for (int i = 1; i < N; i++) {
            if (nums[i] == nums[i - 1]) {
                data.back().second++;
            } else {
                data.emplace_back(nums[i], 1);
            }
        }
        vector<int> preSum(data.size() + 1);
        for (int i = 0; i < data.size(); i++) {
            preSum[i + 1] = preSum[i] + data[i].second;
        }
        int num = nums[0];
        int idx1 = lower_bound(nums.begin(), nums.end(), lower - num) - nums.begin();
        int idx2 = upper_bound(nums.begin(), nums.end(), upper - num) - nums.begin() - 1;
        long long ans = 0;
        for (int i = )
    }
};

class Solution3 {
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper) {
        const int N = nums.size();
        sort(nums.begin(), nums.end());
        int num = nums[0];
        int idx1 = lower_bound(nums.begin(), nums.end(), lower - num) - nums.begin();
        int idx2 = upper_bound(nums.begin(), nums.end(), upper - num) - nums.begin() - 1;
        long long ans = idx2 - idx1 + 1;
        for (int i = 1; i < N; i++) {
            num = nums[i];
            while (idx1 > 0 && nums[idx1 - 1] + num >= lower) {
                idx1--;
            }
            while (idx2 >= 0 && nums[idx2] + num > upper) {
                idx2--;
            }
            if (idx1 <= i && idx2 >= i) {
                ans += idx2 - idx1;
            } else {
                ans += idx2 - idx1 + 1;
            }
        }
        ans /= 2;
        return ans;
    }
};

class Solution2 {
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper) {
        const int N = nums.size();
        map<int, vector<int>> mp;
        long long ans = 0;
        for (int i = 0; i < N; i++) {
            int x = nums[i];
            int val1 = lower - x, val2 = upper - x;
            auto start = mp.lower_bound(val1);
            auto end = mp.upper_bound(val2);
            for (auto it = start; it != end; it++) {
                ans += it->second.size();
            }
            mp[x].push_back(i);
        }
        return ans;
    }
};

int main() {
    auto f = [](vector<int> &&nums, int lower, int upper, long expect) {
        auto output = Solution().countFairPairs(nums, lower, upper);
        leetcode_assert(output == expect,
                        "count_the_number_of_fair_pairs nums={} lower={} upper={} expect={} output={}", nums, lower,
                        upper, expect, output);
    };
    f({0, 1, 7, 4, 4, 5}, 3, 6, 6);
    //    map<int, int> mp;
    //    mp[1] = 1;
    //    mp[2] = 2;
    //    mp[3] = 3;
    //    mp[4] = 4;
    //    mp[5] = 5;
    //    int idx = mp.lower_bound(3) - mp.begin();
    //    fmt::println("{}", idx);
}
