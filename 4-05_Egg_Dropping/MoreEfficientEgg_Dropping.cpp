#include <bits/stdc++.h>
using namespace std;


// Leetcode Hard (this code run in every platform)
class Solution {
public:
  int maxfloors(int x, int e){
       
        if(x == 0 || e == 0){
            return 0;
        }
        if(e == 1){
            return x;
        }
        return maxfloors(x-1, e-1) + maxfloors(x-1, e)+1;
    }
    int superEggDrop(int k, int n) {
        int res =0;
        for(int i = 0; i <= n; i++){
            if(maxfloors(i, k)>= n){
                return i;
            }
        }
        return res;
    }
};


int main() {
    Solution sol;
    int eggs = 2;
    int floors = 10;

    cout << "Minimum number of attempts needed (Optimized Memo with Binary Search): " << sol.superEggDrop(eggs, floors) << endl;
    
    return 0;
}