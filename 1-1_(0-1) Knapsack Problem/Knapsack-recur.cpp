#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) {
        // Base case: If there are no items or capacity is 0, the max value is 0.
        if (n == 0 || W == 0) {
            return 0;
        }
        
        if (wt[n-1] <= W) {
            return max(
                val[n-1] + knapSack(W - wt[n-1], wt, val, n-1), // Include the nth item
                knapSack(W, wt, val, n-1)                        // Exclude the nth item
            );
        }
        // If the weight of the nth item is more than W, we cannot include this item.
        else {
            return knapSack(W, wt, val, n-1); // Exclude the nth item
        }
    }
};

int main() {
    Solution solution;
    
    int N = 3; // Number of items
    int W = 4; // Capacity of knapsack
    
    int values[] = {1, 2, 3};  // Values of items
    int weight[] = {4, 5, 1};  // Weights of items
    
    // Function call to get the maximum value that can be put in knapsack
    int maxValue = solution.knapSack(W, weight, values, N);
    
    cout << "Maximum value in Knapsack: " << maxValue << endl;
    
    return 0;
}
