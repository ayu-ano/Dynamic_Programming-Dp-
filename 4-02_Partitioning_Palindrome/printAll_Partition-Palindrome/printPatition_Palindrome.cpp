#include <bits/stdc++.h> 
using namespace std;

vector<vector<string>> res; // To store the result of all palindrome partitions
vector<string> curr;        // To store the current partition

// Function to check if a string is a palindrome
bool ispalindrome(string &s) {
    int n = s.size();
    int i = 0, j = n - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

// Backtracking function to find all palindrome partitions
void printall_Partition_Palindrome(string &s, int idx, vector<string> &curr, vector<vector<string>> &res) {
    if (idx == s.size()) {
        res.push_back(curr); // If we reach the end, store the current partition
        return;
    }

    string t;
    for (int i = idx; i < s.size(); i++) {
        t.push_back(s[i]); // Form substring
        if (ispalindrome(t)) {  // Check if it's a palindrome
            curr.push_back(t);  // Add to current partition
            printall_Partition_Palindrome(s, i + 1, curr, res);  // Recur for remaining string
            curr.pop_back();  // Backtrack to try other partitions
        }
    }
}

// Function to return all palindrome partitions
vector<vector<string>> partition(string &s) {
    printall_Partition_Palindrome(s, 0, curr, res);
    return res;
}

int main() {
    // Hardcoded test case
    string str = "ababbbabbababa";

    // Get all partitions
    vector<vector<string>> partitions = partition(str);

    // Print all the partitions
    cout << "All possible palindrome partitions: " << endl;
    for (const auto &partition : partitions) {
        for (const auto &palindrome : partition) {
            cout << palindrome << " ";
        }
        cout << endl;
    }



    string str1 = "geeks";

    
    return 0;
}
