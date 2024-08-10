#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int t[101][10001]; 

    bool isSubsetSumUtil(vector<int>& arr, int n, int sum) {
        // Base cases
        if (sum == 0) return true;
        if (n == 0) return false;

        // Check if the result is already computed
        if (t[n][sum] != -1) return t[n][sum];

        // If the current element is greater than the sum, skip it
        if (arr[n-1] > sum) {
            t[n][sum] = isSubsetSumUtil(arr, n-1, sum);
        } else {
          
            t[n][sum] = isSubsetSumUtil(arr, n-1, sum-arr[n-1]) || isSubsetSumUtil(arr, n-1, sum);
        }

        return t[n][sum];
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        memset(t, -1, sizeof(t));

        return isSubsetSumUtil(arr, n, sum);
    }
};

int main() {
    Solution solution;
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    bool result = solution.isSubsetSum(arr, sum);

    cout << "Subset with sum " << sum << (result ? " exists." : " does not exist.") << endl;

    return 0;
}
