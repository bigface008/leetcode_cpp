//
// Created by 汪喆昊 on 2024/3/29.
// https://leetcode.com/problems/word-search/description/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

bool is_connected(pair<int, int> &p1, pair<int, int> &p2) {
    if (p1.first == p2.first) {
        return p1.second == p2.second + 1 || p1.second == p2.second - 1;
    } else if (p1.second == p2.second) {
        return p1.first == p2.first + 1 || p1.first == p2.first - 1;
    } else {
        return false;
    }
}

bool backtrack(map<char, vector<pair<int, int>>> &board_map, int index, string &path, pair<int, int> &pos,
               vector<vector<bool>> &visited) {
    if (index >= path.size()) {
        return true;
    }
    bool res = true;
    char c = path[index];
    auto curr_it = board_map.find(c);
    if (curr_it == board_map.end()) {
        return false;
    }
    for (auto &p : curr_it->second) {
        if (is_connected(p, pos) && !visited[p.first][p.second]) {
            visited[p.first][p.second] = true;
            if (backtrack(board_map, index + 1, path, p, visited)) {
                return true;
            }
            visited[p.first][p.second] = false;
        }
    }
    return false;
}

bool exist(vector<vector<char>> &board, string word) {
    if (word.empty() || board.empty()) {
        return false;
    }
    bool res = false;
    map<char, vector<pair<int, int>>> board_map;
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));
    for (int i = 0; i < board.size(); ++i) {
        auto &row = board[i];
        for (int j = 0; j < row.size(); ++j) {
            char c = row[j];
            board_map[c].emplace_back(i, j);
        }
    }

    auto it = board_map.find(word[0]);
    if (it == board_map.end()) {
        return false;
    }
    for (auto &p : it->second) {
        visited[p.first][p.second] = true;
        bool connected = backtrack(board_map, 1, word, p, visited);
        if (connected) {
            return true;
        }
        visited[p.first][p.second] = false;
    }
    return false;
}

int main() {
    auto f = [](vector<vector<char>> &&board, string &&word, bool expect) {
        auto output = exist(board, word);
        leetcode_assert(output == expect, "word search board={} word={} output={} expect={}", board, word, output,
                        expect);
    };
    f({{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}}, "ABCCED", true);
    f({{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}}, "SEE", true);
    f({{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}}, "ABCB", false);
}
