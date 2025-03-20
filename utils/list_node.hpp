//
// Created by 汪喆昊 on 2024/3/27.
//

#ifndef LEETCODE_CPP_LIST_NODE_HPP
#define LEETCODE_CPP_LIST_NODE_HPP

#include <string>
#include <vector>
#include <fmt/ranges.h>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *newList(const std::vector<int> &&vec);

std::vector<int> node2Vec(const ListNode *head);

void listNodeAssert(std::string &&prefix, ListNode *head, std::vector<int> &&vec);

template <>
struct fmt::formatter<ListNode> : fmt::formatter<std::string> {
    template <typename FormatContext>
    auto format(const ListNode& n, FormatContext& ctx) -> decltype(ctx.out()) {
        auto it = ctx.out();
        const ListNode *curr = &n;
        while (curr) {
            it = format_to(it, "{}", curr->val);
            curr = curr->next;
            if (curr) {
                it = format_to(it, " -> ");
            }
        }
        return it;
    }
};

#endif // LEETCODE_CPP_LIST_NODE_HPP
