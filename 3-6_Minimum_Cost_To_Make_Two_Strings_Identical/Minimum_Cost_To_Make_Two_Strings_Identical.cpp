#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinCost(string str1, string str2, int costX, int costY) {
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

        // Calculate the cost: insertions * costY + deletions * costX
        return insert * costY + del * costX;
    }
};

int main() {
    // Hardcoded input values
    string str1 = "abcd";
    string str2 = "acdb";
    int costX = 10;  // Cost of deleting a character from str1
    int costY = 20;  // Cost of inserting a character into str1

    // Create an object of the Solution class
    Solution sol;

    // Call the findMinCost function and get the result
    int result = sol.findMinCost(str1, str2, costX, costY);

    // Print the result
    cout << "Minimum cost to make both strings identical: " << result << endl;

    return 0;
}
