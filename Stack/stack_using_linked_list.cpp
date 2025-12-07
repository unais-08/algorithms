#include <bits/stdc++.h>
using namespace std;
class Node {
 public:
  int data;
  Node* next;
  Node(int val) : data(val), next(nullptr) {}
};
class Stack {
 private:
  int size;
  Node* top;

 public:
  Stack() {
    top = nullptr;
    size = 0;
  }

  void push(int x) {
    Node* newNode = new Node(x);
    newNode->next = top;
    top = newNode;
    size++;
  }

  // Remove element
  int pop() {
    if (top == nullptr) {
      cout << "Stack Underflow\n";
      exit(1);
      return -1;
    }
    Node* temp = top;
    top = top->next;
    int _popedvalue = temp->data;
    delete temp;
    temp = nullptr;
    size--;
    return _popedvalue;
  }
  // Show top element
  int peek() {
    if (top == nullptr) {
      cout << "Stack is Empty\n";
      return -1;
    }
    return top->data;
  }
  bool isEmpty() { return top == nullptr; }
  int getSize() { return this->size; }
  void print() {
    Node* temp = top;
    while (temp) {
      cout << temp->data << endl;
      temp = temp->next;
    }
  }
};

int main() {
  cout << "Hello, World!" << endl;
  Stack st;

  st.push(10);
  st.push(20);
  st.push(30);
  st.push(40);

  st.push(50);
  st.push(60);
  st.push(70);
  st.push(80);

  st.pop();
  st.pop();

  cout << "Top: " << st.peek() << endl;
  st.print();
  return 0;
}