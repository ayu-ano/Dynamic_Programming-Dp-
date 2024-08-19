#include <bits/stdc++.h>
#include <iostream>
#include <cstring> // for memset
#include <string>  // for string

using namespace std;
class Solution {
public:
    int t[1001][1001];

    // Function to find the length of the longest common subsequence in two strings.
    int solve(int n, int m, string &str1, string &str2) {
        // base case
        if (n == 0 || m == 0) {
            return 0;
        }

        // if already computed, return the value from the memoization table
        if (t[n][m] != -1) {
            return t[n][m];
        }

        // if characters match, move diagonally in the grid and add 1 to result
        if (str1[n - 1] == str2[m - 1]) {
            t[n][m] = 1 + solve(n - 1, m - 1, str1, str2);
        } else {
            // if characters don't match, take the max of two possible moves (left and up)
            t[n][m] = max(solve(n, m - 1, str1, str2), solve(n - 1, m, str1, str2));
        }

        return t[n][m];
    }

    // Initializes the memoization table and starts the LCS calculation
    int lcs(int n, int m, string str1, string str2) {
        memset(t, -1, sizeof(t)); // initialize the memoization table with -1
        return solve(n, m, str1, str2);
    }
};

// Main function with hardcoded values for testing the LCS
int main() {
    Solution sol;

    // Example hardcoded input strings
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";

    // Get the lengths of both strings
    int n = str1.length();
    int m = str2.length();

    // Call the lcs function and display the result
    int result = sol.lcs(n, m, str1, str2);
    cout << "Length of Longest Common Subsequence is: " << result << endl;

    return 0;
}
