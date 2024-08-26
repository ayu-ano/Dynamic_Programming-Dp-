#include <bits/stdc++.h>
using namespace std;

// Memoization table
int dp[1001][1001];

int matrixChainMultiplication(vector<int> &arr, int i, int j) {
    // Base condition: if the matrix chain has less than or equal to one matrix
    if (i >= j) 
        return 0;

    // If the subproblem has already been computed, return the stored result
    if (dp[i][j] != -1) 
        return dp[i][j];

    int mn = INT_MAX;

    // Try placing the partition at each possible position between i and j
    for (int k = i; k <= j - 1; k++) {
        int temp = matrixChainMultiplication(arr, i, k) +
                   matrixChainMultiplication(arr, k + 1, j) +
                   (arr[i - 1] * arr[k] * arr[j]);

        // Update the minimum number of multiplications
        mn = min(temp, mn);
    }

    // Store the result in the memoization table and return
    return dp[i][j] = mn;
}

int main() {
    // Hardcoded dimensions array (matrix dimensions)
    vector<int> arr = {40, 20, 30, 10, 30};
    int n = arr.size();

    // Initialize the memoization table with -1
    memset(dp, -1, sizeof(dp));

    // Minimum number of multiplications required
    cout << "Minimum number of multiplications is: " 
         << matrixChainMultiplication(arr, 1, n - 1) << endl;

    return 0;
}
