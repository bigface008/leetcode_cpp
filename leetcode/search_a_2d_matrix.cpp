//
// https://leetcode.com/problems/search-a-2d-matrix/description/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
        return false;
    }
    const int M = matrix.size(), N = matrix[0].size();
    int start = 0, end = M * N - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        int row = mid / N;
        int col = mid % N;
        int val = matrix[row][col];
        if (val == target) {
            return true;
        } else if (val > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
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
    f({{1, 3}}, 3, true);
}
