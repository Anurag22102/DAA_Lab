#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;


const int INF = 1e9;


int tsp(const vector<vector<int>>& graph, int n) {
    vector<vector<int>> dp(1 << n, vector<int>(n, INF));
    dp[1][0] = 0;


    for (int mask = 1; mask < (1 << n); mask++) {
        for (int u = 0; u < n; u++) {
            if ((mask & (1 << u)) == 0) continue;
            for (int v = 0; v < n; v++) {
                if (u == v || (mask & (1 << v))) continue;
                dp[mask | (1 << v)][v] = min(dp[mask | (1 << v)][v], dp[mask][u] + graph[u][v]);
            }
        }
    }


    int ans = INF;
    for (int i = 0; i < n; i++) {
        ans = min(ans, dp[(1 << n) - 1][i] + graph[i][0]);
    }
    return ans;
}


int main() {
    int n = 4;
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };


    int minCost = tsp(graph, n);
    cout << "Minimum cost to visit all cities: " << minCost << endl;


    return 0;
}
