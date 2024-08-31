

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

long long int solve(TreeNode<int> *root, long long int &maxi) {
    if (root == NULL) return 0;

    long long int l = solve(root->left, maxi);
    long long int r = solve(root->right, maxi);

    if (root->left == NULL && root->right == NULL) {
        return root->val;
    }

    if (root->left == NULL) return root->val + r;
    if (root->right == NULL) return root->val + l;

    long long int pathThroughRoot = root->val + l + r;

    maxi = max(maxi, pathThroughRoot);

    return root->val + max(l, r);
}

long long int findMaxSumPath(TreeNode<int> *root) {
    long long int maxi = LLONG_MIN;
    long long int result = solve(root, maxi);

    if (maxi == LLONG_MIN || result == LLONG_MIN) return -1;

    return maxi;
}

int main() {
    TreeNode<int> *root = new TreeNode<int>(5);
    root->left = new TreeNode<int>(6);
    root->right = new TreeNode<int>(2);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(3);
    root->left->left->left = new TreeNode<int>(9);
    root->left->left->right = new TreeNode<int>(7);
    root->right->left = new TreeNode<int>(6);
    root->right->left->left = new TreeNode<int>(5);
    root->right->left->right = new TreeNode<int>(2);

    long long int result = findMaxSumPath(root);
    
    cout << "Maximum sum path between any two leaves: " << result << endl;

    return 0;
}
