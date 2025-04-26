//
// https://leetcode.cn/problems/count-equal-and-divisible-pairs-in-an-array/?envType=daily-question&envId=2025-04-17
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        const int N = nums.size();
        unordered_map<int, vector<int>> pos_mp;
        for (int i = 0; i < N; i++) {
            pos_mp[nums[i]].push_back(i);
        }
        int ans = 0;
        for (auto &&[num, indices] : pos_mp) {
            if (indices.size() <= 1) {
                continue;
            }
            for (int i = 0; i < indices.size(); i++) {
                for (int j = i + 1; j < indices.size(); j++) {
                    if ((indices[i] * indices[j]) % k == 0) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};


class A {
    void *p1;
    void *p2;
//    uint32_t v1;

    virtual void foo() {
        fmt::println("foo");
    }
};

// 8 + 8 + 8 + 8 = 32
class B : public A {
    void *p2;
//    uint32_t v2;

    void foo() override {
        fmt::println("foo B");
    }
};

// 8 + 8 +

class BV : virtual public A {
    void foo() override {
        fmt::println("foo BV");
    }
};


int main() {
//    auto f = [](vector<int>&& nums, int k, int expect) {
//        auto output = Solution().countPairs(nums, k);
//        leetcode_assert(output == expect, "count_equal_and_divisible_pairs_in_an_array nums={} k={} expect={} output={}", nums, k, expect, output);
//    };
//    f();
    A a;
    B b;
    uint32_t v;
    BV bv;
    fmt::println("sizeof(A) = {} sizeof(B) = {} sizeof(v) = {} sizeof(bv) = {}", sizeof(a), sizeof(b), sizeof(v), sizeof(bv));


}
