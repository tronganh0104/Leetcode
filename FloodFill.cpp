#include <bits/stdc++.h>

using namespace std;

void printImage(vector<vector <int>> v) {
    int n = v.size();
    int m = v[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}

void dfs(vector<vector<int>> &ans, int sr, int sc, int color, int firstColor) {
    ans[sr][sc] = color;
    int nRow = ans.size();
    int nCol = ans[0].size();
    int x, y;
    x = sr - 1;
    y = sc;
    if ((x >= 0 && x < nRow) && (y >= 0 && y < nCol) && (ans[x][y] == firstColor)) {
        dfs(ans, x, y, color, firstColor);
    }
    x = sr + 1;
    y = sc;
    if ((x >= 0 && x < nRow) && (y >= 0 && y < nCol) && (ans[x][y] == firstColor)) {
        dfs(ans, x, y, color, firstColor);
    }
    x = sr;
    y = sc - 1;
    if ((x >= 0 && x < nRow) && (y >= 0 && y < nCol) && (ans[x][y] == firstColor)) {
        dfs(ans, x, y, color, firstColor);
    }
    x = sr;
    y = sc + 1;
    if ((x >= 0 && x < nRow) && (y >= 0 && y < nCol) && (ans[x][y] == firstColor)) {
        dfs(ans, x, y, color, firstColor);
    }
}

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int firstColor = ans[sr][sc];
        dfs(ans,sr,sc,color, firstColor);
        return ans;
    }

int main() {
    vector <vector <int>> image;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        vector <int> v;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        image.push_back(v);
    }
    int sr, sc, color;
    cin >> sr >> sc >> color;
    image = floodFill(image, sr, sc, color);
    printImage(image);
    return 0;
}