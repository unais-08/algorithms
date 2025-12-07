#include <bits/stdc++.h>
using namespace std;

class Stack {
 private:
  int size;
  int* arr;
  int top = -1;

 public:
  Stack(int size) {
    this->size = size;
    arr = new int[size];
    top = -1;
  }

  void push(int x) {
    if (top == size - 1) {
      cout << "Stack Overflow\n";
      return;
    }
    arr[++top] = x;
  }

  // Remove element
  int pop() {
    if (top == -1) {
      cout << "Stack Underflow\n";
      return -1;
    }
    return arr[top--];
  }
  // Show top element
  int peek() {
    if (top == -1) {
      cout << "Stack is Empty\n";
      return -1;
    }
    return arr[top];
  }
  bool isEmpty() { return top == -1; }
};

int main() {
  cout << "Hello, World!" << endl;
  Stack st(5);

  st.push(10);
  st.push(20);
  st.push(30);

  cout << "Top: " << st.peek() << endl;

  st.pop();
  cout << "Top after pop: " << st.peek() << endl;

  return 0;
}