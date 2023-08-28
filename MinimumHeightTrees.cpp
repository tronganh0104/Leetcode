#include <bits/stdc++.h>

using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) return {0};
    vector<int> degree(n, 0);
    vector<vector<int>> adj_list(n, vector<int>{});
    for (const auto& edge : edges) {
        adj_list[edge[0]].push_back(edge[1]);
        adj_list[edge[1]].push_back(edge[0]);
        degree[edge[0]]++;
        degree[edge[1]]++;
    }
    queue<int> leaves;
    for (int i = 0; i < n; ++i) {
        if (degree[i] == 1) leaves.push(i);
    }
    while (n > 2) {
        int num_leaves = leaves.size();
        n -= num_leaves;
        for (int i = 0; i < num_leaves; ++i) {
            int leaf = leaves.front();
            leaves.pop();
            for (int neighbor : adj_list[leaf]) {
                if (--degree[neighbor] == 1) {
                    leaves.push(neighbor);
                }
            }
        }
    }
    vector<int> res;
    while (!leaves.empty()) {
        res.push_back(leaves.front());
        leaves.pop();
    }
    return res;
}


int main() {
    return 0;
}