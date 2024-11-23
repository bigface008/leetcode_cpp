//
// https://leetcode.cn/problems/find-the-distance-value-between-two-arrays/description/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int ans = 0;
        for (int x : arr1) {
            int low = x - d, high = x + d;
            if (high < arr2.front() || low > arr2.back()) {
                ans++;
                continue;
            }
            int start = 0, end = arr2.size() - 1;
            bool valid = true;
            while (start <= end) {
                int mid = start + (end - start) / 2;
                int x = arr2[mid];
                if (x >= low && x <= high) {
                    valid = false;
                    break;
                } else if (x < low) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            if (valid) {
                ans++;
            }
        }
        return ans;
    }
};


int main() {
    auto f = [](vector<int> &&arr1, vector<int> &&arr2, int d, int expect) {
        auto output = Solution().findTheDistanceValue(arr1, arr2, d);
        leetcode_assert(output == expect,
                        "find_the_distance_value_between_two_arrays arr1={} arr2={} d={} expect={} output={}", arr1,
                        arr2, d, expect, output);
    };
    f({4, 5, 8}, {10, 9, 1, 8}, 2, 2);
}
