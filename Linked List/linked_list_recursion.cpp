#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node* next;

  Node(int val) {
    data = val;
    next = nullptr;
  }
};

// Create linked list recursively
Node* createLL(vector<int> arr, int idx, int size) {
  if (idx == size) {
    return nullptr;
  }

  Node* newNode = new Node(arr[idx]);
  newNode->next = createLL(arr, idx + 1, size);
  return newNode;
}

// Print linked list recursively
void printLL(Node* head) {
  if (head == nullptr) {
    cout << "NULL\n";
    return;
  }
  cout << head->data << " -> ";
  printLL(head->next);
}

void print(Node* head) {
  Node* temp = head;
  if (temp == nullptr) {
    cout << "NULL\n";
    return;
  }
  cout << temp->data << " ->";
  print(temp->next);
}

int main() {
  vector<int> arr = {10, 20, 30, 40, 50};

  // Call your recursive creation function
  Node* head = createLL(arr, 0, arr.size());

  // Print the linked list
  printLL(head);
  list<int> myls;

  return 0;
}
