#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> output;
    vector<int> edge;
    int target = graph.size() - 1;
    edge.push_back(0);
    queue<vector<int>> q;
    q.push(edge);
    while (!q.empty()) {
        vector<int> temp = q.front();
        q.pop();
        int size = temp.size();
        int last = temp[size - 1];
        if (last == target) {
            output.push_back(temp);
        } else if (graph[last].size() != 0) {
            for (int cur : graph[last]) {
                temp.push_back(cur);
                q.push(temp);
                temp.pop_back();
            }
        }
    }    
    return output;   
}

int main() {
    vector<int> v;
    v.push_back(0);
    v.push_back(4);
    v.push_back(2);
    v.push_back(3);
    cout << v[v.size() - 1];
    return 0;
}