#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for std::max

using namespace std;

class Solution {
  public:
    string print_longestCommonSubstr(string str1, string str2) {
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

        int maxLength = 0; // Variable to store the maximum length of common substring
        int endIndex = 0;

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // If characters match, take the diagonal value and add 1
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                     if (dp[i][j] > maxLength) {
                        maxLength = dp[i][j];
                        endIndex = i - 1; // Update the end index of the longest substring
                    }// Track the maximum length
                } else {
                    // If characters don't match, set dp[i][j] to 0
                    dp[i][j] = 0;
                }
            }
        }

          cout<< "After DP fill up "<<endl;
        for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++){
          cout<< dp[i][j] << " ";
        }
        cout<<endl;
         cout<<endl;
        }

           string ans = "";
        if (maxLength > 0) {
            int i = endIndex;
            while (maxLength--) {
                ans.push_back(str1[i]);
                i--;
            }
        }

        cout << "Without reversing, the substring is: " << ans << endl;

        // Reverse the string to get the correct order
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    // Hardcoded strings
    string str1 = "abcde";
    string str2 = "abfce";

    Solution sol;
    string result = sol.print_longestCommonSubstr(str1, str2);

    // Output the result
    cout << "The length of the longest common substring is: " << result << endl;

    return 0;
}
