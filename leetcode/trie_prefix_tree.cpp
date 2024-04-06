//
// Created by 汪喆昊 on 2024/4/5.
// https://leetcode.com/problems/implement-trie-prefix-tree/?envType=study-plan-v2&envId=top-interview-150
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

void freeNode(TrieNode *node) {
    for (auto p : node->children) {
        freeNode(p);
    }
    free(node);
}

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        freeNode(root);
    }

    void insert(string word) {
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
        auto p = root;
        for (char c : word) {
            int offset = c - 'a';
            if (!p->children[offset]) {
                return false;
            }
            p = p->children[offset];
        }
        return p->is_word;
    }

    bool startsWith(string prefix) {
        auto p = root;
        for (char c : prefix) {
            int offset = c - 'a';
            if (!p->children[offset]) {
                return false;
            }
            p = p->children[offset];
        }
        return true;
    }

private:
    TrieNode *root;
};

int main() {
    auto t = Trie();
    t.insert("apple");
    fmt::println("t.search(\"apple\") = {}", t.search("apple"));
    fmt::println("t.search(\"app\") = {}", t.search("app"));
    fmt::println("t.startsWith(\"app\") = {}", t.startsWith("app"));
    t.insert("app");
    fmt::println("t.search(\"app\") = {}", t.search("app"));
}
