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

bool checkSymmetric(TreeNode* node1, TreeNode* node2) {
    if (node1 == NULL && node2 == NULL) return true;
    if (node1 == NULL || node2 == NULL) return false;
    if (node1->val != node2->val) return false;
    return checkSymmetric(node1->left, node2->right) && checkSymmetric(node1->right, node2->left);
}

bool isSymmetric(TreeNode* root) {
    if (root == NULL) return true;
    if (root->left == NULL && root->right == NULL) return true;
    if (root->left == NULL || root->right == NULL) return false;
    return checkSymmetric(root->left, root->right);
}

int main() {
    return 0;
}