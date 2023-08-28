#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    vector<Node*> next;
    int inDegree;
    Node() : val(0), next(NULL), inDegree(0) {};
    Node(int x) : val(x), next(NULL), inDegree(0) {};
};


bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    Node* graph[numCourses];
    for (int i = 0; i < numCourses; i += 1) {
        graph[i] = new Node(i);
    }
    queue <Node*> q;
    for (int i = 0; i < prerequisites.size(); i += 1) {
        int from = prerequisites[i][1];
        int to = prerequisites[i][0];
        graph[to]->inDegree += 1;
        graph[from]->next.push_back(graph[to]);
    }
    for (Node* temp : graph) {
        if (temp->inDegree == 0) {
            q.push(temp);
        }
    }
    int count = 0;
    while(!q.empty()) {
        Node* cur = q.front();
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
    return count == numCourses;
}

int main() {
    return 0;
}