#include <bits/stdc++.h>
using namespace std;

void adjMatrix() {
  int n, m;
  cout << "Enter the no. of Nodes and Edges: ";
  cin >> n >> m;

  // Standard adjacency matrix

  // int adj[n+1][n+1]={0};
  // vector<int> adj[n+1]={0};

  vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));

  cout << "Enter the edges:\n";
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u][v] = 1;
    adj[v][u] = 1;  // undirected graph
  }

  cout << "\nAdjacency Matrix:\n";
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << adj[i][j] << " ";
    }
    cout << "\n";
  }
}

void adjList() {
  int n, m;
  cout << "Enter number of nodes and edges: ";
  cin >> n >> m;

  // Adjacency list (1-based indexing)
  vector<vector<int>> adj(n + 1);

  cout << "Enter the edges:\n";
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);  // undirected graph
  }

  cout << "\nAdjacency List:\n";
  for (int i = 1; i <= n; i++) {
    cout << i << " -> ";

    for (auto& neighbor : adj[i]) {
      cout << neighbor << " ";
    }

    cout << "\n";
  }
}

int main() {
  cout << "Hello, Graph Data Structure!" << endl;
  // adjMatrix();
  adjList();
  return 0;
}
