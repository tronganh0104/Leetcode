#include <bits/stdc++.h>

using namespace std;

vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
    //Cài đặt các đỉnh kề
    vector<vector<int>> adjRed (n);
    vector<vector<int>> adjBlue (n);
    for (vector<int> edge : redEdges) {
        int from = edge[0];
        int to = edge[1];
        adjRed[from].push_back(to);
    }
    for (vector<int> edge : blueEdges) {
        int from = edge[0];
        int to = edge[1];
        adjBlue[from].push_back(to);
    }
    vector<int> output (n, -1);
    vector<bool> vstRed(n, false);
    vector<bool> vstBlue(n, false);
    queue<int> q;
    q.push(0);
    vstRed[0] = true;
    int dis = 0;
    bool isRed = true;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int cur = q.front();
            q.pop();
            if (output[cur] == -1 || output[cur] > dis) {
                output[cur] = dis;
            }
            if (isRed) {
                for (int node : adjRed[cur]) {
                    if (!vstBlue[node]) {
                        q.push(node);
                        vstBlue[node] = true;
                    }
                }
                
            } else {
                for (int node : adjBlue[cur]) {
                    if (!vstRed[node]) {
                        q.push(node);
                        vstRed[node] = true;
                    }
                }
                
            }
        }
        dis++;
        isRed = !isRed;
    }
    for (int i = 0; i < n; i++) {
        vstBlue[i] = false;
        vstRed[i] = false;
    }
    q.push(0);
    vstBlue[0] = true;
    dis = 0;
    isRed = false;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int cur = q.front();
            q.pop();
            if (output[cur] == -1 || output[cur] > dis) {
                output[cur] = dis;
            }
            if (isRed) {
                for (int node : adjRed[cur]) {
                    if (!vstBlue[node]) {
                        q.push(node);
                        vstBlue[node] = true;
                    }
                }
               
            } else {
                for (int node : adjBlue[cur]) {
                    if (!vstRed[node]) {
                        q.push(node);
                        vstRed[node] = true;
                    }
                }
                
            }
        }
        dis++;
        isRed = !isRed;
    }
    return output;
}

int main() {
    return 0;
}