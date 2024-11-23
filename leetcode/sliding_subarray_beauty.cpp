//
// https://leetcode.cn/problems/sliding-subarray-beauty/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x) {
        const int N = nums.size();
        vector<int> freqMap(LEN, 0);
        for (int i = 0; i < k; i++) {
            freqMap[getIdx(nums[i])]++;
        }
        vector<int> ans(N - k + 1, 0);
        ans[0] = getX(freqMap, x);
        ans[0] = getX(freqMap, x);
        for (int i = k; i < N; i++) {
            int curr = nums[i], prev = nums[i - k];
            freqMap[getIdx(curr)]++;
            freqMap[getIdx(prev)]--;
            ans[i - k + 1] = getX(freqMap, x);
        }
        return ans;
    }

private:
    static const int DIST = 50;
    static const int LEN = 2 * DIST + 1;

    int getIdx(int val) {
        return val + DIST;
    }

    int getX(vector<int> &freqMap, int x) {
        for (int val = -DIST; val < 0; val++) {
            x -= freqMap[getIdx(val)];
            if (x <= 0) {
                return val;
            }
        }
        return 0;
    }
};

class Solution3 {
public:
    vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x) {
        const int N = nums.size();
        map<int, int> freqMap;
        for (int i = 0; i < k; i++) {
            freqMap[nums[i]]++;
        }
        vector<int> ans(N - k + 1, 0);
        ans[0] = getX(freqMap, x);
        for (int i = k; i < N; i++) {
            int curr = nums[i], prev = nums[i - k];
            freqMap[curr]++;
            if (freqMap[prev] == 0) {
                freqMap.erase(prev);
            } else {
                freqMap[prev]--;
            }
            ans[i - k + 1] = getX(freqMap, x);
        }
        return ans;
    }

private:
    int getX(map<int, int> &freqMap, int x) {
        int i = 0;
        for (auto &p : freqMap) {
            i += p.second;
            if (p.first >= 0) {
                return 0;
            }
            if (i >= x) {
                return p.first;
            }
        }
        return 0;
    }
};

class Solution2 {
public:
    vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x) {
        const int N = nums.size();
        x--;
        multiset<int> freqSet;
        for (int i = 0; i < k; i++) {
            freqSet.insert(nums[i]);
        }
        vector<int> ans(N - k + 1, 0);
        int val = *(next(freqSet.begin(), x));
        ans[0] = val < 0 ? val : 0;
        for (int i = k; i < N; i++) {
            freqSet.insert(nums[i]);
            freqSet.erase(freqSet.find(nums[i - k]));
            val = *(next(freqSet.begin(), x));
            ans[i - k + 1] = val < 0 ? val : 0;
        }
        return ans;
    }
};


int main() {
    auto f = [](vector<int> &&nums, int k, int x, vector<int> expect) {
        auto output = Solution().getSubarrayBeauty(nums, k, x);
        leetcode_assert(output == expect, "sliding_subarray_beauty nums={} k={} x={} expect={} output={}", nums, k, x,
                        expect, output);
    };
    f({1, -1, -3, -2, 3}, 3, 2, {-1, -2, -2});
    //    f({-3, 1, 2, -3, 0, -3}, 2, 1, {-3, 0, -3, -3, -3});
    //    multiset<int> st;
    //    st.insert(-3);
    //    st.insert(0);
    //    fmt::println("{}", st);
    //    st.insert(-3);
    //    fmt::println("{}", st);
    //    st.erase(-3);
    //    fmt::println("{}", st);
}
