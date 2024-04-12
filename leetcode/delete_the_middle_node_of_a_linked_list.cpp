//
// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

ListNode *deleteMiddleV2(ListNode *head) {
    auto *extra = new ListNode();
    extra->next = head;

    ListNode *slow = head, *fast = head, *prev_slow = extra;
    while (fast && fast->next) {
        prev_slow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev_slow->next = slow->next;
    return extra->next;
}

ListNode *deleteMiddle(ListNode *head) {
    auto *extra = new ListNode();
    extra->next = head;

    int cnt = 0;
    auto *node = head;
    while (node) {
        node = node->next;
        cnt++;
    }

    int half = cnt / 2;
    int i = 0;
    node = head;
    auto *prev = extra;
    while (i <= half) {
        if (i == half) {
            prev->next = node->next;
            break;
        }
        prev = node;
        node = node->next;
        i++;
    }


    auto *res = extra->next;
    return res;
}

int main() {
    auto f = [](vector<int> &&head_vec, vector<int> &&expect_vec) {
        ListNode *head = newList(std::move(head_vec));
        auto output = deleteMiddleV2(head);
        listNodeAssert("delete middle", output, std::move(expect_vec));
    };
    f({1, 3, 4, 7, 1, 2, 6}, {1, 3, 4, 1, 2, 6});
    f({1, 2, 3, 4}, {1, 2, 4});
    f({2, 1}, {2});
}
