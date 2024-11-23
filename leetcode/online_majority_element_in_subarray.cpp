//
// https://leetcode.cn/problems/online-majority-element-in-subarray/
//

#include "leetcode_utils.hpp"

using namespace std;

class MajorityChecker {
public:
    MajorityChecker(vector<int>& arr) {
        tree.resize(2 << (32 - __builtin_clz(arr.size())));
    }
    
    int query(int left, int right, int threshold) {
        return 0;
    }

private:
    vector<int> tree;

    void build(int p, int start, int end, vector<int>& arr) {
//        tree[p] =
    }
};


int main() {
//    auto f = [](vector<int>&& arr, MajorityChecker(vector<int>& arr) expect) {
//        auto output = MajorityChecker(arr);
//        leetcode_assert(output == expect, "online_majority_element_in_subarray arr={} expect={} output={}", arr, expect, output);
//    };
//    f();
}
