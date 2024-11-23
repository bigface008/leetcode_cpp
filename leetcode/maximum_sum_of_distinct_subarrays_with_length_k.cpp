//
// https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/?envType=daily-question&envId=2024-11-19
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int> &nums, int k) {
        const int N = nums.size();
        long long sum = 0;
        unordered_map<int, int> freq;
        for (int i = 0; i < k; i++) {
            int x = nums[i];
            freq[x]++;
            sum += x;
        }
        long long ans = 0;
        if (freq.size() == k) {
            ans = max(ans, sum);
        }
        for (int i = k; i < N; i++) {
            int curr = nums[i];
            int prev = nums[i - k];
            freq[curr]++;
            freq[prev]--;
            if (freq[prev] == 0) {
                freq.erase(prev);
            }
            sum = sum + curr - prev;
            if (freq.size() == k) {
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    long long maximumSubarraySum(vector<int> &nums, int k) {
        const int N = nums.size();
        long long sum = 0;
        unordered_map<int, int> freq;
        bool prevValid = true;
        for (int i = 0; i < k; i++) {
            int x = nums[i];
            freq[x]++;
            if (freq[x] > 1) {
                prevValid = false;
            }
            sum += x;
        }
        long long ans = 0;
        if (prevValid) {
            ans = max(ans, sum);
        }
        for (int i = k; i < N; i++) {
            int curr = nums[i];
            int prev = nums[i - k];
            freq[curr]++;
            freq[prev]--;
            if (freq[prev] == 0) {
                freq.erase(prev);
            }
            sum = sum + curr - prev;
//            fmt::println("i={} curr={} prev={} sum={} freq={}", i, curr, prev, sum, freq);
            bool valid = true;
            if (freq[curr] == 1) {
                if (prevValid) {
                    valid = true;
                } else {
                    for (auto [k, v] : freq) {
                        if (v > 1) {
                            valid = false;
                            break;
                        }
                    }
                }
            } else {
                valid = false;
            }
            prevValid = valid;
            if (valid) {
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};


int main() {
    auto f = [](vector<int> &&nums, int k, long long expect) {
        auto output = Solution().maximumSubarraySum(nums, k);
        leetcode_assert(output == expect,
                        "maximum_sum_of_distinct_subarrays_with_length_k nums={} k={} expect={} output={}", nums, k,
                        expect, output);
    };
    f({1, 5, 4, 2, 9, 9, 9}, 3, 15);
}
