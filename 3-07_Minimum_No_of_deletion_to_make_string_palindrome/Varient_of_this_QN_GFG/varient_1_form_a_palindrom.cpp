#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int form_a_palindrom_in_minInsertions(string str1) {
        string str2 = "";
        int n = str1.length();
        
        // Create the reverse of the input string
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
        return n - dp[n][n];   
    }
};

int main() {
    // Hardcoded input values
    Solution sol;

    // Test case 1
    string s1 = "abcd";
    cout << "Minimum insertions for \"" << s1 << "\": " << sol.form_a_palindrom_in_minInsertions(s1) << endl;  // Output: 3

    // Test case 2
    string s2 = "mbadm";
    cout << "Minimum insertions for \"" << s2 << "\": " << sol.form_a_palindrom_in_minInsertions(s2) << endl;  // Output: 2

    // Test case 3
    string s3 = "leetcode";
    cout << "Minimum insertions for \"" << s3 << "\": " << sol.form_a_palindrom_in_minInsertions(s3) << endl;  // Output: 5
    
    string s4 = "zzazz";
    cout << "Minimum insertions for \"" << s1 << "\": " << sol.form_a_palindrom_in_minInsertions(s4) << endl;  // Output: 0

    return 0;
}
