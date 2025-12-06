#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node* next;

  Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
 private:
  Node* head;
  Node* tail;
  int length;

 public:
  LinkedList(int val) {
    head = new Node(val);
    tail = head;
    length = 1;
  }

  // ------- Basic Insertions ---------

  void append(int data) {
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
    length++;
  }

  void prepend(int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    if (length == 0) tail = newNode;
    length++;
  }

  // -------- Delete Operations ---------

  void deleteHead() {
    if (length == 0) return;

    Node* temp = head;
    head = head->next;
    delete temp;

    length--;

    if (length == 0) tail = nullptr;  // list became empty
  }

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
    delete tail;
    tail = temp;
    tail->next = nullptr;
    length--;
  }

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
      // To get the pointer of the element 1 pre to target
      temp = temp->next;
    }

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
    length--;
    return true;
  }

  // -------- Insert at Index ---------

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

  // --------- Utility Methods ----------

  int getLength() const { return length; }

  void print() const {
    Node* temp = head;
    while (temp) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }

  Node* getHead() const { return head; }
  Node* getTail() const { return tail; }

  // -------- Destructor ---------

  ~LinkedList() {
    Node* temp = head;
    while (temp) {
      Node* nxt = temp->next;
      delete temp;
      temp = nxt;
    }
    head = tail = nullptr;
    length = 0;
  }
};

int main() {
  LinkedList list(10);

  list.prepend(5);
  list.append(15);
  list.insert(100, 1);
  list.print();
  list.deleteIndex(2);

  list.print();

  return 0;
}
