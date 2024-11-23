//
// https://leetcode.com/problems/search-insert-position/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        const int N = nums.size();
        int start = 0, end = N - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] >= target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};

int searchInsert(vector<int> &nums, int target) {
    int start = 0, end = nums.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        int val = nums[mid];
        if (val == target) {
            return mid;
        } else if (target > val) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return start;
}

int binarySearch(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (target == nums[mid]) {
            return mid;
        }
        if (target > nums[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    auto f = [](vector<int> &&nums, int target, int expect) {
        auto output = searchInsert(nums, target);
        leetcode_assert(output == expect, "search_insert_position nums={} target={} expect={} output={}", nums, target,
                        expect, output);
    };
    f({1, 3, 5, 6}, 5, 2);
    f({1, 3, 5, 6}, 2, 1);
    f({1, 3, 5, 6}, 7, 4);
}
