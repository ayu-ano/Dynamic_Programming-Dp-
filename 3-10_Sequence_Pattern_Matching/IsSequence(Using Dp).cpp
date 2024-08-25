#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool isSubSequence(string A, string B) 
    {
        // code here
        int n = A.length();
        int m = B.length();
        bool  isSubsequence = false;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        
        // find lcs
        for(int i =1;i<=n;i++){
            for(int j =1;j<=m;j++){
             
             if(A[i-1]==B[j-1]){
                 dp[i][j]= 1+dp[i-1][j-1];
             }   
             else{
                 dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
             }
             
            }
        }
        
        if(dp[n][m]==n){
            return true;
        }
        return  isSubsequence ;
    }
};

int main() {
    Solution sol;
    string A = "abc";
    string B = "ahbgdc";
    cout << (sol.isSubSequence(A, B) ? "True" : "False") << endl; // Output: True
    return 0;
}


// This code TLE Because Here we can solve our problem in O(N); but this code has
// complexity of O(m*n);


// Note : no. of subsequence = 2^n where n is the length of the string