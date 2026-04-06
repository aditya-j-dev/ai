#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E, S, D;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    cout << "Enter source and destination: ";
    cin >> S >> D;

    vector<vector<int>> adj(V);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    // BFS setup
    vector<int> dist(V, -1);     // distance array
    vector<int> parent(V, -1);   // to reconstruct path
    queue<int> q;

    // start BFS from source
    q.push(S);
    dist[S] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto neighbor : adj[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }

    // check if destination is reachable
    if (dist[D] == -1) {
        cout << "\nNo path exists!\n";
        return 0;
    }

    cout << "\nShortest Distance: " << dist[D] << endl;

    // reconstruct path
    vector<int> path;
    int curr = D;

    while (curr != -1) {
        path.push_back(curr);
        curr = parent[curr];
    }

    reverse(path.begin(), path.end());

    cout << "Path: ";
    for (int node : path)
        cout << node << " ";

    return 0;
}