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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

TreeNode* makeTree(vector<int> nums, int left, int right) {
    if (left > right) return NULL;

    int temp = (left + right) / 2;
    TreeNode* root = new TreeNode(nums[temp]);
    root->left = makeTree(nums, left, temp - 1);
    root->right = makeTree(nums, temp + 1, right);
    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    if (head == NULL) return NULL;
    vector<int> nums;
    while (head != NULL) {
        nums.push_back(head->val);
        head = head->next;
    }
    return makeTree(nums, 0, nums.size() - 1);
}

int main() {
    return 0;
}