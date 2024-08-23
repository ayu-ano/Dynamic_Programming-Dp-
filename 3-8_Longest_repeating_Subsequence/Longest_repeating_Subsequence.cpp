
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int LongestRepeatingSubsequence(string str) {
        int n = str.length();
        // Create a 2D DP table to store the length of LCS for subproblems
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // If characters match and their indices are different
                if (str[i - 1] == str[j - 1] && i != j) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    // If characters don't match, take the maximum of top and left values
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // The value at dp[n][n] will be the length of the longest repeating subsequence
        return dp[n][n];
    }
};

int main() {
    Solution sol;

    // Test case 1
    string str1 = "axxzxy";
    cout << "Longest Repeating Subsequence length for \"" << str1 << "\": " 
         << sol.LongestRepeatingSubsequence(str1) << endl;  // Output: 2

    // Test case 2
    string str2 = "aab";
    cout << "Longest Repeating Subsequence length for \"" << str2 << "\": " 
         << sol.LongestRepeatingSubsequence(str2) << endl;  // Output: 1

    // Test case 3
    string str3 = "abc";
    cout << "Longest Repeating Subsequence length for \"" << str3 << "\": " 
         << sol.LongestRepeatingSubsequence(str3) << endl;  // Output: 0

    return 0;
}
