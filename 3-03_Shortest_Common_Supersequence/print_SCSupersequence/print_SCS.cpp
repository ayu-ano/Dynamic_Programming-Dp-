#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to find the length of the shortest common supersequence
string print_shortestCommonSupersequence(string str1, string str2) {
     int n = str1.length();
        int m = str2.length();

        // Create a DP table to store the length of the longest common subsequence (LCS)
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
                 cout<< "Before DP fill up "<<endl;
        for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++){
          cout<< dp[i][j] << " ";
        }
        cout<<endl;
        
        }
         cout<<endl;

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

                 cout<< "After DP fill up "<<endl;
        for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++){
          cout<< dp[i][j] << " ";
        }
        cout<<endl;
        
        }
         cout<<endl;

        // Reconstruct the shortest common supersequence
        string ans = "";
        int i = n, j = m;

        // Trace back the DP table to build the result
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                ans.push_back(str1[i - 1]);
                i--;
                j--;
            } else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    ans.push_back(str1[i - 1]);
                    i--;
                } else {
                    ans.push_back(str2[j - 1]);
                    j--;
                }
            }
        }

        // Add the remaining characters from both strings
        while (i > 0) {
            ans.push_back(str1[i - 1]);
            i--;
        }
        while (j > 0) {
            ans.push_back(str2[j - 1]);
            j--;
        }

        // Since we built the answer in reverse order, we need to reverse it back
        cout<< "SCS without reverse "<< ans << endl;
        reverse(ans.begin(), ans.end());

        return ans;
    
}

int main() {
    // Hardcoded values for the two strings
    string a = "AGGTAB";
    string b = "GXTXAYB";

    // Output the length of the shortest common supersequence
    string ans = print_shortestCommonSupersequence(a, b);
    cout << "Length of Shortest Common Supersequence: " << ans << endl;

    return 0;
}