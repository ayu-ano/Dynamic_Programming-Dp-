#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int t[501][501]; // DP table

    // Function to check if a substring from index i to j is a palindrome
    bool ispalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    // Recursive function to find the minimum cuts for palindromic partitioning
    int solve(string &s, int i, int j) {
        if (i >= j || ispalindrome(s, i, j)) {
            return 0;  // No cuts needed if the substring is already a palindrome
        }

        if (t[i][j] != -1) {
            return t[i][j];  // Return cached result if already computed
        }

        int mn = INT_MAX;

        for (int k = i; k < j; k++) {
            int left, right;

            // Checking if we have already computed the value for solve(s, i, k)
            if (t[i][k] != -1)
                left = t[i][k];
            else
                left = solve(s, i, k);

            // Checking if we have already computed the value for solve(s, k+1, j)
            if (t[k + 1][j] != -1)
                right = t[k + 1][j];
            else
                right = solve(s, k + 1, j);

            // Calculate minimum cuts for this partition
            int temp = left + right + 1;
            mn = min(mn, temp);
        }

        return t[i][j] = mn;  // Store the result in the DP table
    }

    int palindromicPartition(string str) {
        int n = str.size();
        memset(t, -1, sizeof(t));  // Initialize DP table with -1
        return solve(str, 0, n - 1);  // Solve for the entire string
    }
};

int main() {
    Solution solution;

    // Hardcoded test case
    string str = "ababbbabbababa";
    
    cout << "Minimum cuts needed for Palindrome Partitioning: " << solution.palindromicPartition(str) << endl;

    return 0;
}
