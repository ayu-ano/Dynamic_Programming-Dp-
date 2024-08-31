#include <iostream>
#include <string>
#include <unordered_map>

// memoised by map 
using namespace std;

class Solution {
public:
    bool solve(const string &s1, const string &s2, unordered_map<string, bool> &memo) {
        // Base case: If the strings are equal
        if (s1 == s2) return true;
        // If the lengths are not the same or one of the strings is empty
        if (s1.length() != s2.length() || s1.empty()) return false;
        
        // Create a unique key for the current pair of strings
        string key = s1 + "|" + s2;
        // Check if the result is already computed
        if (memo.find(key) != memo.end()) return memo[key];

        int n = s1.length();
        bool flag = false;
        for (int i = 1; i < n; i++) {
            // Check if swapping parts
            if ((solve(s1.substr(0, i), s2.substr(n - i, i), memo) &&
                 solve(s1.substr(i, n - i), s2.substr(0, n - i), memo)) ||
                (solve(s1.substr(0, i), s2.substr(0, i), memo) &&
                 solve(s1.substr(i, n - i), s2.substr(i, n - i), memo))) {
                flag = true;
                break;
            }
        }
        // Store the result in the memoization table
        memo[key] = flag;
        return flag;
    }

    bool isScramble(string s1, string s2) {
        unordered_map<string, bool> memo;
        return solve(s1, s2, memo);
    }
};

int main() {
    Solution sol;

    // Test cases
    string s1 = "great";
    string s2 = "rgeat";
    cout << "Is '" << s1 << "' a scramble of '" << s2 << "'? " << (sol.isScramble(s1, s2) ? "Yes" : "No") << endl;

    s1 = "abcde";
    s2 = "caebd";
    cout << "Is '" << s1 << "' a scramble of '" << s2 << "'? " << (sol.isScramble(s1, s2) ? "Yes" : "No") << endl;

    s1 = "a";
    s2 = "a";
    cout << "Is '" << s1 << "' a scramble of '" << s2 << "'? " << (sol.isScramble(s1, s2) ? "Yes" : "No") << endl;

    s1 = "a";
    s2 = "b";
    cout << "Is '" << s1 << "' a scramble of '" << s2 << "'? " << (sol.isScramble(s1, s2) ? "Yes" : "No") << endl;

    return 0;
}
