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

bool checkLeaf(TreeNode* root, int alpha, int beta) {
    if (root == NULL) return true;
    if (root->val > alpha || root->val < beta) {
        return false;
    }
    return checkLeaf(root->left, root->val, beta) && checkLeaf(root->right, alpha, root->val);
}

bool isValidBST(TreeNode* root) {
    if (root == NULL) return true;
    int alpha = INT_MAX;
    int beta = INT_MIN;
    if (!checkLeaf(root->left, root->val, beta)) {
        return false;
    }
    if (!checkLeaf(root->right, alpha, root->val)) {
        return false;
    }
    return true;
}

int main() {

    return 0;
}