#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int N, int W, vector<int> &val, vector<int> &wt) {
    vector<vector<int>> dp(N+1,vector<int>(W+1));
        
        for(int i =0; i< N+1; i++){
            for(int j =0; j<W+1; j++){
                if(i ==0){
                    dp[i][j]=0;
                }
                if(j == 0){
                    dp[i][j]=0;
                }
            }
        }
        
        
            for(int i =1; i< N+1; i++){
            for(int j =1; j<W+1; j++){
                if(wt[i-1]<=j){
                    dp[i][j]= max(val[i-1]+dp[i][j-wt[i-1]] , dp[i-1][j]);
                }
                else{
                    
                 dp[i][j]= dp[i-1][j];
                }
            }
        }
        
        return dp[N][W];
}

int main() {
    int N = 3; // number of items
    int W = 10; // maximum weight capacity
    vector<int> val = {10, 40, 50}; // values of items
    vector<int> wt = {1, 3, 4}; // weights of items

    int maxProfit = unboundedKnapsack(N, W, val, wt);
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}