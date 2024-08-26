#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wildCard(string pattern, string str) {
        int n = pattern.length();
        int m = str.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // Base case: Empty pattern matches empty string
        dp[0][0] = true;

             cout<< "Before DP fill up "<<endl;
        for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++){
          cout<< dp[i][j] << " ";
        }
        cout<<endl;
       
        }
          cout<<endl;

        // Handle the case when pattern contains only '*' characters
        for (int i = 1; i <= n; i++) {
            if (pattern[i - 1] == '*') {
                dp[i][0] = dp[i - 1][0];
            }
        }


 cout<< "after Handle the case when pattern contains only '*' characters DP fill up "<<endl;
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
                if (pattern[i - 1] == str[j - 1] || pattern[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (pattern[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = false;
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

        // Result is whether the full pattern matches the full string
        return dp[n][m];
    }
};

int main() {
    Solution sol;
    // string pattern = "a*b";
    // string str = "axxb";
    // cout << sol.wildCard(pattern, str) << endl; // Output depends on the pattern and string

    string str1 = "baaabab";
    string pattern1 = "*****ba*****ab";
    cout << sol.wildCard(pattern1, str1) << endl;
    return 0;
}
