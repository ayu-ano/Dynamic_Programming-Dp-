#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive solution to the egg drop problem
    int solve(int eggs, int floors) {
        // Base cases
        if (floors == 0 || floors == 1) {
            return floors;
        }
        if (eggs == 1) {
            return floors;
        }

        int minimumAttempts = INT_MAX;

        // Try dropping the egg from each floor
        for (int floor = 1; floor <= floors; floor++) {
            int temp = 1 + max(solve(eggs - 1, floor - 1), solve(eggs, floors - floor));
            minimumAttempts = min(temp, minimumAttempts);
        }

        return minimumAttempts;
    }

    // Function to find the minimum number of attempts needed
    int eggDrop(int eggs, int floors) {
        return solve(eggs, floors);
    }
};

// Main function to test the code
int main() {
    Solution sol;
    int eggs = 2;
    int floors = 10;

    cout << "Minimum number of attempts needed (Recursive): " << sol.eggDrop(eggs, floors) << endl;
    
    return 0;
}
