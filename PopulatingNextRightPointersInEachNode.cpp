#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) {
    if (root == NULL) return NULL;
    queue <Node *> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* rightNode = NULL;
        for (int i = 0; i < q.size(); i++) {
            Node *temp = q.front();
            temp->next = rightNode;
            rightNode = temp;
            q.pop();
        }
        if (root->right != NULL) {
            q.push(root->right);
            q.push(root->left);
        }
    }
    return root;
}

int main() {
    
    return 0;
}