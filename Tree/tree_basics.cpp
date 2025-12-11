#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node* right;
  Node* left;

 public:
  Node(int data) : data(data), right(nullptr), left(nullptr) {}
};

class BinaryTree {
 private:
  Node* root;

 public:
  BinaryTree(int data) { root = new Node(data); }
  BinaryTree() { root = nullptr; }

 private:
  int getInput(const string& msg) {
    cout << msg;
    int x;
    cin >> x;
    return x;
  }

 public:
  Node* getRoot() { return root; }
  void construct_bt() {
    if (root == nullptr) {
      int rv = getInput("Enter root value: ");
      if (rv == -1) return;
      root = new Node(rv);
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
      Node* curr = q.front();
      q.pop();

      int l = getInput("Left of " + to_string(curr->data) + ": ");

      if (l != -1) {
        curr->left = new Node(l);
        q.push(curr->left);
      }

      int r = getInput("Right of " + to_string(curr->data) + ": ");

      if (r != -1) {
        curr->right = new Node(r);
        q.push(curr->right);
      }
    }
  }

  // data processing at calling time
  void pre_order(Node* root);

  // data processing at returning time
  void post_order(Node* root);
  // data processing b/w calling time and returning time
  void in_order(Node* root);

  void levelOrder();

  Node* buildTree();

  void Ipreorder(vector<int>& preorder_sequence);

  void Iinorder(vector<int>& inorder_sequence);

  void Ipostorder(vector<int>& post);
};
int main() {
  cout << "==============================" << endl;
  cout << "   Tree Data Structure Demo   " << endl;
  cout << "==============================" << endl;

  BinaryTree* bt = new BinaryTree();
  // cout << "\nConstructing Binary Tree..." << endl;
  // bt->construct_bt();
  bt->buildTree();

  cout << "\nTraversal Outputs:" << endl;

  cout << "------------------------------" << endl;
  cout << "Level Order Traversal: ";
  bt->levelOrder();
  cout << endl;
  cout << endl;

  cout << "Preorder Traversal (Recursive): ";
  bt->pre_order(bt->getRoot());
  cout << endl;

  vector<int> preorder_sequence;
  bt->Ipreorder(preorder_sequence);
  cout << "Preorder Traversal (Iterative): ";
  for (int val : preorder_sequence) cout << val << " ";
  cout << endl;
  cout << endl;

  cout << "Inorder Traversal (Recursive): ";
  bt->in_order(bt->getRoot());
  cout << endl;

  vector<int> inorder_sequence;
  bt->Iinorder(inorder_sequence);
  cout << "Inorder Traversal (Iterative): ";
  for (int val : inorder_sequence) cout << val << " ";
  cout << endl;
  cout << endl;

  cout << "Postorder Traversal (Recursive): ";
  bt->post_order(bt->getRoot());
  cout << endl;

  vector<int> postorder_sequence;
  bt->Ipostorder(postorder_sequence);
  cout << "Postorder Traversal (Iterative): ";
  for (int val : postorder_sequence) cout << val << " ";
  cout << endl;

  cout << "==============================" << endl;
  cout << "        Program Ended         " << endl;
  cout << "==============================" << endl;

  delete bt;
  return 0;
}

void BinaryTree::pre_order(Node* root) {
  if (root) {
    cout << root->data << " ";
    pre_order(root->left);
    pre_order(root->right);
  }
  return;
}

void BinaryTree::post_order(Node* root) {
  if (root) {
    post_order(root->left);
    post_order(root->right);
    cout << root->data << " ";
  }
  return;
}

void BinaryTree::in_order(Node* root) {
  if (root) {
    in_order(root->left);
    cout << root->data << " ";
    in_order(root->right);
  }
  return;
}

void BinaryTree::Ipreorder(vector<int>& preorder_sequence) {
  if (!root) return;

  stack<Node*> st;
  st.push(root);

  while (!st.empty()) {
    Node* curr = st.top();  // use local var
    st.pop();

    preorder_sequence.push_back(curr->data);

    if (curr->right) st.push(curr->right);
    if (curr->left) st.push(curr->left);
  }
}

void BinaryTree::Iinorder(vector<int>& inorder_sequence) {
  stack<Node*> st;
  Node* curr = root;
  while (curr || !st.empty()) {
    while (curr) {
      st.push(curr);
      curr = curr->left;
    }
    curr = st.top();
    st.pop();

    inorder_sequence.push_back(curr->data);

    curr = curr->right;
  }
}

void BinaryTree::Ipostorder(vector<int>& ans) {
  if (!root) return;
  stack<Node*> s1, s2;
  s1.push(root);

  while (!s1.empty()) {
    root = s1.top();
    s1.pop();

    s2.push(root);

    if (root->left) s1.push(root->left);
    if (root->right) s1.push(root->right);
  }
  // Empty s2 after s1 is completely processed
  while (!s2.empty()) {
    ans.push_back(s2.top()->data);
    s2.pop();
  }
}

void BinaryTree::levelOrder() {
  if (!this->root) return;
  queue<Node*> q;
  q.push(this->root);

  while (!q.empty()) {
    Node* curr = q.front();
    q.pop();
    cout << curr->data << " ";

    if (curr->left) q.push(curr->left);
    if (curr->right) q.push(curr->right);
  }
}
// TREE
Node* BinaryTree::buildTree() {
  this->root = new Node(10);
  root->left = new Node(5);
  root->right = new Node(20);

  root->left->left = new Node(3);
  root->left->right = new Node(8);

  root->right->right = new Node(25);

  return root;
}