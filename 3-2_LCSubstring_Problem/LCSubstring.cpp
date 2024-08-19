#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for std::max

using namespace std;

class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();

        // Create a 2D DP array to store the length of LCS for subproblems
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        int maxLength = 0; // Variable to store the maximum length of common substring

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // If characters match, take the diagonal value and add 1
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    maxLength = max(maxLength, dp[i][j]); // Track the maximum length
                } else {
                    // If characters don't match, set dp[i][j] to 0
                    dp[i][j] = 0;
                }
            }
        }

        // Return the maximum length of the common substring
        return maxLength;
    }
};

int main() {
    // Hardcoded strings
    string str1 = "abcde";
    string str2 = "abfce";

    Solution sol;
    int result = sol.longestCommonSubstr(str1, str2);

    // Output the result
    cout << "The length of the longest common substring is: " << result << endl;

    return 0;
}
