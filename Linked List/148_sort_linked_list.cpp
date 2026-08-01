#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    ListNode* next;
    int val;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* findMid(ListNode* head) {
        ListNode *slow = head, *fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(-1);
        ListNode* tail = &dummy;

        while (left && right) {
            if (left->val <= right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }

        if (left)
            tail->next = left;
        else
            tail->next = right;

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* mid = findMid(head);
        ListNode* right = mid->next;
        mid->next = nullptr;

        ListNode* left = sortList(head);
        right = sortList(right);

        return merge(left, right);
    }
};