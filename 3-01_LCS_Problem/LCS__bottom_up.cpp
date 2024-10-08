#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <string>


class Solution {
public:
    // Function to find the length of the longest common subsequence using bottom-up DP
    int lcs(string str1, string str2) {
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

        // The final value at dp[n][m] will be the length of the longest common subsequence
        return dp[n][m];
    }
};

// Main function with hardcoded values for testing the bottom-up LCS
int main() {
    Solution sol;

    // Example hardcoded input strings
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";

    // Call the bottom-up LCS function and display the result
    int result = sol.lcs(str1, str2);
    cout << "Length of Longest Common Subsequence is: " << result << endl;

    return 0;
}
