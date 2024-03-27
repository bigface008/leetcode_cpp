//
// Created by 汪喆昊 on 2024/3/27.
//

#ifndef LEETCODE_CPP_LIST_NODE_H
#define LEETCODE_CPP_LIST_NODE_H

#include <string>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *newList(const std::vector<int> &&vec);

void listNodeAssert(std::string &&prefix, ListNode *head, std::vector<int> &&vec);

#endif // LEETCODE_CPP_LIST_NODE_H
