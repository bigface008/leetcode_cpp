//
// https://leetcode.com/problems/maximum-subsequence-score/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

long long maxScore(vector<int> &nums1, vector<int> &nums2, int k) {
    long long ans = 0;
    return ans;
}

class Demo {
public:
    Demo() {
        fmt::println("init!");
    }
};

class Base {
public:
    Base(int x) {
        a = x;
    }
    int a;
    virtual void draw() = 0;
};

class Dervied : public Base {
public:
    Dervied(int x, int y) : Base(x) {
        c = y;
    }
    int c;
    void draw() override {
        fmt::println("dude a={} c={}", a, c);
    }
};

//class OpTest {
//    OpTest operator++() {
//        return 0;
//    }
//};

int main() {
//    auto f = [](vector<int> &&nums1, vector<int> &&nums2, int k, long expect) {
//        auto output = maxScore(nums1, nums2, k);
//        leetcode_assert(output == expect, "maximum_subsequence_score nums1={} nums2={} k={} expect={} output={}", nums1,
//                        nums2, k, expect, output);
//    };
//    f({1, 3, 3, 2}, {2, 1, 3, 4}, 3, 12);
//    f({4, 2, 3, 1, 1}, {7, 5, 10, 9, 6}, 1, 30);
//    fmt::println("man!");
//    static Demo d = Demo();
////    static Demo *d = new Demo();
//    fmt::println("end");
    Dervied d1(13, 12);
    Base &b1 = d1;
    b1.draw();
}
