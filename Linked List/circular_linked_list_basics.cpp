#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node* next;

  Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
 private:
  Node* head;
  Node* tail;
  int length;

 public:
  CircularLinkedList(int val) {
    head = new Node(val);
    tail = head;
    head->next = head;  // circle
    length = 1;
  }

  // ---------------- Append ----------------
  void append(int data) {
    Node* newNode = new Node(data);

    if (length == 0) {
      head = tail = newNode;
      newNode->next = newNode;
    } else {
      newNode->next = head;
      tail->next = newNode;
      tail = newNode;
    }
    length++;
  }

  // ---------------- Prepend ----------------
  void prepend(int data) {
    Node* newNode = new Node(data);

    if (length == 0) {
      head = tail = newNode;
      newNode->next = newNode;
    } else {
      newNode->next = head;
      head = newNode;
      tail->next = head;
    }
    length++;
  }

  // ---------------- Delete Head ----------------
  void deleteHead() {
    if (length == 0) return;

    if (length == 1) {
      delete head;
      head = tail = nullptr;
      length = 0;
      return;
    }

    Node* temp = head;
    head = head->next;
    tail->next = head;
    delete temp;
    length--;
  }

  // ---------------- Delete Tail ----------------
  void deleteTail() {
    if (length == 0) return;

    if (length == 1) {
      delete head;
      head = tail = nullptr;
      length = 0;
      return;
    }

    Node* temp = head;
    while (temp->next != tail) {
      temp = temp->next;
    }

    temp->next = head;
    delete tail;
    tail = temp;
    length--;
  }

  // ---------------- Delete Index ----------------
  bool deleteIndex(int pos) {
    if (pos < 0 || pos >= length) {
      cout << "Invalid Index\n";
      return false;
    }

    if (pos == 0) {
      deleteHead();
      return true;
    }

    if (pos == length - 1) {
      deleteTail();
      return true;
    }

    Node* temp = head;
    for (int i = 0; i < pos - 1; i++) {
      temp = temp->next;
    }

    Node* toDelete = temp->next;
    temp->next = toDelete->next;

    delete toDelete;
    length--;
    return true;
  }

  // ---------------- Insert at index ----------------
  void insert(int data, int pos) {
    if (pos < 0 || pos > length) {
      cout << "Invalid Index\n";
      return;
    }

    if (pos == 0) {
      prepend(data);
      return;
    }

    if (pos == length) {
      append(data);
      return;
    }

    Node* newNode = new Node(data);
    Node* temp = head;

    for (int i = 0; i < pos - 1; i++) {
      temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    length++;
  }

  // ---------------- Print ----------------
  void print() {
    if (length == 0) {
      cout << "Empty\n";
      return;
    }

    Node* temp = head;

    do {
      cout << temp->data << " ";
      temp = temp->next;
    } while (temp != head);

    cout << endl;
  }

  int getLength() const { return length; }

  // ---------------- Destructor ----------------
  ~CircularLinkedList() {
    if (length == 0) return;

    Node* temp = head;
    do {
      Node* nextNode = temp->next;
      delete temp;
      temp = nextNode;
    } while (temp != head);

    head = tail = nullptr;
    length = 0;
  }
};

int main() {
  CircularLinkedList cll(10);

  cll.append(20);
  cll.append(30);
  cll.prepend(5);

  cll.insert(100, 2);

  cll.print();

  cll.deleteIndex(3);
  cll.print();

  cll.deleteHead();
  cll.print();

  return 0;
}
