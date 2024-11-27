//
// https://leetcode.com/problems/can-place-flowers/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int prevOne = -1;
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 1) {
                if (prevOne == -1) {
                    n -= i / 2;
                } else {
                    n -= (i - prevOne) / 2 - 1;
                }
                prevOne = i;
            }
            if (n <= 0) {
                return true;
            }
        }
        if (prevOne == -1) {
            n -= (flowerbed.size() + 1) / 2;
        } else if (prevOne != flowerbed.size() - 1) {
            n -= (flowerbed.size() - 1 - prevOne) / 2;
        }
        return n <= 0;
    }
};


int main() {
    auto f = [](vector<int>&& flowerbed, int n, bool expect) {
        auto output = Solution().canPlaceFlowers(flowerbed, n);
        leetcode_assert(output == expect, "can_place_flowers flowerbed={} n={} expect={} output={}", flowerbed, n, expect, output);
    };
    f({0}, 1, true);
}
