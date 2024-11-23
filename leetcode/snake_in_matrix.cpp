//
// https://leetcode.cn/problems/snake-in-matrix/description/?envType=daily-question&envId=2024-11-21
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int r = 0, c = 0;
        for (string &cmd : commands) {
            if (cmd == "RIGHT") {
                c++;
            } else if (cmd == "DOWN") {
                r++;
            } else if (cmd == "UP") {
                r--;
            } else {
                c--;
            }
        }
        return n * r + c;
    }
};


int main() {
    auto f = [](int n, vector<string>&& commands, int expect) {
        auto output = Solution().finalPositionOfSnake(n, commands);
        leetcode_assert(output == expect, "snake_in_matrix n={} commands={} expect={} output={}", n, commands, expect, output);
    };
    f();
}
