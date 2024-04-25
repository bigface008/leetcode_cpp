//
// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {

}

int main() {
    auto f = [](vector<vector<int>> &&points, int expect) {
        auto output = findMinArrowShots(points);
        leetcode_assert(output == expect, "minimum_number_of_arrows_to_burst_balloons points={} expect={} output={}", points, expect, output);
    };
    f(make2DIntVecByStr("[[10,16],[2,8],[1,6],[7,12]]"), 2);
    f(make2DIntVecByStr("[[1,2],[3,4],[5,6],[7,8]]"), 4);
    f(make2DIntVecByStr("[[1,2],[2,3],[3,4],[4,5]]"), 2);
}
