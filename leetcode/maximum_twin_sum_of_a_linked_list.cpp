//
// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/?envType=study-plan-v2&envId=leetcode-75
//

#include "leetcode_utils.hpp"

using namespace std;

int pairSum(ListNode *head) {
   auto *extra = new ListNode();
   extra->next = head;
   auto *slow = head, *fast = head;
   while (fast && fast->next) {
       auto *temp = slow;
       slow = slow->next;
       fast = fast->next->next;
       temp->next = extra->next;
       extra->next = temp;
   }
   int max_twin_sum = INT_MIN;
   auto *n1 = extra->next, *n2 = slow;
   while (n1 && n2) {
       max_twin_sum = max(max_twin_sum, n1->val + n2->val);
       n1 = n1->next;
       n2 = n2->next;
   }
   return max_twin_sum;
}

int main() {
    auto f = [](vector<int> &&head_vec, int expect) {
        auto output = pairSum(newList(std::move(head_vec)));
        leetcode_assert(output == expect, "pair sum head={} expect={} output={}", head_vec, expect, output);
    };
    f({5, 4, 2, 1}, 6);
    f({4, 2, 2, 3}, 7);
    f({1, 100000}, 100001);
}
