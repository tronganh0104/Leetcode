#include <bits/stdc++.h>

using namespace std;

bool searchRow(vector<int> row, int target) {
    int left = 0;
    int right = row.size() - 1;
    while (left != right) {
        if (row[left] == target || row[right] == target) {
            return true;
        }
        int temp = (left + right) / 2;
        if (target <= row[temp]) {
            right = temp;
        } else {
            left = temp + 1;
        }
    }
    return row[left] == target;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int nRow = matrix.size();
    int nCol = matrix[0].size();
    if (target > matrix[nRow - 1][nCol - 1]) {
        return false;
    }
    if (target < matrix[0][0]) {
        return false;
    }
    int top = 0;
    int bottom = nRow;
    while (top != bottom) {
        int temp = (bottom + top) / 2;
        if (target <= matrix[temp][nCol - 1]) {
            bottom = temp;
        } else {
            top = temp + 1;
        }
    }
    return searchRow(matrix[top], target);
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix;
    for (int i = 0; i < m; i += 1) {
        vector<int> v;
        for (int j = 0; j < n; j += 1) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        matrix.push_back(v);
    }
    int target;
    cin >> target;
    cout << boolalpha << searchMatrix(matrix, target);
    return 0;
}