#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to find the length of the shortest common supersequence
int shortestCommonSupersequence(string a, string b) {
    int n = a.length();
    int m = b.length();

    // Create a DP table to store the length of the longest common subsequence (LCS)
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // The length of the shortest common supersequence is (n + m) - length of LCS
    return (m + n) - dp[n][m];
}

int main() {
    // Hardcoded values for the two strings
    string a = "AGGTAB";
    string b = "GXTXAYB";

    // Output the length of the shortest common supersequence
    cout << "Length of Shortest Common Supersequence: " << shortestCommonSupersequence(a, b) << endl;

    return 0;
}
