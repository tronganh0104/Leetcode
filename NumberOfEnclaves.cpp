#include <bits/stdc++.h>

using namespace std;

int numEnclaves(vector<vector<int>>& grid) {
    int nRow = grid.size();
    int nCol = grid[0].size();
    for (int i = 0; i < nRow; i += 1) {
        if (grid[i][0] == 1) {
            queue <pair<int, int>> q;
            q.push(make_pair(i, 0));
            grid[i][0] = 0;
            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if (x > 0 && grid[x - 1][y] == 1) {
                    q.push(make_pair(x - 1, y));
                    grid[x - 1][y] = 0;
                }
                if (x < nRow - 1 && grid[x + 1][y] == 1) {
                    q.push(make_pair(x + 1, y));
                    grid[x + 1][y] = 0;
                }
                if (y > 0 && grid[x][y - 1] == 1) {
                    q.push(make_pair(x, y - 1));
                    grid[x][y - 1] = 0;
                }
                if (y < nCol - 1 && grid[x][y + 1] == 1) {
                    q.push(make_pair(x, y + 1));
                    grid[x][y + 1] = 0;
                }
            }
        }
        if (grid[i][nCol - 1] == 1) {
            queue <pair<int, int>> q;
            q.push(make_pair(i, nCol - 1));
            grid[i][nCol - 1] = 0;
            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                if (x > 0 && grid[x - 1][y] == 1) {
                    q.push(make_pair(x - 1, y));
                    grid[x - 1][y] = 0;
                }
                if (x < nRow - 1 && grid[x + 1][y] == 1) {
                    q.push(make_pair(x + 1, y));
                    grid[x + 1][y] = 0;
                }
                if (y > 0 && grid[x][y - 1] == 1) {
                    q.push(make_pair(x, y - 1));
                    grid[x][y - 1] = 0;
                }
                if (y < nCol - 1 && grid[x][y + 1] == 1) {
                    q.push(make_pair(x, y + 1));
                    grid[x][y + 1] = 0;
                }
            }
        }
    }
    for (int i = 0; i < nCol; i += 1) {
        if (grid[0][i] == 1) {
            queue <pair<int, int>> q;
            q.push(make_pair(0, i));
            grid[0][i] = 0;
            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                if (x > 0 && grid[x - 1][y] == 1) {
                    q.push(make_pair(x - 1, y));
                    grid[x - 1][y] = 0;
                }
                if (x < nRow - 1 && grid[x + 1][y] == 1) {
                    q.push(make_pair(x + 1, y));
                    grid[x + 1][y] = 0;
                }
                if (y > 0 && grid[x][y - 1] == 1) {
                    q.push(make_pair(x, y - 1));
                    grid[x][y - 1] = 0;
                }
                if (y < nCol - 1 && grid[x][y + 1] == 1) {
                    q.push(make_pair(x, y + 1));
                    grid[x][y + 1] = 0;
                }
            }
        }
        if (grid[nRow - 1][i] == 1) {
            queue <pair<int, int>> q;
            q.push(make_pair(nRow - 1, i));
            grid[nRow - 1][i] = 0;
            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                if (x > 0 && grid[x - 1][y] == 1) {
                    q.push(make_pair(x - 1, y));
                    grid[x - 1][y] = 0;
                }
                if (x < nRow - 1 && grid[x + 1][y] == 1) {
                    q.push(make_pair(x + 1, y));
                    grid[x + 1][y] = 0;
                }
                if (y > 0 && grid[x][y - 1] == 1) {
                    q.push(make_pair(x, y - 1));
                    grid[x][y - 1] = 0;
                }
                if (y < nCol - 1 && grid[x][y + 1] == 1) {
                    q.push(make_pair(x, y + 1));
                    grid[x][y + 1] = 0;
                }
            }
        }
    }
    int count = 0;
    for (int i = 0; i < nRow; i += 1) {
        for (int j = 0; j < nCol; j += 1) {
            if (grid[i][j] == 1) {
                count += 1;
            }
        }
    }
    return count;
}

int main() {
    vector<vector<int>> grid;
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i += 1) {
        vector<int> v;
        for (int j = 0; j < n; j += 1) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        grid.push_back(v);
    }
    cout << numEnclaves(grid);
    return 0;
}