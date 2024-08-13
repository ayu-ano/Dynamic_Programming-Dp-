#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
// code usage of qn. count_subset_in_sum
    int perfectSum(vector<int>& arr, int n, int sum) {
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
    
    int countPartitions(int n, int d, vector<int>& arr) {
        int sum1 = 0;
        for(auto it : arr) {
            sum1 += it;
        }
        
        if((d + sum1) % 2 != 0) 
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
    
    int result = sol.countPartitions(n, d, arr);
    cout << "The number of ways to partition the array into two subsets with difference " << d << " is: " << result << endl;
    
    return 0;
}
