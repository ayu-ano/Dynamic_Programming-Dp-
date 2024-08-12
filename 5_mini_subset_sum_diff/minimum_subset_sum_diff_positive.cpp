#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int minDifference(int arr[], int n)  { 
    int sum = 0;
    for(int i = 0; i < n; i++) sum += arr[i];
    
    bool t[n+1][sum+1];
    // Initializing Subset Sum Table
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < sum+1; j++){
            if(i == 0) t[i][j] = 0; 
            if(j == 0) t[i][j] = 1; // Sum zero is possible for every array size
        }
    }
    
    // Filling up the table
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < sum+1; j++){
            if(arr[i-1] <= j){
                t[i][j] = (t[i-1][j-arr[i-1]] || t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    int ans = INT_MAX;
    // All the subset sums which are possible for this n sized array will have true value in table in nth row
    for(int j = 0; j < sum+1; j++) {
        if(t[n][j] == 1) 
            ans = min(ans, abs(sum - 2*j));
    }
    
    return ans;
}

int main() {
    // Hard-coded values
    int arr[] = {1, 6, 11, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int result = minDifference(arr, n);
    cout << "The minimum difference between two subsets is: " << result << endl;
    
    return 0;
}
