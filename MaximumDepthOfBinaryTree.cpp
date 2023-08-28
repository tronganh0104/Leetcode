#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int depthTree(TreeNode* root) {
    if (root == NULL) return 0;
    int depthLeft = depthTree(root->left) + 1;
    int depthRight = depthTree(root->right) + 1;
    return max(depthLeft, depthRight);
}

int maxDepth(TreeNode* root) {
    if (root == NULL) return 0;
    int depthLeft = depthTree(root->left) + 1;
    int depthRight = depthTree(root->right) + 1;
    return max(depthLeft, depthRight);
}

int main() {
    return 0;
}