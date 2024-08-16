#include <bits/stdc++.h>

using namespace std;

int cutRod(vector<int> &price, int n) {
    // Create a vector for lengths (1 to n)
    vector<int> len;
    for (int i = 1; i <= n; i++) {
        len.push_back(i);
    }

    // Create a DP table with dimensions (n+1) x (n+1)
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (len[i-1] <= j) {
                dp[i][j] = max(price[i-1] + dp[i][j - len[i-1]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][n]; // The maximum profit is stored in dp[n][n]
}

int main() {
    // Hard-coded values
    int n = 8; // Length of the rod
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20}; // Prices for each length

    // Call the cutRod function
    int maxProfit = cutRod(price, n);

    // Output the result
    cout << "The maximum profit that can be obtained is: " << maxProfit << endl;

    return 0;
}
