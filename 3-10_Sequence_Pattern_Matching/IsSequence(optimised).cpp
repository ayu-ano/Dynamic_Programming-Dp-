#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isSubSequence(string A, string B) {
        int n = A.length();
        int m = B.length();
        
        int i = 0; // Pointer for string A
        int j = 0; // Pointer for string B
        
        // Traverse through string B
        while (j < m) {
            // If characters match, move both pointers
            if (A[i] == B[j]) {
                i++;
            }
            // Move pointer for B
            j++;
            // If we have matched all characters of A
            if (i == n) {
                return true;
            }
        }
        
        // If all characters of A were not matched
        return i == n;
    }
};

int main() {
    Solution sol;
    string A = "abc";
    string B = "ahbgdc";
    cout << (sol.isSubSequence(A, B) ? "True" : "False") << endl; // Output: True
    return 0;
}
