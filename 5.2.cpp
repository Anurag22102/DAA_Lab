#include <iostream>
#include <vector>
#include <climits>


using namespace std;


int cost(const vector<int>& freq, int i, int j) {
    int sum = 0;
    for (int k = i; k <= j; k++) {
        sum += freq[k];
    }
    return sum;
}


int constructOBST(const vector<int>& keys, const vector<int>& freq) {
    int n = keys.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));


    for (int i = 0; i < n; i++) {
        dp[i][i] = freq[i];
    }


    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? dp[i][r - 1] : 0) +
                        ((r < j) ? dp[r + 1][j] : 0) + cost(freq, i, j);
                if (c < dp[i][j]) {
                    dp[i][j] = c;
                }
            }
        }
    }
    return dp[0][n - 1];
}


int main() {
    vector<int> keys = {10, 12, 20, 35};
    vector<int> freq = {34, 8, 50, 25};
    int minCost = constructOBST(keys, freq);
    cout << "The cost of constructing optimal BST is: " << minCost << endl;
    return 0;
}
