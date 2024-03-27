//
// Created by 汪喆昊 on 2024/3/27.
//

#include "leetcode_utils.hpp"

using namespace std;

// https://leetcode.com/problems/add-two-numbers/description/
ListNode *addTwoNumbers_v2(ListNode *l1, ListNode *l2) {
    auto *res = new ListNode();
    auto *head = res;
    int carry = 0;
    while (l1 || l2 || carry) {
        head->next = new ListNode();
        head = head->next;
        int curr = carry;
        if (l1) {
            curr += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            curr += l2->val;
            l2 = l2->next;
        }
        if (curr >= 10) {
            curr -= 10;
            carry = 1;
        } else {
            carry = 0;
        }
        head->val = curr;
    }
    return res->next;
}

int main() {
    auto f = [&](vector<int> &&v1, vector<int> &&v2, vector<int> &&vec) {
        auto *l1 = newList(std::move(v1));
        auto *l2 = newList(std::move(v2));
        ListNode *res = addTwoNumbers_v2(l1, l2);
        listNodeAssert(fmt::format("add two numbers l1={} l2={}", v1, v2), res, std::move(vec));
    };

    f({2, 4, 3}, {5, 6, 4}, {7, 0, 8});
    f({0}, {0}, {0});
    f({9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9}, {8, 9, 9, 9, 0, 0, 0, 1});
}
