#include <bits/stdc++.h>

using namespace std;

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int nRow = maze.size();
    int nCol = maze[0].size();
    vector<vector<bool>> visited (nRow, vector<bool> (nCol, false));
    int output = 0;
    bool canOut = false; 
    queue <pair<int, int>> q;
    q.push(make_pair(entrance[0], entrance[1]));
    visited[entrance[0]][entrance[1]] = true;
    while (!q.empty()) {
        int qSize = q.size();
        for (int i = 0; i < qSize; i++) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            if (row == 0 || row == (nRow - 1) || (col == 0 || col == (nCol - 1)) && (row != entrance[0] && col != entrance[1])) {
                canOut = true;
                break;
            }
            if (row > 0 && !visited[row - 1][col] && maze[row - 1][col] == '.') {
                q.push(make_pair(row - 1, col));
                visited[row - 1][col] = true;
            }
            if (col > 0 && !visited[row][col - 1] && maze[row][col - 1] == '.') {
                q.push(make_pair(row, col - 1));
                visited[row][col - 1] = true;
            }
            if (row < nRow - 1 && !visited[row + 1][col] && maze[row + 1][col] == '.') {
                q.push(make_pair(row + 1, col));
                visited[row + 1][col] = true;
            }
            if (col < nCol - 1 && !visited[row][col + 1] && maze[row][col + 1] == '.') {
                q.push(make_pair(row, col + 1));
                visited[row][col + 1] = true;
            }
        }
        if (canOut) {
            break;
        }
        output++;
    }
    if (!canOut) {
        return -1; 
    }
    return output;
}

int main() {
    return 0;
}