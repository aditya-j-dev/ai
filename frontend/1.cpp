#include <bits/stdc++.h>
using namespace std;

/*
BFS Traversal with user-friendly input prompts
*/

class Solution {
public:
    vector<int> bfs(int V, vector<vector<int>> &adj) {

        vector<int> result;
        vector<int> visited(V, 0);
        queue<int> q;

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {

                q.push(i);
                visited[i] = 1;

                while(!q.empty()) {
                    int node = q.front();
                    q.pop();

                    result.push_back(node);

                    for(auto neighbor : adj[node]) {
                        if(!visited[neighbor]) {
                            visited[neighbor] = 1;
                            q.push(neighbor);
                        }
                    }
                }
            }
        }

        return result;
    }
};

int main() {
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);

    cout << "Enter edges (u v):\n";
    cout << "(Each line represents an undirected edge)\n";

    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Solution obj;
    vector<int> result = obj.bfs(V, adj);

    cout << "\nBFS Traversal: ";
    for(int node : result)
        cout << node << " ";

    return 0;
}