//
// Created by 汪喆昊 on 2024/4/17.
//

#include "leetcode_utils.hpp"

using namespace std;

// N个城市，步行通过每个城市所需时间存储在time数组中。除了步行之外，用户也可以坐地铁，假设坐地
// 铁通过一个城市的时间一定为B，最多可以坐M次地铁，每次坐地铁最多通过K个城市。求通过所有城市的
// 时间的最小值。

int train_v2(int N, int K, vector<int> &time, int B, int M) {
    for (int i = 0; i < N; i++) {
        time[i] -= B;
    }
    vector<int> vec_sum;
    int window_sum = 0;
    for (int i = 0; i < K; i++) {
        window_sum += time[i];
    }
    const int window_cnt = N - K + 1;
    for (int i = 0; i < window_cnt; i++) {
        vec_sum.push_back(window_sum);
        if (i != window_cnt - 1) {
            window_sum = window_sum - time[i] + time[i + K];
        }
    }
}

int test_train() {
    //    vector<int> time{3, 7, 5, 3, 6};
    //    int res = train_v2(5, 1, time, 0, 2);
    //    fmt::println("{}", res == 11);
    priority_queue<int> pq;
    pq.push(12);
    pq.push(12);
    fmt::println("{}", pq);
}

// 给你一个整数数组 nums 和一个整数 k ，编写一个函数来判断该数组是否含有同时满足下述条件的连续子数组：
// 子数组大小 至少为 2 ，且
// 子数组元素总和为 k 的倍数。
// 如果存在，返回 true ；否则，返回 false 。

bool check_sum_mod_k(vector<int> &nums, int K) {
    const int N = nums.size();
    if (N == 0) {
        return false;
    }
    map<int, int> mp;
    vector<int> vec(N, 0);
    int curr_sum = 0;
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            curr_sum = nums[i];
        } else {
            curr_sum += nums[i];
        }
        int curr_mod = curr_sum % K;
        auto it = mp.find(curr_mod);
        if (it != mp.end()) {
            if (i - it->second > 1) {
                return true;
            }
        } else {
            mp[curr_mod] = i;
        }
    }
    return false;
}

void test_sum_mod_k() {
    auto f = [](vector<int> &&nums, int K, bool expect) {
        bool output = check_sum_mod_k(nums, K);
        leetcode_assert(output == expect, "Check Mod Sum nums={} K={} expect={} output={}", nums, K, expect, output);
    };
    f({23, 2, 4, 6, 7}, 6, true);
    f({23, 2, 6, 4, 7}, 13, false);
}

int main() {
//    test_sum_mod_k();
//    fmt::println("{}", INT_MAX);
//    fmt::println("{}", UINT_MAX);
    priority_queue<int> pq;
    pq.push(12);
    pq.push(12);
    pq.push(13);
    pq.push(12);
    fmt::println("{}", pq);
}
