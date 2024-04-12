//
// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

int minReorder(int n, vector<vector<int>>& connections) {
    return 0;
}


int main() {
//    auto f = [](int n, vector<vector<int>> &&connections, int expect) {
//        auto output = minReorder(n, connections);
//        leetcode_assert(output == expect, "reorder_routes_to_make_all_paths_lead_to_the_city_zero n={} connections={} expect={} output={}", n, connections, expect, output);
//    };
//    f(6, make2DIntVecByStr("[[0,1],[1,3],[2,3],[4,0],[4,5]]"), 3);
//    f(5, make2DIntVecByStr("[[1,0],[1,2],[3,2],[3,4]]"), 2);
//    f(3, make2DIntVecByStr("[[1,0],[2,0]]"), 0);
    Base b1 = Derived();
    b1.who();

    Base b3;
    b3.who();

    Base *b2 = new Derived();
    b2->who();
    delete b2;
}
