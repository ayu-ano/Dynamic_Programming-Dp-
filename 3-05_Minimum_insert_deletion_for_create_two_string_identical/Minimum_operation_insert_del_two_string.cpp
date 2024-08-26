#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations_forInsertion_Deletion_forMakingTwoStrings_Identical(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();

        // Create a 2D DP array to store the length of LCS for subproblems
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // If characters match, take the diagonal value and add 1
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    // If characters don't match, take the maximum of top and left values
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Calculate the number of insertions and deletions
        int insert = m - dp[n][m];  // Insertions needed to make str1 into str2
        int del = n - dp[n][m];     // Deletions needed to make str1 into str2

        // Return total operations (insertions + deletions)
        return insert + del;
    }
};

int main() {
    // Hardcoded input values
    string str1 = "heap";
    string str2 = "pea";

    // Create an object of the Solution class
    Solution sol;

    // Call the minOperations function and get the result
    int result = sol.minOperations_forInsertion_Deletion_forMakingTwoStrings_Identical(str1, str2);

    // Print the result
    cout << "Minimum number of operations: " << result << endl;

    return 0;
}
