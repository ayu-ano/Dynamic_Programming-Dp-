#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // Function to find the length of the longest common subsequence in two strings using recursion
    int lcs(int n, int m, string &str1, string &str2) {
        // base case: if either string is empty, the LCS length is 0
        if (n == 0 || m == 0) {
            return 0;
        }

        // if the last characters of both strings match, increment the result and move diagonally
        if (str1[n - 1] == str2[m - 1]) {
            return 1 + lcs(n - 1, m - 1, str1, str2);
        } else {
            // if they don't match, take the maximum of two possibilities: move left or move up
            return max(lcs(n, m - 1, str1, str2), lcs(n - 1, m, str1, str2));
        }
    }
};

// Main function with hardcoded values for testing the recursive LCS
int main() {
    Solution sol;

    // Example hardcoded input strings
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";

    // Get the lengths of both strings
    int n = str1.length();
    int m = str2.length();

    // Call the recursive lcs function and display the result
    int result = sol.lcs(n, m, str1, str2);
    cout << "Length of Longest Common Subsequence is: " << result << endl;

    return 0;
}
