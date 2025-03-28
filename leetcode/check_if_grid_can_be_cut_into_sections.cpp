//
// https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/
//

#include "leetcode_utils.hpp"
#include <iostream>

using namespace std;

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        sort(rectangles.begin(), rectangles.end(), [&](auto &r1, auto &r2) {
            if (r1[0] < r2[0]) {
                return true;
            }
            if (r1[0] > r2[0]) {
                return false;
            }
            if (r1[2] < r2[2]) {
                return true;
            }
            return false;
        });
        int rightMost = rectangles[0][2];
        bool is1stValid = false;
        bool is2ndValid = false;
        for (int i = 1; i < rectangles.size(); i++) {
            vector<int> &rect = rectangles[i];
            int startX = rect[0], endX = rect[2];
            if (startX >= rightMost) {
                if (!is1stValid) {
                    is1stValid = true;
                } else {
                    if (!is2ndValid) {
                        is2ndValid = true;
                    }
                }
            }
            rightMost = max(rightMost, endX);
        }
        if (is1stValid && is2ndValid) {
            return true;
        }

        sort(rectangles.begin(), rectangles.end(), [&](auto &r1, auto &r2) {
            if (r1[1] < r2[1]) {
                return true;
            }
            if (r1[1] > r2[1]) {
                return false;
            }
            if (r1[3] < r2[3]) {
                return true;
            }
            return false;
        });
        int topMost = rectangles[0][3];
        is1stValid = false;
        is2ndValid = false;
        for (int i = 1; i < rectangles.size(); i++) {
            vector<int> &rect = rectangles[i];
            int startY = rect[1], endY = rect[3];
            if (startY >= topMost) {
                if (!is1stValid) {
                    is1stValid = true;
                } else {
                    if (!is2ndValid) {
                        is2ndValid = true;
                    }
                }
            }
            topMost = max(topMost, endY);
        }
        if (is1stValid && is2ndValid) {
            return true;
        }
        return false;
    }
};

class MyException : public std::exception {
private:
    string msg;

public:
    explicit MyException(const string &m) : msg(m) {}

    const char * what() const noexcept override {
        return msg.c_str();
    }
};

int main() {
//    auto f = [](int n, vector<vector<int>>&& rectangles, bool expect) {
//        auto output = Solution().checkValidCuts(n, rectangles);
//        leetcode_assert(output == expect, "check_if_grid_can_be_cut_into_sections n={} rectangles={} expect={} output={}", n, rectangles, expect, output);
//    };
//    f();
    vector<int> v{1, 2, 3, 4, 5, 6};
    try {
//        int res = v.at(7);
//        fmt::println("just we res={}", res);
        throw MyException("just we");
    } catch (std::exception &err) {
        std::cerr << err.what() << std::endl;
    }
}
