//
// https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/description/?envType=daily-question&envId=2024-11-14
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int minimizedMaximum(int n, vector<int> &quantities) {
        int start = 1, end = *max_element(quantities.begin(), quantities.end());

        auto isValid = [&](int K) {
            int cnt = 0;
            for (int q : quantities) {
                int div = q / K;
                int remain = q % K;
                cnt += remain == 0 ? div : (div + 1);
            }
            return cnt <= n;
        };

        while (start <= end) {
            int mid = (start + end) / 2;
            if (isValid(mid)) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};

int main() {
//    auto f = [](int n, vector<int> &&quantities, int expect) {
//        auto output = Solution().minimizedMaximum(n, quantities);
//        leetcode_assert(output == expect,
//                        "minimized_maximum_of_products_distributed_to_any_store n={} quantities={} expect={} output={}",
//                        n, quantities, expect, output);
//    };
//    f(6, {11, 6}, 3);
    vector<int> v0{1, 2, 3, 3, 3, 3, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v1{1, 2, 3, 3, 3, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v2{1, 2, 3, 3, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v3{1, 2, 3, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v4{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v5{2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v6{3, 4, 5, 6, 7, 8, 9, 10};

    auto valid1 = [=](vector<int> &vec, int idx) {
        return vec[idx] >= 3;
    };

    auto bs1 = [=](vector<int> &vec) {
        int start = 0, end = vec.size() - 1;
        int ans = 0;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (valid1(vec, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        fmt::println("bs1 vec={} ans={} start={} end={}", vec, ans, start, end);
        return start;
    };
    bs1(v0);
    bs1(v1);
    bs1(v2);
    bs1(v3);
    bs1(v4);
    bs1(v5);
    bs1(v6);
}
