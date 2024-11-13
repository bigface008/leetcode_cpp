//
// https://leetcode.com/problems/prime-subtraction-operation/description/?envType=daily-question&envId=2024-11-11
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    bool primeSubOperation(vector<int> &nums) {
        const int N = nums.size();
        for (int i = N - 2; i >= 0; i--) {
            int x = nums[i];
            int next = nums[i + 1];
            if (x < next) {
                continue;
            }
            int newX = next - 1;
            bool find = false;
            while (newX > 0) {
                if (isPrime(x - newX)) {
                    find = true;
                    break;
                }
                newX--;
            }
            if (!find) {
                return false;
            }
            nums[i] = newX;
        }
        return true;
    }

private:
    bool isPrime(int num) {
        if (num < 2) {
            return false;
        }
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    auto f = [](vector<int> &&nums, bool expect) {
        vector<int> tmp(nums);
        auto output = Solution().primeSubOperation(tmp);
        leetcode_assert(output == expect, "prime_subtraction_operation nums={} expect={} output={}", nums, expect,
                        output);
    };
    //    f({5, 8, 3}, false);
    //     11 3 6
    f({18, 12, 14, 6}, false);
}
