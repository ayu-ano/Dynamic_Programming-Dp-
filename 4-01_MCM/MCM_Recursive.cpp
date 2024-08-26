#include <bits/stdc++.h>
using namespace std;

int matrixChainMultiplication(vector<int> &arr, int i, int j) {
    if (i >= j) 
        return 0;
    
    int mn = INT_MAX;
    
    for (int k = i; k <= j - 1; k++) {
        int temp = matrixChainMultiplication(arr, i, k) +
                   matrixChainMultiplication(arr, k + 1, j) +
                   (arr[i - 1] * arr[k] * arr[j]);
        
        mn = min(temp, mn);
    }
    
    return mn;
}

int main() {
    // Hardcoded dimensions array (matrix dimensions)
    vector<int> arr = {40, 20, 30, 10, 30};
    int n = arr.size();
    
    // Minimum number of multiplications required
    cout << "Minimum number of multiplications is: " 
         << matrixChainMultiplication(arr, 1, n - 1) << endl;

    return 0;
}
