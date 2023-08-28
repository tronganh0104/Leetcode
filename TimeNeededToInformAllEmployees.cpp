#include <bits/stdc++.h>

using namespace std;

int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    int output = 0;
    vector<vector<int>> adj (n);
    for (int i = 0; i < n; i++) {
        if (headID == i) continue;
        int from = manager[i];
        adj[from].push_back(i);
    }       
    vector<pair<int,int>> v;
    v.push_back(make_pair(headID, informTime[headID]));
    while (!v.empty()) {
        int timeMin = -1;
        for (int i = 0; i < v.size(); i++) {
            if (timeMin == -1 || v[i].second < timeMin) {
                timeMin = v[i].second;
            }
        }
        vector<pair<int, int>> nextLevel;
        for (int i = 0; i < v.size(); i++) {
            v[i].second -= timeMin;
            if (v[i].second != 0) {
                nextLevel.push_back(v[i]);
            } else {
                int cur = v[i].first;
                for (int temp : adj[cur]) {
                    if (adj[temp].size() != 0) {
                        nextLevel.push_back(make_pair(temp, informTime[temp]));
                    }
                }
            }
        }
        v = nextLevel;
        output += timeMin;
    }
    return output;
}

struct CompareSecond {
    bool operator() (const pair<int, int> p1, const pair<int, int> p2) {
        return p1.second > p2.second;
    }
};

int main() {
    vector<pair<int, int>> v;
    v.push_back(make_pair(1,4));
    v.push_back(make_pair(2,1));
    v.push_back(make_pair(3,3));
    v.push_back(make_pair(4,9));
    v[0].second -= 2;
    cout << v[0].second;
    return 0;
}