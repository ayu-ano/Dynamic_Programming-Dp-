#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
// Leetcode Hard (this code run in every platform)


    int eggDrop(int eggs, int floors) {
        // dp[e][f] represents the minimum number of attempts needed with e eggs and f floors
        vector<vector<int>> dp(eggs + 1, vector<int>(floors + 1, 0));

        // If we have 1 egg, we have to do linear search (worst case is dropping from each floor)
        for (int f = 1; f <= floors; ++f) {
            dp[1][f] = f;
        }

        // If we have 0 or 1 floor, we need 0 or 1 attempts respectively
        for (int e = 1; e <= eggs; ++e) {
            dp[e][0] = 0;  // 0 floors need 0 attempts
            dp[e][1] = 1;  // 1 floor needs 1 attempt
        }

        // Fill the rest of the dp table
        for (int e = 2; e <= eggs; ++e) {
            for (int f = 2; f <= floors; ++f) {
                dp[e][f] = INT_MAX;

                // Binary search to find the critical floor
                int low = 1, high = f;
                while (low <= high) {
                    int mid = (low + high) / 2;

                    // If egg breaks, we solve the problem for e-1 eggs and mid-1 floors
                    // If egg doesn't break, we solve the problem for e eggs and f-mid floors
                    int egg_broke = dp[e - 1][mid - 1];
                    int egg_not_broke = dp[e][f - mid];

                    // Take the worst-case scenario
                    int worst = 1 + max(egg_broke, egg_not_broke);

                    // Minimize the number of attempts
                    dp[e][f] = min(dp[e][f], worst);

                    // Adjust the binary search window
                    if (egg_broke > egg_not_broke) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
        }

        // Return the result for e eggs and f floors
        return dp[eggs][floors];
    }
};

// Main function to test the code
int main() {
    Solution sol;
    int eggs = 4;
    int floors = 2000;

    cout << "Minimum number of attempts needed: " << sol.eggDrop(eggs, floors) << endl;
    
    return 0;
}
