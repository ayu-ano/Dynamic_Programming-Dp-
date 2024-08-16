#include <bits/stdc++.h>
using namespace std;

// Remember it 

// in this qn. we got stuck to solve due to issue in dp initialisation 

class Solution {
public:
    int perfectSum(int arr[], int n, int sum) {
        const int MOD = 1e9 + 7;

        // Initialize the dp array
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        dp[0][0] = 1; // There's one way to achieve sum 0 with 0 elements (choose none)

        // Fill the dp array
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]) % MOD;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][sum];
    }
};

int main() {
    Solution sol;

    // Example test case
    int arr[] = {9, 7, 0, 3, 9, 8, 6, 5, 7, 6}; // Array elements
    int n = sizeof(arr) / sizeof(arr[0]); // Number of elements in the array
    int sum = 31; // Target sum

    
    int result = sol.perfectSum(arr, n, sum);

    // Output the result
    cout << "Number of subsets with sum " << sum << " is: " << result << endl;

    return 0;
}
