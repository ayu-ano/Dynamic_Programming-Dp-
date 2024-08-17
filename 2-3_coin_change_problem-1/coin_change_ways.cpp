#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int sum) {
        int N = coins.size();  // Number of different coins
        vector<vector<int>> dp(N + 1, vector<int>(sum + 1, 0)); // DP table initialized to 0

        // Base case: There is 1 way to make a sum of 0 (by using no coins)
        for (int i = 0; i <= N; i++) {
            dp[i][0] = 1;
        }

        // Fill the DP table
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= sum; j++) {
                if (coins[i-1] <= j) {
                    dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[N][sum]; // The answer is in dp[N][sum]
    }
};

int main() {
    Solution solution;

    // Hard-coded coin denominations and target sum
    vector<int> coins = {1, 2, 5};  // Coin denominations
    int sum = 11;  // Target sum

    // Call the coinChange function and output the result
    int ways = solution.coinChange(coins, sum);
    cout << "Number of ways to make sum " << sum << ": " << ways << endl;

    return 0;
}
