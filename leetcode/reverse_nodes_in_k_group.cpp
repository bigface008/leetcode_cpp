//
// https://leetcode.cn/problems/reverse-nodes-in-k-group/
//

#include "leetcode_utils.hpp"

using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *node = head;
        int cnt = 0;
        while (node) {
            node = node->next;
            cnt++;
        }
        int groupCnt = cnt / k;

        ListNode *extra = new ListNode(-1);
        extra->next = head;
        ListNode *prevNode = nullptr;
        ListNode *groupPrev = extra;
        node = head;
        int i = 0;
        while (i < groupCnt) {
            for (int i = 0; i < k; i++) {
                ListNode *nextNode = node->next;
                node->next = prevNode;
                prevNode = node;
                node = nextNode;
            }
            ListNode *nextNode = groupPrev->next;
            groupPrev->next->next = node;
            groupPrev->next = prevNode;
            groupPrev = nextNode;
            i++;
        }
        return extra->next;
    }
};


int main() {
    auto f = [](vector<int> &&headVec, int k, vector<int> &&expectVec) {
        ListNode *head = newList(std::move(headVec));
        ListNode *output = Solution().reverseKGroup(head, k);
        listNodeAssert("", output, std::move(expectVec));
    };
//    f({1, 2, 3, 4, 5}, 2, {2, 1, 4, 3, 5});
    f({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 4, {4, 3, 2, 1, 8, 7, 6, 5, 9, 10});
}
