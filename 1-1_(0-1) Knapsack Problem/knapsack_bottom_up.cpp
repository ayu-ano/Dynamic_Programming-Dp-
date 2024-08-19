#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> wt, vector<int> val, int n, int W) {
    // Initialize a 2D vector to store the results of subproblems
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    // Initialize the dp array
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;  // Base case: no items or capacity 0
            }
        }
    }

    // Fill the dp array using the bottom-up approach
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (wt[i - 1] <= j) {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // The last cell of the dp array will have the maximum value
    return dp[n][W];
}

int main() {
    vector<int> wt = {4, 5, 1};  // Weights of the items
    vector<int> val = {1, 2, 3};  // Values of the items
    int W = 4;  // Capacity of the knapsack
    int n = wt.size();  // Number of items

    // Call the knapsack function and print the result
    cout << "Maximum value in Knapsack: " << knapsack(wt, val, n, W) << endl;

    return 0;
}
