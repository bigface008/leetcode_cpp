//
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

vector<int> searchRange(vector<int> &nums, int target) {
    int start = 0, end = nums.size() - 1;
    int open_index = -1;
    while (start <= end) {
        int mid = (start + end) / 2;
        int val = nums[mid];
        if (val == target) {
            if (mid == 0 || nums[mid - 1] != target) {
                open_index = mid;
                break;
            }
            end = mid - 1;
        } else if (val < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    start = 0;
    end = nums.size() - 1;
    int close_index = -1;
    while (start <= end) {
        int mid = (start + end) / 2;
        int val = nums[mid];
        if (val == target) {
            if (mid == nums.size() - 1 || nums[mid + 1] != target) {
                close_index = mid;
                break;
            }
            start = mid + 1;
        } else if (val < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return {open_index, close_index};
}

int main() {
    auto f = [](vector<int> &&nums, int target, vector<int> expect) {
        auto output = searchRange(nums, target);
        bool same = equal(output.begin(), output.end(), expect.begin(), expect.end());
        leetcode_assert(output == expect, "search range nums={} target={} expect={} output={}", nums, target, expect,
                        output);
    };
    f({5, 7, 7, 8, 8, 10}, 8, {3, 4});
    f({5, 7, 7, 8, 8, 10}, 6, {-1, -1});
    f({}, 0, {-1, -1});
    f({2, 2}, 2, {0, 1});
}
