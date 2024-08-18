#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int sum) {
        int N = coins.size();
        vector<vector<int>> dp(N + 1, vector<int>(sum + 1, INT_MAX - 1)); // Initialize with INT_MAX-1
        dp[0][0] = 0; 
        
        // Initialize the dp array for base cases
        for (int i = 0; i <= N; i++) {
            dp[i][0] = 0;
        }

        for (int j = 1; j <= sum; j++) {
            if (j % coins[0] == 0) {
                dp[1][j] = j / coins[0];
            } else {
                dp[1][j] = INT_MAX - 1;  // Use INT_MAX-1 for safety
            }
        }

        // Fill the dp array for other cases
        for (int i = 2; i <= N; i++) {
            for (int j = 1; j <= sum; j++) {
                if (coins[i - 1] <= j) {
                    // Ensure that we don't add to INT_MAX-1
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] == INT_MAX - 1 ? INT_MAX - 1 : dp[i][j - coins[i - 1]] + 1);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[N][sum] == INT_MAX - 1 ? -1 : dp[N][sum];
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
