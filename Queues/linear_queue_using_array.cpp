#include <bits/stdc++.h>
using namespace std;

class Queue {
 private:
  int* queue;
  int size;
  int front;
  int rear;

 public:
  Queue(int size) {
    this->size = size;
    queue = new int[size];
    front = rear = -1;
  }

  void enqueue(int x) {
    if (rear == size - 1) {
      cout << "Queue Overflow!\n";
      exit(1);
      return;
    }
    if (front == -1) front = 0;  // first element
    queue[++rear] = x;
  }

  int dequeue() {
    if (front == -1 || front > rear) {
      cout << "Queue Underflow!\n";
      return -1;
    }
    return queue[front++];
  }

  int peek() {
    if (front == -1 || front > rear) {
      cout << "Queue is Empty\n";
      return -1;
    }
    return queue[front];
  }
  bool isEmpty() { return (front == -1 || front > rear); }
  void print() {
    int temp = front;
    while (temp < size) {
      cout << queue[temp++] << "|";
    }
    cout << endl;
  }
};

int main() {
  cout << "Hello, World!" << endl;
  //   Queue q(5);
  //   q.enqueue(1);
  //   q.enqueue(2);
  //   q.enqueue(3);
  //   q.enqueue(4);
  //   q.enqueue(5);
  //   q.dequeue();
  //   q.enqueue(100);
  //   q.print();
  queue<int> que;
  que.push(10);
  que.push(20);
  que.push(20);
  que.push(20);
  while (que.front()) {
    /* code */
    cout << que.front() << " ";
    que.pop();
  }

  return 0;
}