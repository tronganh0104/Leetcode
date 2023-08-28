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

bool isUnivalTree(TreeNode* root) {
    if (root == NULL) return true;
    int value = root->val;
    queue<TreeNode*> q;
    q.push(root);       
    while (!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        if (cur->left != NULL) {
            TreeNode* left = cur->left;
            if (left->val == value) {
                q.push(left);
            } else {
                return false;
            }   
        }
        if (cur->right != NULL) {
            TreeNode* right = cur->right;
            if (right->val == value) {
                q.push(right);
            } else {
                return false;
            }
        }
    }
    return true;
}

int main() {
    return 0;
}