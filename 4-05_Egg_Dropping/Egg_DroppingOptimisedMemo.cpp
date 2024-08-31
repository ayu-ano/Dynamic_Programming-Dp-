#include <bits/stdc++.h>
using namespace std;
//  failed in Leetcode Hard  but pass in gfg
class Solution {
public:
    int memo[201][201];

    // Helper function to solve the problem using recursion + memoization with binary search
    int solve(int eggs, int floors) {
        // Base cases
        if (floors == 0 || floors == 1) {
            return floors;
        }
        if (eggs == 1) {
            return floors;
        }
        if (memo[eggs][floors] != -1) {
            return memo[eggs][floors];
        }

        int low = 1, high = floors, result = INT_MAX;

        // Binary search to find the optimal floor to drop the egg from
        while (low <= high) {
            int mid = (low + high) / 2;

            // Check if results are already computed in the memo table
            int egg_broke, egg_not_broke;

            if (memo[eggs - 1][mid - 1] != -1) {
                egg_broke = memo[eggs - 1][mid - 1];  // Egg breaks
            } else {
                egg_broke = solve(eggs - 1, mid - 1);
                memo[eggs - 1][mid - 1] = egg_broke;
            }

            if (memo[eggs][floors - mid] != -1) {
                egg_not_broke = memo[eggs][floors - mid];  // Egg doesn't break
            } else {
                egg_not_broke = solve(eggs, floors - mid);
                memo[eggs][floors - mid] = egg_not_broke;
            }

            int temp = 1 + max(egg_broke, egg_not_broke);  // Worst-case scenario

            // Update the minimum result
            result = min(result, temp);

            // Use binary search to minimize the worst-case scenario
            if (egg_broke > egg_not_broke) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return memo[eggs][floors] = result;
    }

    // Function to find minimum number of attempts needed
    int eggDrop(int eggs, int floors) {
        memset(memo, -1, sizeof(memo));
        return solve(eggs, floors);
    }
};

// Main function to test the code
int main() {
    Solution sol;
    int eggs = 2;
    int floors = 10;

    cout << "Minimum number of attempts needed (Optimized Memo with Binary Search): " << sol.eggDrop(eggs, floors) << endl;
    
    return 0;
}
