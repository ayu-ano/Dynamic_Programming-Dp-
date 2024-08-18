#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int sum) {
        int N = coins.size();
        vector<vector<int>> dp(N + 1, vector<int>(sum + 1, INT_MAX)); // Initialize with INT_MAX
        dp[0][0] = 0; // Base case: 0 coins needed to make amount 0
        
        // Initialize first column (when sum is 0, 0 coins are needed)
        for(int i = 0; i <= N; i++) {
            dp[i][0] = 0;
        }
        
        // Initialize first row (with no coins, we can't form any amount, except 0)
        for(int j = 1; j <= sum; j++) {
            dp[0][j] = INT_MAX;
        }
        
        // Fill the dp table
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= sum; j++) {
                if (coins[i - 1] <= j) {
                    // Either include the coin or don't include it
                    if (dp[i][j - coins[i - 1]] != INT_MAX) {
                        dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
                    } else {
                        dp[i][j] = dp[i - 1][j]; // Exclude the coin
                    }
                } else {
                    dp[i][j] = dp[i - 1][j]; // Exclude the coin if it's too large
                }
            }
        }
        
        // If the last cell dp[N][sum] is still INT_MAX, it means we can't form the amount
        return dp[N][sum] == INT_MAX ? -1 : dp[N][sum];
    }
};

// Main function with hardcoded values
int main() {
    Solution solution;

    // Hardcoded values
    vector<int> coins = {1, 2, 5}; // Available coin denominations
    int sum = 11; // Target amount

    // Call the coinChange function
    int result = solution.coinChange(coins, sum);

    // Output the result
    if (result == -1) {
        cout << "It is not possible to make the amount " << sum << " with the given coins." << endl;
    } else {
        cout << "The fewest number of coins needed to make the amount " << sum << " is: " << result << endl;
    }

    return 0;
}
