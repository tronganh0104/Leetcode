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

void printTree(TreeNode *root) {
    cout << root->val << " ";
    if (root->left != NULL) {
        printTree(root->left);
    } 
    if (root->right != NULL) {
        printTree(root->right);
    }
}

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) {
        return NULL;
    }
    int sum = (root1 ? root1->val : 0) + (root2 ? root2->val : 0);
    TreeNode *rootMerge = new TreeNode(sum);
    rootMerge->left = mergeTrees(root1 ? root1->left : NULL, root2 ? root2->left : NULL); 
    rootMerge->right = mergeTrees(root1 ? root1->right : NULL, root2 ? root2->right : NULL);
    return rootMerge; 
}

int main() {
    int x;
    cin >> x;
    TreeNode *tempLeft = new TreeNode(x);
    cout << tempLeft->left->val;
    cin >> x;
    TreeNode *tempRight = new TreeNode(x);
    cin >> x;
    TreeNode *rLeft = new TreeNode(x,tempLeft, tempRight);
    cin >> x;
    tempLeft = new TreeNode(x);
    cin >> x;
    tempRight = new TreeNode(x);
    cin >> x;
    TreeNode *rRight = new TreeNode(x,tempLeft, tempRight);
    cin >> x;
    TreeNode *root = new TreeNode(x, rLeft, rRight);
    printTree(root);
    return 0;
}