//
// https://leetcode.com/problems/keys-and-rooms/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

void dfs(int i, int &remain_cnt, bool &res, vector<vector<int>> &rooms, vector<bool> &visited) {
    if (res) {
        return;
    }
    if (visited[i]) {
        return;
    }
    remain_cnt--;
    if (remain_cnt <= 0) {
        res = true;
        return;
    }
    visited[i] = true;
    auto &keys = rooms[i];
    for (auto key : keys) {
        dfs(key, remain_cnt, res, rooms, visited);
    }
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    bool res = false;
    int remain_cnt = rooms.size();
    vector<bool> visited(rooms.size(), false);
    dfs(0, remain_cnt, res, rooms, visited);
    return res;
}

int main() {
    auto f = [](vector<vector<int>> &&rooms, bool expect) {
        auto output = canVisitAllRooms(rooms);
        leetcode_assert(output == expect, "keys_and_rooms rooms={} expect={} output={}", rooms, expect, output);
    };
    f(make2DIntVecByStr("[[1],[2],[3],[]]"), true);
    f(make2DIntVecByStr("[[1,3],[3,0,1],[2],[0]]"), false);
    f(make2DIntVecByStr("[[2,3],[],[2],[1,3]]"), true);
}
