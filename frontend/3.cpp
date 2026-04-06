#include <bits/stdc++.h>
using namespace std;

/*
DFS Traversal of a graph
Handles disconnected graphs also
*/

void dfs(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &result) {
    visited[node] = 1;
    result.push_back(node);

    for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, result);
        }
    }
}

int main() {
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    // Optional: sort adjacency list for consistent output
    for (int i = 0; i < V; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    vector<int> visited(V, 0);
    vector<int> result;

    // Important: handles disconnected graphs
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, result);
        }
    }

    cout << "\nDFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }

    return 0;
}