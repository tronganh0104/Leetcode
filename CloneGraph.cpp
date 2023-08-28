#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* cloneNode(unordered_map<Node*, Node*> &mp, Node* cur) {
    if (mp.find(cur) != mp.end()) {
        return mp[cur];
    }
    Node* clone = new Node(cur->val);
    mp[cur] = clone;
    for (auto it : cur->neighbors) {
        clone->neighbors.push_back(cloneNode(mp, it));
    }
    return clone;
}

Node* cloneGraph(Node* node) {
    if (node == NULL) return NULL;
    if (node->neighbors.size() == 0) {
        Node* newNode = new Node(node->val);
        return newNode;
    }
    unordered_map<Node*, Node*> mp;
    return cloneNode(mp, node);
}

int main() {
    return 0;
}