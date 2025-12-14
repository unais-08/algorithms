#include <bits/stdc++.h>
using namespace std;
void adjList(vector<vector<int>>& adj, int edges) {
  cout << "Enter the edges:\n";
  for (int i = 0; i < edges; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);  // undirected graph
  }
}

vector<int> bfsTraverse(vector<vector<int>>& adj, int v) {
  vector<int> bfs;
  std::queue<int> q;
  vector<int> visited(v + 1, 0);
  visited[1] = 1;
  q.push(1);

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    bfs.push_back(node);
    for (int& neighbor : adj[node]) {
      if (!visited[neighbor]) {
        visited[neighbor] = 1;
        q.push(neighbor);
      }
    }
  }
  return bfs;
}

void printAdjList(const vector<vector<int>>& adj, int v) {
  cout << "\nAdjacency List:\n";
  for (int i = 1; i <= v; i++) {
    cout << i << " -> ";

    for (auto& neighbor : adj[i]) {
      cout << neighbor << " ";
    }

    cout << "\n";
  }
}
int main() {
  int nodes, edges;
  cout << "Enter number of nodes and edges: ";
  cin >> nodes >> edges;

  // Adjacency list (1-based indexing)
  vector<vector<int>> adj(nodes + 1);

  // creating adjList data structure
  adjList(adj, edges);

  // printing adjList data structure
  printAdjList(adj, nodes);

  // bfs traversal of graph
  vector<int> bfs = bfsTraverse(adj, nodes);

  // printing BFS traversal of graph
  for (int& ele : bfs) cout << ele << " ";
  cout << endl;

  return 0;
}