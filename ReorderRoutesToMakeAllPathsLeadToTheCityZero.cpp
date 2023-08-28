#include <bits/stdc++.h>

using namespace std;



int minReorder(int n, vector<vector<int>>& connections) {
    vector<vector<int>> neighbour (n);
    map<pair<int,int>, int> mp;
    for (vector<int> edge : connections) {
        int from = edge[0];
        int to = edge[1];
        neighbour[from].push_back(to);
        neighbour[to].push_back(from);
        mp[make_pair(from, to)]++;
    }
    vector<bool> vst (n, false);
    queue<int> q;
    q.push(0);
    vst[0] = true;
    int output = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int temp : neighbour[cur]) {
            if (!vst[temp]) {
                q.push(temp);
                vst[temp] = true;
                pair<int, int> p = make_pair(temp, cur);
                if (mp.find(p) == mp.end()) output++;
            }
        }
    }
    return output;
}

int main() {
    return 0;
}