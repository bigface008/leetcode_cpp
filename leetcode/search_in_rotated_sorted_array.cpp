//
// https://leetcode.com/problems/search-in-rotated-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

int search(vector<int> &nums, int target) {
    int start = 0, end = nums.size() - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        int start_val = nums[start];
        int mid_val = nums[mid];
        int end_val = nums[end];
        if (mid_val == target) {
            return mid;
        }
        if (start_val < end_val) {
            if (target > mid_val) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        } else {
            if (end_val > mid_val) {
                if (target > mid_val) {
                    if (target == start_val) {
                        return start;
                    } else if (target > start_val) {
                        end = mid - 1;
                    } else {
                        start = mid + 1;
                    }
                } else {
                    end = mid - 1;
                }
            } else {
                if (target > mid_val) {
                    start = mid + 1;
                } else {
                    if (target == start_val) {
                        return start;
                    } else if (target > start_val) {
                        end = mid - 1;
                    } else {
                        start = mid + 1;
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    auto f = [](vector<int> &&nums, int target, int expect) {
        auto output = search(nums, target);
        leetcode_assert(output == expect, "search_in_rotated_sorted_array nums={} target={} expect={} output={}", nums,
                        target, expect, output);
    };
    f({4, 5, 6, 7, 0, 1, 2}, 0, 4);
    f({4, 5, 6, 7, 0, 1, 2}, 3, -1);
    f({1}, 0, -1);
    f({1, 3}, 3, 1);
    f({3, 5, 1}, 3, 0);
}
