#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long perfectSum(vector<int>& arr, int n, int sum) {
        const int MOD = 1e9 + 7;
        
        // Handle the case where sum is negative or too large
        if (sum < 0) return 0;

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

    long long findTargetSumWays(int n, vector<int>& arr, int d) {
        int sum1 = 0;
        for(auto it : arr) {
            sum1 += it;
        }

        // Calculate the target sum for the subset
        if ((d + sum1) % 2 != 0 || (d + sum1) < 0) 
            return 0;

        int sum = (sum1 + d) / 2;

        return perfectSum(arr, n, sum);
    }
};

int main() {
    Solution sol;

    // Hard-coded values
    vector<int> arr = {1, 2, 3, 4, 5};
    int d = 3;
    int n = arr.size();
    
    long long result = sol.findTargetSumWays(n, arr, d);
    cout << "The number of ways to partition the array with target difference " << d << " is: " << result << endl;
    
    return 0;
}
