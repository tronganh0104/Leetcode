#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<int>> graph, int node, vector<int> &colors) {
    if (colors[node] != 0) {
        return colors[node] == 2;
    }
    colors[node] = 1;
    for (int near : graph[node]) {
        if (!dfs(graph, near, colors)) {
            return false;
        }
    }

    colors[node] = 2;
    return true;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<int> output;
    int n = graph.size();
    vector<int> colors(n, 0);
    for (int i = 0; i < n; i += 1) {
        if (dfs(graph, i, colors)) {
            output.push_back(i);
        }
    }
    sort(output.begin(), output.end());
    return output;
}

int main() {
    return 0;
}