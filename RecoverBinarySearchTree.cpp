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

void recoverTree(TreeNode* root) {
    vector<TreeNode*> nodes;
    stack<TreeNode*> st;
    TreeNode* temp = root;
    while (temp != NULL || !st.empty()) {
        while (temp != NULL) {
            st.push(temp);
            temp = temp->left;
        }
        temp = st.top();
        st.pop();
        nodes.push_back(temp);
        temp = temp->right;
    }
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    for (int i = 0; i < nodes.size() - 1; i += 1) {
        if (nodes[i]->val >= nodes[i + 1]->val) {
            if (first == NULL) {
                first = nodes[i];
            }
            second = nodes[i + 1];
        }
    }
    swap(first->val, second->val);
}

int main() {
    return 0;
}