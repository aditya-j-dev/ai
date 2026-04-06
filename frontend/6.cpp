#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// Nodes: 0 = Hospital (H), 1=A, 2=B, 3=C, 4=D, 5=E
int dist[6][6] = {
    {0,12,10,19,8,14},
    {11,0,7,6,12,9},
    {9,8,0,14,10,6},
    {18,5,13,0,INF,11},
    {7,11,9,15,0,8},
    {13,10,6,12,9,0}
};

int dp[1<<5][6];
int parent[1<<5][6]; // to reconstruct path

int tsp(int mask, int u){

    // All cities visited → return to hospital
    if(mask == (1<<5)-1){
        return (dist[u][0] == INF) ? INF : dist[u][0];
    }

    if(dp[mask][u] != -1){
        return dp[mask][u];
    }

    int ans = INF;
    int bestNext = -1;

    for(int v = 1; v <= 5; v++){

        int bit = v - 1;

        // Already visited
        if(mask & (1<<bit)) continue;

        // 🔴 Constraint: B must be visited before C
        // B = node 2 → bit = 1
        // C = node 3 → bit = 2
        if(v == 3 && !(mask & (1<<(2-1)))) continue;

        // Blocked path
        if(dist[u][v] == INF) continue;

        int newCost = dist[u][v] + tsp(mask | (1<<bit), v);

        if(newCost < ans){
            ans = newCost;
            bestNext = v;
        }
    }

    parent[mask][u] = bestNext;
    return dp[mask][u] = ans;
}

int main(){

    memset(dp, -1, sizeof(dp));
    memset(parent, -1, sizeof(parent));

    int minCost = tsp(0, 0);

    cout << "Minimum Cost: " << minCost << endl;

    // 🔹 Reconstruct path
    vector<int> path;
    int mask = 0, u = 0;

    path.push_back(0);

    while(true){
        int next = parent[mask][u];
        if(next == -1) break;

        path.push_back(next);
        mask |= (1 << (next-1));
        u = next;
    }

    path.push_back(0); // return to hospital

    cout << "Path: ";
    for(int node : path){
        if(node == 0) cout << "H ";
        else cout << char('A' + node - 1) << " ";
    }

    return 0;
}