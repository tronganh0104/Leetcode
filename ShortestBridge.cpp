#include <bits/stdc++.h>

using namespace std;

int shortestBridge(vector<vector<int>>& grid) {
    int x = -1, y = -1;
    int output = 0;
    int nRow = grid.size();
    int nCol = grid[0].size();
    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            if (grid[i][j] == 1) {
                x = i;
                y = j;
                break;
            }
        }
        if (x != -1) {
            break;
        }
    }
    vector<pair<int, int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    queue<pair<int, int>> q;
    queue<pair<int, int>> queueTemp;
    q.push(make_pair(x, y));
    queueTemp.push(make_pair(x, y));
    while (!queueTemp.empty()) {
        x = queueTemp.front().first;
        y = queueTemp.front().second;
        queueTemp.pop();
        grid[x][y] = 0;
    }
}

int main() {
    return 0;
}