#include <iostream>
#include <climits>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function to validate BST
bool isValidBSTHelper(TreeNode* root, long long minVal, long long maxVal) {
    if (!root) return true;

    if (root->val <= minVal || root->val >= maxVal) return false;

    return isValidBSTHelper(root->left, minVal, root->val) &&
           isValidBSTHelper(root->right, root->val, maxVal);
}

// Main function
bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
}

// ---------------- TESTING ----------------
int main() {
    /*
        Example 1:
                2
               / \
              1   3
    */
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    cout << (isValidBST(root) ? "true" : "false") << endl; // Expected: true

    /*
        Example 2:
                5
               / \
              1   4
                 / \
                3   6
        This is NOT a BST because 4 < 5 but is in the right subtree of 5.
    */
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);

    cout << (isValidBST(root2) ? "true" : "false") << endl; // Expected: false

    return 0;
}
``
