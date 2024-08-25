#include <iostream>
#include <string>
using namespace std;

void printAllSubsequences(string str, string current, int index) {
    if (index == str.size()) {
        // Base case: when we've considered all characters
        cout << "\"" << current << "\"" << endl;
        return;
    }

    // Include the current character
    printAllSubsequences(str, current + str[index], index + 1);
    
    // Exclude the current character
    printAllSubsequences(str, current, index + 1);
}

int main() {
    string str = "abc";
    cout << "All subsequences including the empty string:" << endl;
    printAllSubsequences(str, "", 0);
    return 0;
}
