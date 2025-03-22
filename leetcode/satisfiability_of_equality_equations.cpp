//
// https://leetcode.cn/problems/satisfiability-of-equality-equations/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        parents.resize(26);
        iota(parents.begin(), parents.end(), 0);
        ranks.resize(26);

        vector<pair<int, int>> notEqualPairs;
        for (string &eq : equations) {
            int a = eq[0] - 'a';
            int b = eq[3] - 'a';
            if (eq[1] == '=') {
                merge(a, b);
            } else {
                notEqualPairs.emplace_back(a, b);
            }
        }
        for (auto [a, b] : notEqualPairs) {
            if (findParent(a) == findParent(b)) {
                return false;
            }
        }
        return true;
    }

private:
    vector<int> parents;
    vector<int> ranks;

    void merge(int a, int b) {
        int pa = findParent(a);
        int pb = findParent(b);
        if (pa == pb) {
            return;
        }
        if (ranks[pa] > ranks[pb]) {
            parents[pb] = pa;
        } else if (ranks[pa] < ranks[pb]) {
            parents[pa] = pb;
        } else {
            parents[pb] = pa;
            ranks[pa] += 1;
        }
    }

    int findParent(int a) {
        while (parents[a] != a) {
            parents[a] = parents[parents[a]];
            a = parents[a];
        }
        return a;
    }
};


int main() {
    auto f = [](vector<string>&& equations, bool expect) {
        auto output = Solution().equationsPossible(equations);
        leetcode_assert(output == expect, "satisfiability_of_equality_equations equations={} expect={} output={}", equations, expect, output);
    };
    f();
}
