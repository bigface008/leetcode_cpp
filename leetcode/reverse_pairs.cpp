//
// https://leetcode.com/problems/reverse-pairs/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int reversePairs(vector<int> &nums) { return dfs(nums, 0, nums.size() - 1); }

private:
    int dfs(vector<int> &nums, int start, int end) {
        if (start == end) {
            return 0;
        }
        if (start + 1 == end) {
            int ans = 0;
            if (isValid(nums, start, end)) {
                ans++;
            }
            if (nums[start] > nums[end]) {
                int tmp = nums[start];
                nums[start] = nums[end];
                nums[end] = tmp;
            }
            return ans;
        }
        int mid = (start + end) / 2;
        int ans = dfs(nums, start, mid) + dfs(nums, mid + 1, end);
        int i = start, j = mid + 1;
        while (i <= mid) {
            while (j <= end && isValid(nums, i, j)) {
                j++;
            }
            ans += j - (mid + 1);
            i++;
        }
        i = start;
        j = mid + 1;
        vector<int> vec(end - start + 1, 0);
        int k = 0;
        while (i <= mid && j <= end) {
            if (nums[i] < nums[j]) {
                vec[k] = nums[i];
                i++;
            } else {
                vec[k] = nums[j];
                j++;
            }
            k++;
        }
        while (i <= mid) {
            vec[k] = nums[i];
            i++;
            k++;
        }
        while (j <= end) {
            vec[k] = nums[j];
            j++;
            k++;
        }
        for (int k = 0; k < vec.size(); k++) {
            nums[k + start] = vec[k];
        }
        return ans;
    }

    bool isValid(vector<int> &nums, int i, int j) {
        long a = nums[i];
        long b = nums[j];
        if (a == b) {
            return a < 0;
        }
        return a > 2 * b;
    }
};

int main() {
//    auto f = [](vector<int> &&nums, int expect) {
//        auto output = Solution().reversePairs(nums);
//        leetcode_assert(output == expect, "reverse_pairs nums={} expect={} output={}", nums, expect, output);
//    };
//    //    f({1, 3, 2, 3, 1}, 2);
//    //    f({5, 4, 3, 2, 1}, 4);
//    f({2147483647, 2147483647, -2147483647, -2147483647, -2147483647, 2147483647}, 9);
    bitset<32> bits(6);
    bits.flip();
    fmt::println("{}", bits.to_string());
//    fmt::println("{}", bits.count());
//    fmt::println("{}", bits.size());
//    fmt::println("{}", __builtin_clz(6));
//    fmt::println("{}", 32 - __builtin_clz(6));
//    fmt::println("{}", __builtin_ctz(6));
}
