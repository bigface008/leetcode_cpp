//
// https://leetcode.com/problems/find-the-difference-of-two-arrays/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> st1(nums1.begin(), nums1.end());
        set<int> st2(nums2.begin(), nums2.end());
        vector<int> diff1;
        set_difference(st1.begin(), st1.end(), st2.begin(), st2.end(), back_inserter(diff1));
        vector<int> diff2;
        set_difference(st2.begin(), st2.end(), st1.begin(), st1.end(), back_inserter(diff2));
        return {diff1, diff2};
    }
};


int main() {
    auto f = [](vector<int>&& nums1, vector<int>&& nums2, vector<vector<int>> expect) {
        auto output = Solution().findDifference(nums1, nums2);
        leetcode_assert(output == expect, "find_the_difference_of_two_arrays nums1={} nums2={} expect={} output={}", nums1, nums2, expect, output);
    };
    f();
}
