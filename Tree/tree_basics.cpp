#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node* right;
  Node* left;

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

  // Level-order construction using -1 as null indicator
  void construct_bt() {
    if (!root) {
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

  void pre_order(Node* root) {
    if (root) {
      cout << root->data << " ";
      pre_order(root->left);
      pre_order(root->right);
    }
  }

  void in_order(Node* root) {
    if (root) {
      in_order(root->left);
      cout << root->data << " ";
      in_order(root->right);
    }
  }

  void post_order(Node* root) {
    if (root) {
      post_order(root->left);
      post_order(root->right);
      cout << root->data << " ";
    }
  }

  void levelOrder() {
    if (!root) return;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
      Node* curr = q.front();
      q.pop();
      cout << curr->data << " ";

      if (curr->left) q.push(curr->left);
      if (curr->right) q.push(curr->right);
    }
  }

  // Iterative traversals
  void Ipreorder(vector<int>& ans) {
    if (!root) return;

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
      Node* curr = st.top();
      st.pop();

      ans.push_back(curr->data);

      if (curr->right) st.push(curr->right);
      if (curr->left) st.push(curr->left);
    }
  }

  void Iinorder(vector<int>& ans) {
    stack<Node*> st;
    Node* curr = root;

    while (curr || !st.empty()) {
      while (curr) {
        st.push(curr);
        curr = curr->left;
      }

      curr = st.top();
      st.pop();

      ans.push_back(curr->data);
      curr = curr->right;
    }
  }

  void Ipostorder(vector<int>& ans) {
    if (!root) return;

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
      Node* curr = s1.top();
      s1.pop();

      s2.push(curr);

      if (curr->left) s1.push(curr->left);
      if (curr->right) s1.push(curr->right);
    }

    while (!s2.empty()) {
      ans.push_back(s2.top()->data);
      s2.pop();
    }
  }

  // Single-stack: Pre + In + Post in one traversal
  void pre_in_post(vector<int>& pre, vector<int>& in, vector<int>& post) {
    stack<pair<Node*, int>> st;
    st.push({root, 1});

    while (!st.empty()) {
      auto it = st.top();
      st.pop();

      if (it.second == 1) {
        pre.push_back(it.first->data);
        // it.second++;
        it.second = 2;
        st.push(it);
        if (it.first->left) st.push({it.first->left, 1});
      }

      else if (it.second == 2) {
        in.push_back(it.first->data);
        // it.second++;
        it.second = 3;
        st.push(it);
        if (it.first->right) st.push({it.first->right, 1});
      }

      else {
        post.push_back(it.first->data);
      }
    }
  }

  // Hardcoded demo tree
  Node* buildTree() {
    root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);

    root->left->left = new Node(3);
    root->left->right = new Node(8);

    root->right->right = new Node(25);

    return root;
  }
};

int main() {
  cout << "==============================" << endl;
  cout << "   Tree Data Structure Demo   " << endl;
  cout << "==============================" << endl;

  BinaryTree bt;
  bt.buildTree();

  cout << "\nLevel Order       : ";
  bt.levelOrder();
  cout << "\n";

  cout << "Preorder (Rec)    : ";
  bt.pre_order(bt.getRoot());
  cout << "\n";

  vector<int> preIt, inIt, postIt;
  bt.Ipreorder(preIt);
  bt.Iinorder(inIt);
  bt.Ipostorder(postIt);

  cout << "Preorder (Itr)    : ";
  for (int x : preIt) cout << x << " ";
  cout << "\n";

  cout << "Inorder  (Rec)    : ";
  bt.in_order(bt.getRoot());
  cout << "\n";

  cout << "Inorder  (Itr)    : ";
  for (int x : inIt) cout << x << " ";
  cout << "\n";

  cout << "Postorder (Rec)   : ";
  bt.post_order(bt.getRoot());
  cout << "\n";

  cout << "Postorder (Itr)   : ";
  for (int x : postIt) cout << x << " ";
  cout << "\n\n";

  vector<int> pre, in, post;
  bt.pre_in_post(pre, in, post);

  cout << "Combined Preorder : ";
  for (int x : pre) cout << x << " ";
  cout << "\n";

  cout << "Combined Inorder  : ";
  for (int x : in) cout << x << " ";
  cout << "\n";

  cout << "Combined Postorder: ";
  for (int x : post) cout << x << " ";
  cout << "\n";

  cout << "==============================" << endl;
  cout << "        Program Ended         " << endl;
  cout << "==============================" << endl;

  return 0;
}
