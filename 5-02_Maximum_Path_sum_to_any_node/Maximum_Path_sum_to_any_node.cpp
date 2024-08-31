#include <iostream>
#include <climits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
  public:
    // Function to return the maximum path sum from any node in a tree
    int solve(TreeNode* root, int &maxi) {
        if (root == NULL) return 0;

        // Recursively get the maximum sum on the left and right subtrees
        int l = solve(root->left, maxi);
        int r = solve(root->right, maxi);

      
        // Find the maximum path sum passing through the current node
        int temp = max(root->val + max(l, r),root->val);  // Maximum path sum including either left or right (or none)
        
        // Max path sum that includes both left and right children
        int ans = max(temp,root->val + l + r);

        // Update the overall maximum path sum
        maxi = max(maxi, ans);

        // Return the path sum starting from the current node
        return temp;
    }

    int findMaxSum(TreeNode* root) {
        int maxi = INT_MIN;
        solve(root, maxi);
        return maxi;
    }
};

int main() {
    // Hardcoding the binary tree
    /*
                -10
                /  \
               9   20
                  /  \
                 15   7
    */
    
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    int result = sol.findMaxSum(root);

    // Output the maximum path sum of the binary tree
    cout << "The maximum path sum is: " << result << endl;

    return 0;
}
