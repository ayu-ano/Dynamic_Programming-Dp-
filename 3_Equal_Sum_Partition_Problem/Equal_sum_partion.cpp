#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        
        // Calculate the total sum of the array
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        
        // If the sum is odd, it's impossible to partition into two equal subsets
        if (sum % 2 != 0) {
            return false;
        }
        
        // The target sum for each subset
        sum /= 2;
        
        // Initialize the DP table
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        
        // Base cases: 
        // dp[i][0] = true for all i (sum = 0 can be achieved with an empty subset)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        
        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        // The answer will be in dp[n][sum]
        return dp[n][sum];
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {1, 5, 11, 5};
    cout << "Can partition: " << (solution.canPartition(nums1) ? "true" : "false") << endl;

    // Example 2
    vector<int> nums2 = {1, 2, 3, 5};
    cout << "Can partition: " << (solution.canPartition(nums2) ? "true" : "false") << endl;

    return 0;
}
