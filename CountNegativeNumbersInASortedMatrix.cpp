#include <bits/stdc++.h>

using namespace std;

int countNegatives(vector<vector<int>>& grid) {
    int count = 0;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++) {
        int index = n;
        for (int j = 0; j < n; j++) {
            if (grid[i][j] < 0) {
                index = j;
                break;
            }
        }
        count += n - index;
    }
    return count;
}

int main() {
    return 0;
}