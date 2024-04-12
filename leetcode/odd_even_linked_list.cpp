//
// https://leetcode.com/problems/odd-even-linked-list/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

ListNode *oddEvenList(ListNode *head) {
    auto *extra_odd = new ListNode();
    auto *node_odd = extra_odd;
    auto *extra_even = new ListNode();
    auto *node_even = extra_even;

    bool odd = true;
    while (head) {
        if (odd) {
            node_odd->next = head;
            node_odd = node_odd->next;
        } else {
            node_even->next = head;
            node_even = node_even->next;
        }
        head = head->next;
        odd = !odd;
    }
    node_even->next = nullptr;
    node_odd->next = nullptr;

    auto *extra = new ListNode();
    auto *node = extra;
    while (extra_odd->next) {
        node->next = extra_odd->next;
        extra_odd = extra_odd->next;
        node = node->next;
    }
    while (extra_even->next) {
        node->next = extra_even->next;
        extra_even = extra_even->next;
        node = node->next;
    }
    return extra->next;
}

int main() {
    auto f = [](vector<int> &&head_vec, vector<int> &&expect_vec) {
        auto output = oddEvenList(newList(std::move(head_vec)));
        listNodeAssert("odd even", output, std::move(expect_vec));
    };
    f({1, 2, 3, 4, 5}, {1, 3, 5, 2, 4});
    f({2, 1, 3, 5, 6, 4, 7}, {2, 3, 6, 7, 1, 5, 4});
}
