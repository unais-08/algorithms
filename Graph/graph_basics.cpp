#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << "Hello, Graph Data Structure!" << endl;

  int n, m;
  cout << "Enter the no. of Nodes and Edges: ";
  cin >> n >> m;

  // Standard adjacency matrix
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

  return 0;
}
