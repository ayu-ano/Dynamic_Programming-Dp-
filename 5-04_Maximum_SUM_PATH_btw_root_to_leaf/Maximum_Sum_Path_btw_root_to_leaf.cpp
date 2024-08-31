

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int maxLeafToRootSum(TreeNode<int> *root) {
    if (root == NULL) return 0;

    // Base case: If the node is a leaf, return its value
    if (root->left == NULL && root->right == NULL) {
        return root->val;
    }

    // Recursively get the maximum sum from left and right subtrees
    int leftSum = INT_MIN;
    int rightSum = INT_MIN;

    if (root->left) {
        leftSum = maxLeafToRootSum(root->left);
    }
    if (root->right) {
        rightSum = maxLeafToRootSum(root->right);
    }

    // Return the maximum sum including the current node
    return root->val + max(leftSum, rightSum);
}

int main() {
    // Construct the sample binary tree: 
    //       10
    //      /  \
    //    -20  -30

    TreeNode<int> *root = new TreeNode<int>(10);
    root->left = new TreeNode<int>(-20);
    root->right = new TreeNode<int>(-30);

    int result = maxLeafToRootSum(root);
    
    cout << "Maximum sum from leaf to root: " << result << endl;

    return 0;
}
