#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

// this code trow error MLE (Memory Limit Exceeded)
class Solution {
public:
     vector<string> allSubsequences(string &str) {
    vector<string> subsequences = {""};
    
  
    for (char ch : str) {
        int currentSize = subsequences.size();
        
        for (int i = 0; i < currentSize; i++) {
            subsequences.push_back(subsequences[i] + ch);
        }
    }
    
    return subsequences;
}
    int numMatchingSubseq(string s, vector<string>& words) {
      int count =0;
        vector<string> seq = allSubsequences(s);
        unordered_map<string,int>mp;
        for(auto it : seq){
          mp[it]++;
        }
            
            for(auto it : words ){
              if(mp.find(it)!=mp.end()){
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

