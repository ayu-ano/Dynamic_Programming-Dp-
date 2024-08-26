// this code trow error TLE (Time  Limit Exceeded)

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Helper function to check if 'word' is a subsequence of 's'
    bool isSubsequence(const string &s, const string &word) {
        int i = 0, j = 0;
        
        // Traverse both strings
        while (i < s.size() && j < word.size()) {
            if (s[i] == word[j]) {
                j++;  // Move to the next character in word
            }
            i++;  // Move to the next character in s
        }
        
        // If we reached the end of word, it's a subsequence
        return j == word.size();
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        
        // Check each word in words
        for (const string &word : words) {
            if (isSubsequence(s, word)) {
                count++;
            }
        }
        
        return count;
    }
};





int main() {
    Solution solution;
    string s = "abcde";
    vector<string> words = {"a", "bb", "acd", "ace", "a"};
    
    cout << "Number of matching subsequences: " << solution.numMatchingSubseq(s, words) << endl;

    return 0;
}

