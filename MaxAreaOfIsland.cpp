#include <bits/stdc++.h>

using namespace std;

void printGrid(vector<vector <int>> v) {
    int n = v.size();
    int m = v[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}

void countArea(vector<vector<int>>& grid, int row, int col, int &count) {
    count += 1;
    grid[row][col] = 0;
    int nRow = grid.size();
    int nCol = grid[0].size();
    if ((row + 1 < nRow) && (grid[row + 1][col] == 1)) {
        
        countArea(grid, row + 1, col, count);
    }
    if ((row - 1 >= 0) && (grid[row - 1][col] == 1)) {
        
        countArea(grid, row - 1, col, count);
    }
    if ((col + 1 < nCol) && (grid[row][col + 1] == 1)) {
        
        countArea(grid, row, col + 1, count);
    }
    if ((col - 1 >= 0) && (grid[row][col - 1] == 1)) {
        
        countArea(grid, row, col - 1, count);
    }
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int nRow = grid.size();
    int nCol = grid[0].size();
    int max = 0;
    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            if (grid[i][j] == 1) {
                int count = 0;
                countArea(grid, i, j, count);
                if (count > max) max = count;
            }
        }
    }
    return max;
}

int main() {
    vector <vector <int>> grid;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        vector <int> v;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        grid.push_back(v);
    }
    int max = maxAreaOfIsland(grid);
    cout << max;
    return 0;
}