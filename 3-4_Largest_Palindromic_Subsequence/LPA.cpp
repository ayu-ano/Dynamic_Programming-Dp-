#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalinSubseq(string str1) {
        // Reverse the string to compare with the original string
        string str2 = "";
        int n = str1.length();
        for (int i = n - 1; i >= 0; i--) {
            str2.push_back(str1[i]);
        }

        // Create a 2D DP array to store the length of LCS for subproblems
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // If characters match, take the diagonal value and add 1
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    // If characters don't match, take the maximum of top and left values
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // The final value at dp[n][n] will be the length of the longest palindromic subsequence
        return dp[n][n];
    }
};

int main() {
    // Hardcoded input string
    string S = "bbabcbcab";
    
    // Create an object of the Solution class
    Solution sol;
    
    // Call the longestPalinSubseq function and get the result
    int result = sol.longestPalinSubseq(S);
    
    // Print the result
    cout << "Length of the longest palindromic subsequence: " << result << endl;

    return 0;
}
