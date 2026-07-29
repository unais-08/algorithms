#include <bits/stdc++.h>
using namespace std;

/**
 * This question need to implement loop in linked list using pos(i).
 * I have just implement the function to solve this particular problem.
 */

class Node {
   public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

int find_length(Node* slow, Node* fast) {
    int cnt = 1;
    slow = slow->next;
    while (slow != fast) {
        cnt++;
        slow = slow->next;
    };
    return cnt;
}
int length_of_loop(Node* head) {
    if (head == nullptr) return 0;

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            int length = find_length(slow, fast);
            return length;
        }
    }
    return 0;
}