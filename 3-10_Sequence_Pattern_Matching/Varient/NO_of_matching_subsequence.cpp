#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;


// Optimised one 
class Solution {
public:
    // Helper function to check if 'word' is a subsequence of 's'
    bool isSubsequence(const string &s, const string &word) {
        int i = 0, j = 0;
        while (i < s.size() && j < word.size()) {
            if (s[i] == word[j]) {
                j++;  // Move to the next character in word
            }
            i++;  // Move to the next character in s
        }
        return j == word.size();  // If we've checked all of word, it's a subsequence
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        unordered_map<string, int> wordFreq;

        // Build the hashmap: count the occurrences of each word
        for (const string &word : words) {
            wordFreq[word]++;
        }

        // For each unique word in the map, check if it is a subsequence of s
        for (const auto &entry : wordFreq) {
            const string &word = entry.first;
            int frequency = entry.second;

            if (isSubsequence(s, word)) {
                count += frequency;  // Multiply by the frequency of the word
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
