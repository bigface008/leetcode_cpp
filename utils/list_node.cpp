//
// Created by 汪喆昊 on 2024/3/27.
//

#include "list_node.h"
#include <fmt/core.h>
#include "leetcode_utils.hpp"

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

void listNodeAssert(std::string &&prefix, ListNode *head, std::vector<int> &&vec) {
    ListNode *node = head;
    std::vector<int> nodeVec;
    bool isSame = true;
    while (node != nullptr) {
        nodeVec.push_back(node->val);
        node = node->next;
    }
    if (nodeVec.size() != vec.size()) {
        isSame = false;
    } else {
        for (int i = 0; i < vec.size(); ++i) {
            if (nodeVec[i] != vec[i]) {
                isSame = false;
                break;
            }
        }
    }
    leetcode_assert(isSame, std::move(prefix));
    fmt::println(" output={} expect={}", nodeVec, vec);
}
