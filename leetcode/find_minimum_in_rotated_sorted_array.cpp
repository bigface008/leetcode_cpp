//
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
//

#include <vector>
#include "leetcode_utils.hpp"

using namespace std;

int doSomething(vector<int> &vec, int p, vector<int> &other) {

}

int findMin(vector<int> &nums) {
    int start = 0, end = nums.size() - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        int mid_val = nums[mid];
        int start_val = nums[start];
        int end_val = nums[end];
        if (mid != 0 && mid_val < nums[mid - 1]) {
            return mid_val;
        }
        if (start_val <= end_val) {
            return start_val;
        }
        if (mid_val >= start_val) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return nums[start];
}

int main() {
    auto f = [](vector<int> &&nums, int expect) {
        auto output = findMin(nums);
        leetcode_assert(output == expect, "find_minimum_in_rotated_sorted_array expect={} output={}", expect, output);
    };
    f({3, 4, 5, 1, 2}, 1);
    f({4, 5, 6, 7, 0, 1, 2}, 0);
    f({11, 13, 15, 17}, 11);
    f({2, 1}, 1);
    f({3, 1, 2}, 1);
}
