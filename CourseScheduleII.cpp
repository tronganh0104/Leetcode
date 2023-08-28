#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    vector<Node*> next;
    int inDegree;
    Node() : val(0), inDegree(0) {};
    Node(int x) : val(x), inDegree(0) {};
};

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    Node* clone[numCourses];
    for (int i = 0; i < numCourses; i += 1) {
        clone[i] = new Node(i);
    }
    for (vector<int> v : prerequisites) {
        int from = v[1];
        int to = v[0];
        clone[to]->inDegree += 1;
        clone[from]->next.push_back(clone[to]);
    }
    queue <Node*> q;
    for (Node* temp : clone) {
        if (temp->inDegree == 0) {
            q.push(temp);
        }
    }
    int count = 0;
    vector<int> output;
    while (!q.empty()) {
        Node* cur = q.front();
        output.push_back(cur->val);
        q.pop();
        if (cur->next.size() != 0) {
            for (Node* temp : cur->next) {
                temp->inDegree -= 1;
                if (temp->inDegree == 0) {
                    q.push(temp);
                }
            }
        }
        count += 1;
    }
    if (count != numCourses) {
        vector<int> v;
        return v;
    }
    return output;
}

int main() {
    return 0;
}