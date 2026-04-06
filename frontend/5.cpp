#include <bits/stdc++.h>
using namespace std;

/*
TSP using Bitmask DP + Path Reconstruction
*/

const int INF = 1e9;

int n;
vector<vector<int>> dist;
vector<vector<int>> dp;
vector<vector<int>> parent; // to store next city

int tsp(int mask, int pos) {

    if (mask == (1 << n) - 1) {
        return dist[pos][0];
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;
    int bestCity = -1;

    for (int city = 0; city < n; city++) {

        if ((mask & (1 << city)) == 0) {

            int newCost = dist[pos][city] +
                          tsp(mask | (1 << city), city);

            if (newCost < ans) {
                ans = newCost;
                bestCity = city; // store best next city
            }
        }
    }

    parent[mask][pos] = bestCity;
    return dp[mask][pos] = ans;
}

int main() {

    cout << "Enter number of cities: ";
    cin >> n;

    dist.assign(n, vector<int>(n));

    cout << "Enter cost matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    dp.assign(1 << n, vector<int>(n, -1));
    parent.assign(1 << n, vector<int>(n, -1));

    int minCost = tsp(1, 0);

    cout << "\nMinimum Travelling Cost: " << minCost << endl;

    // 🔹 Reconstruct path
    vector<int> path;
    int mask = 1, pos = 0;

    path.push_back(0);

    while (true) {
        int next = parent[mask][pos];
        if (next == -1) break;

        path.push_back(next);
        mask |= (1 << next);
        pos = next;
    }

    path.push_back(0); // return to start

    cout << "Path: ";
    for (int city : path) {
        cout << city << " ";
    }

    return 0;
}