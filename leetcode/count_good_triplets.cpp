//
// https://leetcode.cn/problems/count-good-triplets/description/?envType=daily-question&envId=2025-04-14
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        const int N = arr.size();
        int ans = 0;
        for (int j = 1; j < N - 1; j++) {
            for (int i = 0; i < j; i++) {
                for (int k = j + 1; k < N; k++) {
                    if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};


int main() {
    auto f = [](vector<int>&& arr, int a, int b, int c, int expect) {
        auto output = Solution().countGoodTriplets(arr, a, b, c);
        leetcode_assert(output == expect, "count_good_triplets arr={} a={} b={} c={} expect={} output={}", arr, a, b, c, expect, output);
    };
    f();
}
