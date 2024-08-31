

#include <bits/stdc++.h>
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
    int maxDepth(TreeNode* root, int &maxi) {
        if (root == NULL) {
            return 0;
        }
        int left = maxDepth(root->left, maxi);
        int right = maxDepth(root->right, maxi);
        maxi = max(maxi, left + right);  // Update the diameter
        return max(left, right) + 1;     // Return height of the subtree
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        maxDepth(root, dia);
        return dia;
    }
};

int main() {
    // Hardcoding the binary tree
    /*
                1
               / \
              2   3
             / \
            4   5
    */
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    int diameter = sol.diameterOfBinaryTree(root);

    // Output the diameter of the binary tree
    cout << "The diameter of the binary tree is: " << diameter << endl;

    return 0;
}
