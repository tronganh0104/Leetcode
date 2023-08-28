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

vector<int> inorderTraversal(TreeNode* root) {
    stack <TreeNode*> st;
    vector<int> output;
    st.push(root);
    while (!st.empty()) {
        TreeNode* current = st.top();
        if (current->left != NULL) {
            st.push(current->left);
            current->left = NULL;
            continue;
        }
        if (current->right != NULL) {
            st.pop();
            st.push(current->right);
            output.push_back(current->val);
        } else {
            st.pop();
            output.push_back(current->val);
        }
    }
    return output;
}

int main() {
    return 0;
}