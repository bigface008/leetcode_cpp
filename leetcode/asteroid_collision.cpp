//
// https://leetcode.com/problems/asteroid-collision/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids) {
    vector<int> stk;
    for (int asteriod : asteroids) {
        if (asteriod > 0) {
            stk.push_back(asteriod);
        } else {
            if (stk.empty()) {
                stk.push_back(asteriod);
            } else {
                int top = stk.back();
                if (top < 0) {
                    stk.push_back(asteriod);
                } else {
                    bool need_push = true;
                    do {
                        int top = stk.back();
                        if (top < -asteriod) {
                            stk.pop_back();
                        } else if (top == -asteriod) {
                            stk.pop_back();
                            need_push = false;
                            break;
                        } else {
                            need_push = false;
                            break;
                        }
                    } while (!stk.empty() && stk.back() > 0);
                    if (need_push) {
                        stk.push_back(asteriod);
                    }
                }
            }
        }
    }
    return stk;
}

int main() {
    auto f = [](vector<int> &&asteroids, vector<int> &&expect) {
        auto output = asteroidCollision(asteroids);
        bool same = equal(output.begin(), output.end(), expect.begin(), expect.end());
        leetcode_assert(same, "asteroid_collision asteroids={} expect={} output={}", asteroids, expect, output);
    };
    f({5, 10, -5}, {5, 10});
    f({8, -8}, {});
    f({10, 2, -5}, {10});
}
