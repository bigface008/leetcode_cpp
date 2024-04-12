//
// https://leetcode.com/problems/dota2-senate/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

string predictPartyVictoryV2(string senate) {
    string radiant = "Radiant";
    string dire = "Dire";
    queue<int> dir_q;
    queue<int> rad_q;
    for (int i = 0; i < senate.size(); i++) {
        if (senate[i] == 'R') {
            rad_q.push(i);
        } else {
            dir_q.push(i);
        }
    }
    int n = senate.size();
    while (!dir_q.empty() && !rad_q.empty()) {
        if (dir_q.front() < rad_q.front()) {
            dir_q.push(n);
        } else {
            rad_q.push(n);
        }
        dir_q.pop();
        rad_q.pop();
        n++;
    }
    if (dir_q.empty()) {
        return radiant;
    } else {
        return dire;
    }
}

string predictPartyVictory(string senate) {
    string radiant = "Radiant";
    string dire = "Dire";
    int i = 0;
    while (senate.size() > 1) {
        int j = 0;
        bool ban = false;
        bool loop = false;
        for (; j < senate.size(); j++) {
            int index = i + j;
            if (index >= senate.size()) {
                index %= senate.size();
                loop = true;
            }
            if (senate[index] != senate[i]) {
                senate.erase(senate.begin() + index);
                ban = true;
                break;
            }
        }
        if (!ban) {
            break;
        }
        if (!loop) {
            i++;
        }
        if (i >= senate.size()) {
            i = 0;
        }
    }
    return senate[0] == 'R' ? radiant : dire;
}

int main() {
    auto f = [](string &&senate, string &&expect) {
        auto output = predictPartyVictory(senate);
        leetcode_assert(output == expect, "dota2_senate senate={} expect={} output={}", senate, expect, output);
    };
    f("RD", "Radiant");
    f("RDD", "Dire");
    f("DDRRR", "Dire");
    f("RRR", "Radiant");
    f("DRRDRDRDRDDRDRDR", "Radiant");
    f("DDRRRR", "Radiant");
}
