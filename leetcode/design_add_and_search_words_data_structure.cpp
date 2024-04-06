//
// Created by 汪喆昊 on 2024/4/5.
// https://leetcode.com/problems/design-add-and-search-words-data-structure/?envType=study-plan-v2&envId=top-interview-150
//

#include "leetcode_utils.hpp"

using namespace std;

struct TrieNode {
    bool is_word;
    TrieNode *children[26];

    TrieNode() {
        is_word = false;
        memset(children, 0, sizeof(children));
    }
};

bool check_valid(string &word, int index, TrieNode *node) {
    if (index >= word.size()) {
        return node->is_word;
    }
    char c = word[index];
    if (c == '.') {
        bool valid = false;
        for (auto p : node->children) {
            if (p && check_valid(word, index + 1, p)) {
                valid = true;
                break;
            }
        }
        return valid;
    } else {
        int offset = c - 'a';
        auto p = node->children[offset];
        if (p) {
            return check_valid(word, index + 1, p);
        } else {
            return false;
        }
    }
}

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        auto p = root;
        for (char c : word) {
            int offset = c - 'a';
            if (!p->children[offset]) {
                p->children[offset] = new TrieNode();
            }
            p = p->children[offset];
        }
        p->is_word = true;
    }

    bool search(string word) {
        if (word.empty()) {
            return true;
        }
        return check_valid(word, 0, root);
    }

private:
    TrieNode *root;
};

int main() {
    auto dic = WordDictionary();
    dic.addWord("bad");
    dic.addWord("dad");
    dic.addWord("map");
    fmt::println("dic.search(\"pad\") {}", dic.search("pad"));
    fmt::println("dic.search(\"bad\") {}", dic.search("bad"));
    fmt::println("dic.search(\".ad\") {}", dic.search(".ad"));
    fmt::println("dic.search(\"b..\") {}", dic.search("b.."));
}
