#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node* next;
  Node* prev;

  Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
 private:
  Node* head;
  Node* tail;
  int length;

 public:
  // Constructor
  DoublyLinkedList(int val) {
    head = new Node(val);
    tail = head;
    length = 1;
  }

  // -------------------- Append --------------------
  void append(int data) {
    Node* newNode = new Node(data);
    if (length == 0) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
    length++;
  }

  // -------------------- Prepend --------------------
  void prepend(int data) {
    Node* newNode = new Node(data);
    if (length == 0) {
      head = tail = newNode;
    } else {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
    length++;
  }

  // -------------------- Delete Head --------------------
  void deleteHead() {
    if (length == 0) return;

    Node* temp = head;

    if (length == 1) {
      delete head;
      head = tail = nullptr;
    } else {
      head = head->next;
      head->prev = nullptr;
      delete temp;
    }

    length--;
  }

  // -------------------- Delete Tail --------------------
  void deleteTail() {
    if (length == 0) return;

    if (length == 1) {
      delete head;
      head = tail = nullptr;
      length = 0;
      return;
    }

    Node* temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete temp;

    length--;
  }

  // -------------------- Delete Index --------------------
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
    for (int i = 0; i < pos; i++) {
      temp = temp->next;
    }

    Node* prevNode = temp->prev;
    Node* nextNode = temp->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    delete temp;
    length--;
    return true;
  }

  // -------------------- Insert at Position --------------------
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

    for (int i = 0; i < pos; i++) temp = temp->next;

    Node* prevNode = temp->prev;

    newNode->next = temp;
    newNode->prev = prevNode;

    prevNode->next = newNode;
    temp->prev = newNode;

    length++;
  }

  // -------------------- Construct Linked List (User Input)
  // --------------------
  void construct_linked_list() {
    int input_data;
    Node* temp = this->tail;

    cout << "Note: Give -1 in input to stop DLL construction\n";

    while (true) {
      cout << "Enter the value after " << temp->data << ": ";
      cin >> input_data;

      if (input_data == -1) break;

      Node* newNode = new Node(input_data);
      temp->next = newNode;
      newNode->prev = temp;

      temp = newNode;
      length++;
    }

    tail = temp;
  }

  // -------------------- Utility --------------------
  void printForward() const {
    Node* temp = head;
    while (temp) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }

  void printBackward() const {
    Node* temp = tail;
    while (temp) {
      cout << temp->data << " ";
      temp = temp->prev;
    }
    cout << endl;
  }

  int getLength() const { return length; }

  // -------------------- Destructor --------------------
  ~DoublyLinkedList() {
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
  DoublyLinkedList list(10);

  list.prepend(5);
  list.append(15);
  list.insert(100, 1);
  list.printForward();

  list.deleteIndex(2);

  list.construct_linked_list();
  list.printForward();
  cout << "Backward: ";
  list.printBackward();

  return 0;
}
