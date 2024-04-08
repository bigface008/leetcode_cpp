//
// https://leetcode.com/problems/word-ladder/description/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    queue<string> q;
    q.push(beginWord);
    unordered_set<string> visited;
    int step = 0;
    while (!q.empty()) {
        int level_size = q.size();
        for (int i = 0; i < level_size; i++) {
            auto curr_word = q.front();
            q.pop();
            if (curr_word == endWord) {
                return step + 1;
            }
            if (visited.contains(curr_word)) {
                continue;
            }
            visited.insert(curr_word);
            for (auto &word : wordList) {
                int diff_cnt = 0;
                for (int i = 0; i < word.size(); i++) {
                    if (word[i] != curr_word[i]) {
                        diff_cnt++;
                    }
                }
                if (diff_cnt == 1) {
                    q.push(word);
                }
            }
        }
        step++;
    }
    return 0;
}

int main() {
    auto f = [](string &&beginWord, string &&endWord, vector<string> &&wordList, int expect) {
        auto output = ladderLength(beginWord, endWord, wordList);
        leetcode_assert(output == expect, "word ladder beginWord={} endWord={} wordList={} expect={} output={}",
                        beginWord, endWord, wordList, expect, output);
    };
    f("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}, 5);
    f("hit", "cog", {"hot", "dot", "dog", "lot", "log"}, 0);
}
