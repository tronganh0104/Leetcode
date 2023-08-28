#include <bits/stdc++.h>

using namespace std;

bool checkClosed(vector<vector<int>> grid, queue<pair<int, int>> island) {
    int nRow = grid.size();
    int nCol = grid[0].size();
    while (!island.empty()) {
        int x = island.front().first;
        int y = island.front().second;
        island.pop();
        if (x == 0) return false;
        if (y == 0) return false;
        if (x == nRow - 1) return false;
        if (y == nCol - 1) return false;
    }
    return true;
}

int closedIsland(vector<vector<int>>& grid) {
    int count = 0;
    int nRow = grid.size();
    int nCol = grid[0].size();
    vector<vector<bool>> visited (grid.size(), vector<bool> (grid[0].size()));
    for (int i = 0; i < nRow; i += 1) {
        for (int j = 0; j < nCol; j += 1) {
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < nRow; i += 1) {
        for (int j = 0; j < nCol; j += 1) {
            if (grid[i][j] == 0 && visited[i][j] == false) {
                queue <pair<int, int>> island;
                queue <pair<int, int>> temp;
                island.push(make_pair(i, j));
                temp.push(make_pair(i, j));
                visited[i][j] = true;
                while (!temp.empty()) {
                    int x = temp.front().first;
                    int y = temp.front().second;
                    temp.pop();
                    if (x > 0 && grid[x - 1][y] == 0 && !visited[x - 1][y]) {
                        island.push(make_pair(x - 1, y));
                        temp.push(make_pair(x - 1, y));
                        visited[x - 1][y] = true;
                    }
                    if (x < nRow - 1 && grid[x + 1][y] == 0 && !visited[x + 1][y]) {
                        island.push(make_pair(x + 1, y));
                        temp.push(make_pair(x + 1, y));
                        visited[x + 1][y] = true;
                    }
                    if (y > 0 && grid[x][y - 1] == 0 && !visited[x][y - 1]) {
                        island.push(make_pair(x, y - 1));
                        temp.push(make_pair(x, y - 1));
                        visited[x][y - 1] = true;
                    }
                    if (y < nCol - 1 && grid[x][y + 1] == 0 && !visited[x][y + 1]) {
                        island.push(make_pair(x, y + 1));
                        temp.push(make_pair(x, y + 1));
                        visited[x][y + 1] = true;
                    }
                }
                if (checkClosed(grid, island)) {
                    count += 1;
                }
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
    cout << closedIsland(grid);
    return 0;
}