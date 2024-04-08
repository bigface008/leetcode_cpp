//
// https://leetcode.com/problems/minimum-genetic-mutation/description/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

int minMutation(string startGene, string endGene, vector<string> &bank) {
    queue<string> q;
    unordered_set<string> visited;
    q.push(startGene);
    int step = 0;
    while (!q.empty()) {
        int level_size = q.size();
        for (int i = 0; i < level_size; i++) {
            auto str = q.front();
            q.pop();
            if (str == endGene) {
                return step;
            }
            if (visited.contains(str)) {
                continue;
            }
            visited.insert(str);
            for (auto &gene : bank) {
                int diff_cnt = 0;
                for (int j = 0; j < gene.size(); j++) {
                    if (gene[j] != str[j]) {
                        diff_cnt++;
                    }
                    if (diff_cnt > 1) {
                        break;
                    }
                }
                if (diff_cnt == 1) {
                    q.push(gene);
                }
            }
        }
        step++;
    }
    return -1;
}

int main() {
    auto f = [](string &&startGene, string &&endGene, vector<string> &&bank, int expect) {
        int output = minMutation(startGene, endGene, bank);
        leetcode_assert(output == expect, "min mutation startGene={} endGene={} bank={} expect={} output={}", startGene,
                        endGene, bank, expect, output);
    };

    f("AACCGGTT", "AACCGGTA", {"AACCGGTA"}, 1);
    f("AACCGGTT", "AAACGGTA", {"AACCGGTA", "AACCGCTA", "AAACGGTA"}, 2);
}
