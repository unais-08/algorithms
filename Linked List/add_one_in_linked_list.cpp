
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() {
        val = 0;
        next = NULL;
    }
    ListNode(int val1) {
        val = val1;
        next = NULL;
    }
    ListNode(int val1, ListNode* next1) {
        val = val1;
        next = next1;
    }
};
class Solution {
   public:
    // Returns the carry generated after processing the current node.
    int helper(ListNode* head) {
        // Base case: add 1 beyond the last node.
        if (head == nullptr) return 1;

        int carry = helper(head->next);

        head->val += carry;

        if (head->val < 10) return 0;

        head->val = 0;
        return 1;
    }

    ListNode* addOne(ListNode* head) {
        int carry = helper(head);

        if (carry) {
            ListNode* newHead = new ListNode(1);
            newHead->next = head;
            head = newHead;
        }

        return head;
    }
};