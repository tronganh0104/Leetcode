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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> output;
    if (root == NULL) return output;
    bool ziczac = true;       
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int l = q.size();
        vector<int> v(l);
        for (int i = 0; i < l; i += 1) {
            TreeNode* temp = q.front();
            q.pop();
            if (ziczac) {
                v[i] = temp->val;
            } else {
                v[l - i - 1] = temp->val;
            }
            if (temp->left != NULL) q.push(temp->left);
            if (temp->right != NULL) q.push(temp->right);
        }
        
        ziczac = !ziczac;
        output.push_back(v);
    }
    return output;
}

int main() {
    return 0;
}