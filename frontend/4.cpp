#include <bits/stdc++.h>
using namespace std;

/*
Problem:
Campus buildings: A, B, C, D, E, F
Edges:
A->B, A->C, B->D, B->E, C->F

Tasks:
1. Perform DFS from A
2. Show traversal order
3. Explain why DFS is suitable
*/

// DFS function
void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& result) {
    visited[node] = 1;
    result.push_back(node);

    for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, result);
        }
    }
}

int main() {

    int V = 6; // A, B, C, D, E, F

    vector<vector<int>> adj(V);

    // Constructing graph
    adj[0].push_back(1); // A -> B
    adj[0].push_back(2); // A -> C
    adj[1].push_back(3); // B -> D
    adj[1].push_back(4); // B -> E
    adj[2].push_back(5); // C -> F

    vector<int> visited(V, 0);
    vector<int> result;

    // Start DFS from A (node 0)
    dfs(0, adj, visited, result);

    // Task 2: Print traversal order
    cout << "DFS Traversal Order: ";
    for (int node : result) {
        cout << char('A' + node) << " ";
    }

    return 0;
}