#include <bits/stdc++.h>

using namespace std;
//in ra ma tran
void printMatrix(vector<vector<int>> matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    queue <pair<int, int>> q;
    int nRow = mat.size();
    int nCol = mat[0].size();
    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            if (mat[i][j] == 0) {
                q.push(make_pair(i,j));
            } else {
                mat[i][j] = -1;
            }
        }
    }
    while (!q.empty()) {
        int x, y;
        x = q.front().first;
        y = q.front().second;
        cout << x << " " << y <<" \n";
        q.pop();
        if (x < nRow - 1 && mat[x + 1][y] == -1) {
            mat[x + 1][y] = mat[x][y] + 1;
            q.push(make_pair(x + 1, y));
        }
        if (x > 0 && mat[x - 1][y] == -1) {
            mat[x - 1][y] = mat[x][y] + 1;
            q.push(make_pair(x - 1, y));
        }
        if (y < nCol - 1 && mat[x][y + 1] == -1) {
            mat[x][y + 1] = mat[x][y] + 1;
            q.push(make_pair(x, y + 1));
        }
        if (y > 0 && mat[x][y - 1] == -1) {
            mat[x][y - 1] = mat[x][y] + 1;
            q.push(make_pair(x, y - 1));
        }
        
    }
    return mat;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix;
    for (int i = 0; i < m; i++) {
        vector<int> v;
        int x;
        for (int j = 0; j < n; j ++) {
            cin >> x;
            v.push_back(x);
        }
        matrix.push_back(v);
    }
    matrix = updateMatrix(matrix);
    printMatrix(matrix);
}