#include <bits/stdc++.h>
using namespace std;
class Node {
 public:
  int data;
  Node* next;
  Node(int val) : data(val), next(nullptr) {}
};

class Queue {
 private:
  Node* head;
  Node* front;
  Node* rear;
  int length;

 public:
  Queue() {
    front = nullptr;
    rear = nullptr;
    length = 0;
  }

  void enqueue(int x) {
    Node* newNode = new Node(x);
    if (length == 0) {
      head = newNode;
      front = rear = head;
      length++;
      return;
    }

    rear->next = newNode;
    rear = newNode;
    length++;
    return;
  }

  int dequeue() {
    if (length == 0) {
      cout << "Emtpy Queue\n";
      return INT_MIN;
    }
    if (length == 1) {
      Node* temp = front;
      int dequedValue = temp->data;
      delete temp;
      head = front = rear = nullptr;
      length--;
      return dequedValue;
    }
    Node* temp = front;
    int dequedValue = temp->data;
    front = front->next;
    delete temp;
    length--;
    return dequedValue;
  }

  int peek() {
    if (length == 0) {
      cout << "Empty Queue\n";
      return INT_MIN;
    }
    return front->data;
  }

  int getLength() { return this->length; }

  void print() {
    Node* temp = front;
    while (temp) {
      cout << temp->data << "|";
      temp = temp->next;
    }
    cout << endl;
  }
};

int main() {
  cout << "Hello, World!" << endl;

  Queue que;
  que.enqueue(10);
  que.enqueue(20);
  que.enqueue(30);
  // que.dequeue();
  // que.dequeue();
  // que.dequeue();
  que.print();
  // cout << que.peek() << endl;
  return 0;
}