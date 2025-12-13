#include <bits/stdc++.h>
using namespace std;

/*
=====================================
        Node Structure
=====================================
*/
class Node {
 public:
  int data;
  Node* left;
  Node* right;

  Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

/*
=====================================
      Binary Search Tree (BST)
=====================================
*/
class BinarySearchTree {
 private:
  Node* root;

 public:
  BinarySearchTree() : root(nullptr) {}

  Node* getRoot() { return root; }

  /*
  =====================================
            Inorder Traversal
      (Left -> Root -> Right)
  =====================================
  */
  void inorder(Node* node) {
    if (!node) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
  }

  /*
  =====================================
            Recursive Search
  =====================================
  */
  bool search(Node* node, int key) {
    if (!node) return false;
    if (node->data == key) return true;

    if (key < node->data)
      return search(node->left, key);
    else
      return search(node->right, key);
  }

  /*
  =====================================
            Iterative Search
  =====================================
  */
  bool iterativeSearch(int key) {
    Node* curr = root;
    while (curr) {
      if (curr->data == key) return true;
      if (key < curr->data)
        curr = curr->left;
      else
        curr = curr->right;
    }
    return false;
  }

  /*
  =====================================
        Recursive Insert
  =====================================
  */
  Node* insert(Node* node, int value) {
    if (!node) return new Node(value);

    if (value < node->data)
      node->left = insert(node->left, value);
    else if (value > node->data)
      node->right = insert(node->right, value);

    return node;
  }

  void insertValue(int value) { root = insert(root, value); }

  /*
  =====================================
      Recursive Delete (Standard)
  =====================================
  */
  Node* deleteNode(Node* node, int key) {
    if (!node) return nullptr;

    if (key < node->data) {
      node->left = deleteNode(node->left, key);
    } else if (key > node->data) {
      node->right = deleteNode(node->right, key);
    } else {
      // Case 1: Leaf node
      if (!node->left && !node->right) {
        delete node;
        return nullptr;
      }
      // Case 2: One child
      else if (!node->left) {
        Node* temp = node->right;
        delete node;
        return temp;
      } else if (!node->right) {
        Node* temp = node->left;
        delete node;
        return temp;
      }
      // Case 3: Two children
      else {
        // Inorder successor (smallest in right subtree)
        Node* succ = node->right;
        while (succ->left) succ = succ->left;

        node->data = succ->data;
        node->right = deleteNode(node->right, succ->data);
      }
    }
    return node;
  }

  void removeRecursive(int key) { root = deleteNode(root, key); }

  /*
  =====================================
      Iterative Delete (O(1) Space)
  =====================================
  */
  void removeIterative(int key) {
    Node* parent = nullptr;
    Node* curr = root;

    // Step 1: Search node
    while (curr && curr->data != key) {
      parent = curr;
      if (key < curr->data)
        curr = curr->left;
      else
        curr = curr->right;
    }

    if (!curr) return;  // key not found

    // Step 2: Node with 2 children
    if (curr->left && curr->right) {
      Node* succParent = curr;
      Node* succ = curr->right;

      while (succ->left) {
        succParent = succ;
        succ = succ->left;
      }

      curr->data = succ->data;
      parent = succParent;
      curr = succ;
    }

    // Step 3: Node with 0 or 1 child
    Node* child = curr->left ? curr->left : curr->right;

    if (!parent)
      root = child;  // deleting root
    else if (parent->left == curr)
      parent->left = child;
    else
      parent->right = child;

    delete curr;
  }

  /*
  =====================================
        Hardcoded Demo Tree
  =====================================
  */
  void buildDemoTree() {
    root = new Node(30);
    root->left = new Node(20);
    root->right = new Node(40);

    root->left->left = new Node(10);
    root->left->right = new Node(25);

    root->right->left = new Node(35);
    root->right->right = new Node(50);
  }
};

/*
=====================================
                MAIN
=====================================
*/
int main() {
  BinarySearchTree bst;
  bst.buildDemoTree();

  bst.insertValue(89);
  bst.insertValue(100);

  // Recursive deletion
  bst.removeRecursive(10);

  // Iterative deletion
  bst.removeIterative(25);
  bst.removeRecursive(100);
  cout << "Inorder Traversal: ";
  bst.inorder(bst.getRoot());
  cout << endl;

  cout << (bst.iterativeSearch(100) ? "Search Found" : "Search Not Found")
       << endl;

  return 0;
}
