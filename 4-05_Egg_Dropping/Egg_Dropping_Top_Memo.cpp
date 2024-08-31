#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Table for memoization
    int t[201][201];

    // Function to solve the egg drop problem using recursion and memoization
    int solve(int eggs, int floors) {
        // Base case: If there are no floors or only one floor
        if (floors == 0 || floors == 1) {
            return floors;
        }
        // Base case: If there is only one egg, we need to try all floors
        if (eggs == 1) {
            return floors;
        }
        // Check if the result is already calculated
        if (t[eggs][floors] != -1) {
            return t[eggs][floors];
        }

        int minimumAttempts = INT_MAX;

        // Try dropping the egg from each floor and take the worst case
        for (int floor = 1; floor <= floors; floor++) {
            int temp = 1 + max(solve(eggs - 1, floor - 1), solve(eggs, floors - floor));
            minimumAttempts = min(temp, minimumAttempts);
        }
        
        // Store the result and return
        return t[eggs][floors] = minimumAttempts;
    }

    // Function to find the minimum number of attempts needed
    int eggDrop(int eggs, int floors) {
        // Initialize the memoization table with -1
        memset(t, -1, sizeof(t));
        return solve(eggs, floors);
    }
};

// Main function to test the code
int main() {
    Solution sol;
    int eggs = 2; // Number of eggs
    int floors = 10; // Number of floors

    cout << "Minimum number of attempts needed: " << sol.eggDrop(eggs, floors) << endl;
    
    return 0;
}
