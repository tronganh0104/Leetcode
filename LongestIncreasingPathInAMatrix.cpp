#include <bits/stdc++.h>

using namespace std;

int dfs(int x, int y, vector<vector<int>>& memo, vector<vector<int>>& matrix, int preVal) {
    if (x < 0 || x == matrix.size() || y < 0 || y == matrix[0].size() || matrix[x][y] <= preVal) return 0;
    if (memo[x][y] != -1) {
        return memo[x][y];
    }
    int res = 0;
    res = max(res, dfs(x + 1, y, memo, matrix, matrix[x][y]));
    res = max(res, dfs(x - 1, y, memo, matrix, matrix[x][y]));
    res = max(res, dfs(x, y + 1, memo, matrix, matrix[x][y]));
    res = max(res, dfs(x, y - 1, memo, matrix, matrix[x][y]));
    memo[x][y] = res + 1;
    return memo[x][y];
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int nRow = matrix.size();
    int nCol = matrix[0].size();
    vector<vector<int>> memo(nRow, vector<int>(nCol, -1));
    int output = 0;
    for (int i = 0; i < nRow; i += 1) {
        for (int j = 0; j < nCol; j += 1) {
            output = max(output, dfs(i, j, memo, matrix, INT_MIN));
        }
    }
    return output;
}

int main() {
    return 0;
}