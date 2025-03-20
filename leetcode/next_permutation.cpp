//
// https://leetcode.cn/problems/next-permutation/
//

#include "leetcode_utils.hpp"

using namespace std;


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        const int N = nums.size();
        int i = N - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = N - 1;
            while (nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        i++;
        int j = N - 1;
        while (i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};

//class Solution {
//public:
//    void nextPermutation(vector<int>& nums) {
//        const int N = nums.size();
//        int i = N - 2, j = N - 1, k = N - 1;
//        while (i >= 0 && nums[i] >= nums[j]) {
//            i--;
//            j--;
//        }
//        if (i >= 0) {
//            while (nums[i] >= nums[k]) {
//                k--;
//            }
//            int temp = nums[i];
//            nums[i] = nums[k];
//            nums[k] = temp;
//        }
//        i = j;
//        j = N - 1;
//        while (i < j) {
//            int temp = nums[i];
//            nums[i] = nums[j];
//            nums[j] = temp;
//            i++;
//            j--;
//        }
//    }
//};


int main() {
    vector<int> a{1, 2, 3, 4};
    swap(a[0], a[1]);
    fmt::println("a={}", a);
}
