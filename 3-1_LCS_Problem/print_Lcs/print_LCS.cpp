#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <string>


class Solution {
public:
    // Function to find the length of the longest common subsequence using bottom-up DP
    string print_lcs(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();

        // Create a 2D DP array to store the length of LCS for subproblems
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

          cout<< "Before DP fill up "<<endl;
        for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++){
          cout<< dp[i][j] << " ";
        }
        cout<<endl;
         cout<<endl;
        }

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

        // // The final value at dp[n][m] will be the length of the longest common subsequence
        // return dp[n][m];

          cout<< "After DP fill up "<<endl;
        for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++){
          cout<< dp[i][j] << " ";
        }
        cout<<endl;
        }

        int i=n;
        int j =m;
        string ans ="";
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans.push_back(str1[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    i--;
                }
                else{
                    j--;
                }
            }
        }
        cout << "without reverse string ans : "<< ans << endl;
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// Main function with hardcoded values for testing the bottom-up LCS
int main() {
    Solution sol;

    // Example hardcoded input strings
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";

    // Call the bottom-up LCS function and display the result
    string result = sol.print_lcs(str1, str2);
    cout << "Length of Longest Common Subsequence is: " << result << endl;

    return 0;
}
