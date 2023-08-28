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

TreeNode* makeTree(vector<int> nums, int left, int right) {
    if (left > right) return NULL;

    int temp = (left + right) / 2;
    TreeNode* root = new TreeNode(nums[temp]);
    root->left = makeTree(nums, left, temp - 1);
    root->right = makeTree(nums, temp + 1, right);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.size() == 0) return NULL;
    return makeTree(nums, 0, nums.size() - 1);
}

int main() {
    return 0;
}