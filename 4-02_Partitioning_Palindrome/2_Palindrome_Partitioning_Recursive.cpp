#include <bits/stdc++.h>
using namespace std;
class Solution{
public:


 
// Corrected palindrome function to check substring from index i to j
bool ispalindrome(string &s, int i, int j){
    while(i < j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int solve(string &s, int i, int j){
    if(i >= j){
        return 0;  // No cuts needed if there's only one character or no characters
    }
    
    // Check if the substring from i to j is a palindrome
    if(ispalindrome(s, i, j)){
        return 0;  // No cuts needed if the substring is already a palindrome
    }

  

    int mn = INT_MAX;

    for(int k = i; k <= j-1; k++){
        int temp = solve(s, i, k) + solve(s, k+1, j) + 1;
        mn = min(mn, temp);
    }

    return mn;
}

int palindromicPartition(string str){
    int n = str.size();  // Corrected: Use str.size(), not s.size() 
    return solve(str, 0, n-1);  // Start solving from the entire string
}
};

int main() {
    Solution solution;

    // Hardcoded test case
    string str = "ababbbabbababa";
    
    cout << "Minimum cuts needed for Palindrome Partitioning: " << solution.palindromicPartition(str) << endl;

    return 0;
}