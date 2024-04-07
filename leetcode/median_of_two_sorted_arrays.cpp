//
// https://leetcode.com/problems/median-of-two-sorted-arrays/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

double median(vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    } else {
        if (nums.size() % 2 == 0) {
            return (double)(nums[nums.size() / 2] + nums[nums.size() / 2 - 1]) / 2;
        } else {
            return (double)nums[nums.size() / 2];
        }
    }
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.empty()) {
        return median(nums2);
    }
    if (nums2.empty()) {
        return median(nums1);
    }
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }

    const int M = nums1.size(), N = nums2.size();
    int low = 0, high = M;
    int mid1 = 0, mid2 = 0;
    int half = (M + N + 1) / 2;
    while (low <= high) {
        mid1 = (low + high) / 2;
        mid2 = half - mid1;
        if (mid1 > 0 && nums1[mid1 - 1] > nums2[mid2]) {
            high = mid1 - 1;
        } else if (mid1 < M && nums1[mid1] < nums2[mid2 - 1]) {
            low = mid1 + 1;
        } else {
            break;
        }
    }

    int mid_left = 0, mid_right = 0;
    if (mid1 == 0) {
        mid_left = nums2[mid2 - 1];
    } else if (mid2 == 0) {
        mid_left = nums1[mid1 - 1];
    } else {
        mid_left = max(nums1[mid1 - 1], nums2[mid2 - 1]);
    }
    if ((M + N) % 2 != 0) {
        return double(mid_left);
    }
    if (mid1 == M) {
        mid_right = nums2[mid2];
    } else if (mid2 == N) {
        mid_right = nums1[mid1];
    } else {
        mid_right = min(nums1[mid1], nums2[mid2]);
    }
    return double(mid_left + mid_right) / 2;
}

int main() {
    auto f = [](vector<int> &&nums1, vector<int> &&nums2, double expect) {
        auto output = findMedianSortedArrays(nums1, nums2);
        leetcode_assert(output == expect, "median_of_two_sorted_arrays nums1={} nums2={} expect={} output={}", nums1,
                        nums2, expect, output);
    };
    f({1, 3}, {2}, 2.0);
    f({1, 2}, {3, 4}, 2.5);
}
