//
// Created by 汪喆昊 on 2024/4/12.
//

#include "leetcode_utils.hpp"

using namespace std;

// 记录 DTL 的笔试算法题。

// 1. 给定一个数组，一个整型x，求所有长度为x的子数组中的最小值的最大值，要求最优算法。

int maxMinGroupMember(int x, vector<int> &vec) {
    priority_queue<int, vector<int>, greater<>> min_heap;
    int ans = INT_MIN;
    for (int i = 0; i < x; i++) {
        min_heap.push(vec[i]);
    }
    ans = max(ans, min_heap.top());
    for (int i = x; i < vec.size(); i++) {
        int drop_val = vec[i - x];
        int val = vec[i];
        if (drop_val == min_heap.top()) {
            min_heap.pop();
        }
        min_heap.push(val);
        ans = max(ans, min_heap.top());
    }
    return ans;
}

void testQ1() {
    vector<int> v{8, 2, 4, 6};
    int res = maxMinGroupMember(2, v);
    fmt::println("q1 {}", res);
}

// 2. 一个树，求其中path里各节点的值的和的最大值（path可以不经过根节点），树的表示是两个等长vector，一个vector表示
// 各节点的值，另一个表示其父节点的索引。

int treeMinSum(vector<int> &parent, vector<int> &values) { return 0; }

// 3. 两个字符串，求在第二个字符串中找到所有和第一个字符串有着相同字母以及字母顺序的、可不连续的子串的个数。

void backtrack(int i, int min_j, int &count, const int M, const int N, const string &s1, map<char, vector<int>> &s2mp,
               vector<bool> &visited) {
    if (i == M) {
        count++;
        return;
    }
    char c = s1[i];
    auto it = s2mp.find(c);
    if (it == s2mp.end() || it->second.empty()) {
        return;
    }
    for (int index : it->second) {
        if (!visited[index] && index >= min_j) {
            visited[index] = true;
            backtrack(i + 1, index + 1, count, M, N, s1, s2mp, visited);
            visited[index] = false;
        }
    }
}

int countSubStr(string s1, string s2) {
    const int M = s1.size(), N = s2.size();
    map<char, vector<int>> s2mp;
    vector<bool> visited(N, false);
    for (int i = 0; i < M; i++) {
        s2mp[s2[i]].push_back(i);
    }
    int ans = 0;
    backtrack(0, 0, ans, M, N, s1, s2mp, visited);
    return ans;
}

int main() { testQ1(); }
