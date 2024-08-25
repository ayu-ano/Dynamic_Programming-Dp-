// Note : no. of subsequence = 2^n where n is the length of the string

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> allSubsequences(string str) {
    // Initialize with the empty string as the first subsequence
    vector<string> subsequences = {""};
    
    // Iterate over each character in the string
    for (char ch : str) {
        int currentSize = subsequences.size();
        
        // For each existing subsequence, create a new one by appending the current character
        for (int i = 0; i < currentSize; i++) {
            subsequences.push_back(subsequences[i] + ch);
        }
    }
    
    return subsequences;
}

int main() {
    string str = "abc";
    vector<string> subsequences = allSubsequences(str);

    cout << "All subsequences including the empty string:" << endl;
    for (const string& subseq : subsequences) {
        cout << "\"" << subseq << "\"" << endl;
    }

    return 0;
}
