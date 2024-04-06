//
// https://leetcode.com/problems/search-a-2d-matrix/description/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target) {

    return false;
}

int main() {
    auto f = [](vector<vector<int>> &&matrix, int target, bool expect) {
        auto output = searchMatrix(matrix, target);
        leetcode_assert(output == expect, "search_a_2d_matrix matrix={} target={} expect={} output={}", matrix, target,
                        expect, output);
    };
    f({{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}, 3, true);
    f({{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}, 13, false);
}
