#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsetSum(vector<int> arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));

        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < sum + 1; j++) {
                if (i == 0) {
                    dp[i][j] = false;
                }
                if (j == 0) {
                    dp[i][j] = true;
                }
            }
        }

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < sum + 1; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][sum];
    }
};

int main() {
    Solution solution;
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    bool result = solution.isSubsetSum(arr, sum);

    cout << "Subset with sum " << sum << (result ? " exists." : " does not exist.") << endl;

    return 0;
}
