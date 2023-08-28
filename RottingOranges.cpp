#include <bits/stdc++.h>

using namespace std;

void printGrid(vector<vector<int>> grid) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}

int orangesRotting(vector<vector<int>>& grid) {
    queue <pair<int, int>> q;
    int countFresh = 0;
    int count = 0;
    int nRow = grid.size();
    int nCol = grid[0].size();
    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            if (grid[i][j] == 2) {
               count++;
               q.push(make_pair(i, j)); 
            }
            if (grid[i][j] == 1) {
                countFresh += 1;
            }
        }
    }
    if (count == 0 && countFresh == 0) return 0;
    if (count == 0 && countFresh != 0) return -1;
    count = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (x + 1 < nRow && grid[x + 1][y] == 1) {
                grid[x + 1][y] = 2;
                countFresh -= 1;
                q.push(make_pair(x + 1, y));
            }
            if (x - 1 >= 0 && grid[x - 1][y] == 1) {
                grid[x - 1][y] = 2;
                countFresh -= 1;
                q.push(make_pair(x - 1, y));
            }
            if (y + 1 < nCol && grid[x][y + 1] == 1) {
                grid[x][y + 1] = 2;
                countFresh -= 1;
                q.push(make_pair(x, y + 1));
            }
            if (y - 1 >= 0 && grid[x][y - 1] == 1) {
                grid[x][y - 1] = 2;
                countFresh -= 1;
                q.push(make_pair(x, y - 1));
            }
        }
        count++;
    }
    if (countFresh != 0) {
        return -1;
    }
    return count - 1;
}

int main() {
    vector<vector<int>> grid;
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        vector<int> v;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        grid.push_back(v);
    }
    printGrid(grid);
    cout << orangesRotting(grid);
    return 0;
}