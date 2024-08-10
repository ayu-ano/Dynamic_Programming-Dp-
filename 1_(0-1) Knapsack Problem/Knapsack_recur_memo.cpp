#include <bits/stdc++.h>
using namespace std;

int t[101][1001];

int solve(vector<int> &wt, vector<int> &val, int n, int W) {
    // Base case: If no items are left or the capacity is 0
    if (n == 0 || W == 0) {
        return 0;
    }
    
    // Check if the result is already computed
    if (t[n][W] != -1) {
        return t[n][W];
    }
    
    // If the weight of the nth item is less than or equal to W
    if (wt[n-1] <= W) {
        // Return the maximum of including or excluding the nth item
        return t[n][W] = max(
            val[n-1] + solve(wt, val, n-1, W - wt[n-1]),
            solve(wt, val, n-1, W)
        );
    } else {
        // If the weight of the nth item is more than W, exclude it
        return t[n][W] = solve(wt, val, n-1, W);
    }
}

int knapsack(vector<int> wt, vector<int> val, int n, int W) {
    // Initialize the memoization table with -1
    memset(t, -1, sizeof(t));
    
    // Call the solve function to compute the result
    return solve(wt, val, n, W);
}

int main() {
    vector<int> wt = {4, 5, 1};
    vector<int> val = {1, 2, 3};
    int W = 4;
    int n = wt.size();
    
    cout << "Maximum value in Knapsack: " << knapsack(wt, val, n, W) << endl;
    
    return 0;
}
