#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to check if two trees are mirrors of each other
bool isMirror(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2) return false;
    return (t1->val == t2->val) 
           && isMirror(t1->left, t2->right) 
           && isMirror(t1->right, t2->left);
}

// Main function
bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

// Helper to build a binary tree from a vector (level-order)
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty()) return nullptr;

    vector<TreeNode*> treeNodes;
    for (int val : nodes) {
        if (val == -101) treeNodes.push_back(nullptr); // Using -101 as null marker
        else treeNodes.push_back(new TreeNode(val));
    }

    int j = 1;
    for (int i = 0; i < treeNodes.size() && j < treeNodes.size(); i++) {
        if (treeNodes[i]) {
            if (j < treeNodes.size()) treeNodes[i]->left = treeNodes[j++];
            if (j < treeNodes.size()) treeNodes[i]->right = treeNodes[j++];
        }
    }
    return treeNodes[0];
}

// Driver code for testing
int main() {
    vector<int> input = {1, 2, 2, 3, 4, 4, 3};
    TreeNode* root = buildTree(input);

    if (isSymmetric(root)) cout << "true" << endl;
    else cout << "false" << endl;

    return 0;
}
