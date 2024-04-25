//
// https://leetcode.com/problems/search-suggestions-system/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

const int CHILDREN_NUM = 26;

struct TrieNode {
    bool is_word;
    TrieNode *children[CHILDREN_NUM];
};

void clearNode(TrieNode *node) {
    for (auto p : node->children) {
        if (p) {
            clearNode(p);
        }
    }
    delete node;
}

class TrieTree {
public:
    TrieTree() { root = new TrieNode(); };

    ~TrieTree() { clearNode(root); }

    void insert(string &word) {
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

    vector<string> getWords(string &prefix) {
        vector<string> res;
        auto p = root;
        for (char c : prefix) {
            auto next_p = p->children[c - 'a'];
            if (!next_p) {
                return res;
            }
            p = next_p;
        }
        dfs(p, prefix, res);
        return res;
    }

    vector<vector<string>> search2(string &word) {
        vector<vector<string>> res;
        string word_to_search;
        for (char c : word) {
            word_to_search.push_back(c);
            res.push_back(getWords(word_to_search));
        }
        return res;
    }

    void dfs(TrieNode *node, string &path, vector<string> &curr_vec) {
        if (curr_vec.size() == 3) {
            return;
        }
        if (node->is_word) {
            curr_vec.push_back(path);
        }
        for (char c = 'a'; c <= 'z'; c++) {
            auto next_p = node->children[c - 'a'];
            if (next_p) {
                path.push_back(c);
                dfs(next_p, path, curr_vec);
                path.pop_back();
            }
        }
    }

private:
    TrieNode *root;
};

vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord) {
    auto tree = TrieTree();
    for (auto &product : products) {
        tree.insert(product);
    }
    vector<vector<string>> res;
    string prefix;
    for (char c : searchWord) {
        prefix.push_back(c);
        res.push_back(tree.getWords(prefix));
    }
    return res;
}

vector<vector<string>> suggestedProducts_v2(vector<string> &products, string searchWord) {
    vector<vector<string>> res;
    size_t start = 0, next_start = 0, N = products.size();
    sort(products.begin(), products.end());
    string prefix;
    for (char c : searchWord) {
        prefix += c;
        start = lower_bound(products.begin() + next_start, products.end(), prefix) - products.begin();

        res.push_back({});
        const int end = min(start + 3, N);
        for (int i = start; i < end && products[i].compare(0, prefix.length(), prefix) == 0; i++) {
            res.back().push_back(products[i]);
        }
        next_start = start;
    }
    return res;
}

int main() {
    auto f = [](vector<string> &&products, string &&searchWord, vector<vector<string>> &&expect) {
        auto output = suggestedProducts(products, searchWord);
        leetcode_assert(output == expect,
                        "search_suggestions_system \n  products={} \n  searchWord={} \n  expect={} \n  output={}",
                        products, searchWord, expect, output);
    };
    f({"mobile", "mouse", "moneypot", "monitor", "mousepad"}, "mouse",
      make2DStrVecByStr("[[\"mobile\",\"moneypot\",\"monitor\"],[\"mobile\",\"moneypot\",\"monitor\"],[\"mouse\","
                        "\"mousepad\"],[\"mouse\",\"mousepad\"],[\"mouse\",\"mousepad\"]]"));
    f({"havana"}, "tatiana", make2DStrVecByStr("[[],[],[],[],[],[],[]]"));
}
