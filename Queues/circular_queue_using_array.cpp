#include <bits/stdc++.h>
using namespace std;

class CircularQueue {
 private:
  int* arr;
  int size;
  int front;
  int rear;

 public:
  CircularQueue(int size) {
    this->size = size;
    arr = new int[size];
    front = rear = -1;
  }

  void enqueue(int x) {
    // Queue full
    if ((rear + 1) % size == front) {
      cout << "Queue is Full\n";
      return;
    }
    // First element
    if (front == -1) {
      front = rear = 0;
      arr[rear] = x;
      return;
    }
    // Normal push
    rear = (rear + 1) % size;
    arr[rear] = x;
  }

  int dequeue() {
    // Empty
    if (front == -1) {
      cout << "Queue is Empty\n";
      return INT_MIN;
    }

    int value = arr[front];

    // Only one element
    if (front == rear) {
      front = rear = -1;
      return value;
    }

    // Normal delete
    front = (front + 1) % size;
    return value;
  }

  void peek() {
    if (front == -1) {
      cout << "Queue is Empty\n";
      return;
    }
    cout << arr[front] << endl;
  }
};

int main() {
  CircularQueue cq(5);

  cq.enqueue(1);
  cq.enqueue(2);
  cq.enqueue(3);
  cq.enqueue(4);
  cq.enqueue(5);

  cout << cq.dequeue() << endl;
  cout << cq.dequeue() << endl;
  cout << cq.dequeue() << endl;
  cout << cq.dequeue() << endl;
  cout << cq.dequeue() << endl;
  cout << cq.dequeue() << endl;  // empty case

  return 0;
}
