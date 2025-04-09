//
// Created by 汪喆昊 on 2024/3/27.
//

#include "list_node.hpp"
#include <fmt/core.h>
#include "leetcode_utils.hpp"

using namespace std;

ListNode *newList(const std::vector<int> &&vec) {
    auto *extra = new ListNode();
    auto *node = extra;
    for (int i : vec) {
        auto *n = new ListNode(i);
        node->next = n;
        node = node->next;
    }
    auto *res = extra->next;
    free(extra);
    return res;
}

vector<int> node2Vec(const ListNode *head) {
    auto *node = head;
    vector<int> vec;
    while (node != nullptr) {
        vec.push_back(node->val);
        node = node->next;
    }
    return vec;
}

void listNodeAssert(std::string &&prefix, ListNode *head, const std::vector<int> &&vec) {
    auto node_vec = node2Vec(head);
    bool same = equal(node_vec.begin(), node_vec.end(), vec.begin(), vec.end());
    leetcode_assert(same, "{} output={} expect={}", std::move(prefix), node_vec, vec);
//    leetcode_assert(same, "{} output={} expect={}", std::move(prefix), node_vec, vec);
}
