#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Bottom-up dynamic programming solution to the egg drop problem
    int eggDrop(int eggs, int floors) {
        // Create a DP table to store the results
        vector<vector<int>> dp(eggs + 1, vector<int>(floors + 1, 0));

        // Fill the table for 1 egg (we need `floors` attempts in the worst case)
        for (int i = 1; i <= floors; i++) {
            dp[1][i] = i;
        }

        // Fill the table for multiple eggs and floors
        for (int e = 2; e <= eggs; e++) {
            for (int f = 1; f <= floors; f++) {
                dp[e][f] = INT_MAX;
                // Try dropping from every floor
                for (int k = 1; k <= f; k++) {
                    int temp = 1 + max(dp[e - 1][k - 1], dp[e][f - k]);
                    dp[e][f] = min(dp[e][f], temp);
                }
            }
        }

        // Return the result for `eggs` eggs and `floors` floors
        return dp[eggs][floors];
    }
};

// Main function to test the code
int main() {
    Solution sol;
    int eggs = 2;
    int floors = 10;

    cout << "Minimum number of attempts needed (Bottom-Up DP): " << sol.eggDrop(eggs, floors) << endl;
    
    return 0;
}
