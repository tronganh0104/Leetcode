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

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> output;
    if (root == NULL) return output;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        vector<int> v;
        int l = q.size();
        for (int i = 0; i < l; i += 1) {
            TreeNode* temp = q.front();
            q.pop();
            v.push_back(temp->val);
            if (temp->left != NULL) q.push(temp->left);
            if (temp->right != NULL) q.push(temp->right);
        }   
        output.push_back(v);
    } 
    return output;
}

int main() {
    int n;
    cin >> n;
    return 0;
}