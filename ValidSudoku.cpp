#include <bits/stdc++.h>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); i++) {
        map <char, int> mapRow;
        map <char, int> mapCol;
        for (int j = 0; j < board.size(); j++) {
            if (board[i][j] != '.') {
                mapRow[board[i][j]]++;
                if (mapRow[board[i][j]] > 1) return false;
            }
            if (board[j][i] != '.') {
                mapCol[board[j][i]]++;
                if (mapCol[board[j][i]] > 1) return false;
            }
        }
    }
    map <char, int> mapSquare;
    //1
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != '.') {
                mapSquare[board[i][j]]++;
                if (mapSquare[board[i][j]] > 1) return false;
            }
        }
    }
    mapSquare.clear();
    //2
    for (int i = 0; i < 3; i++) {
        for (int j = 3; j < 6; j++) {
            if (board[i][j] != '.') {
                mapSquare[board[i][j]]++;
                if (mapSquare[board[i][j]] > 1) return false;
            }
        }
    }
    mapSquare.clear();
    for (int i = 0; i < 3; i++) {
        for (int j = 6; j < 9; j++) {
            if (board[i][j] != '.') {
                mapSquare[board[i][j]]++;
                if (mapSquare[board[i][j]] > 1) return false;
            }
        }
    }
    mapSquare.clear();
    for (int i = 3; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != '.') {
                mapSquare[board[i][j]]++;
                if (mapSquare[board[i][j]] > 1) return false;
            }
        }
    }
    mapSquare.clear();
    for (int i = 3; i < 6; i++) {
        for (int j = 3; j < 6; j++) {
            if (board[i][j] != '.') {
                mapSquare[board[i][j]]++;
                if (mapSquare[board[i][j]] > 1) return false;
            }
        }
    }
    mapSquare.clear();
    for (int i = 3; i < 6; i++) {
        for (int j = 6; j < 9; j++) {
            if (board[i][j] != '.') {
                mapSquare[board[i][j]]++;
                if (mapSquare[board[i][j]] > 1) return false;
            }
        }
    }
    mapSquare.clear();
    for (int i = 6; i < 9; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != '.') {
                mapSquare[board[i][j]]++;
                if (mapSquare[board[i][j]] > 1) return false;
            }
        }
    }
    mapSquare.clear();
    for (int i = 6; i < 9; i++) {
        for (int j = 3; j < 6; j++) {
            if (board[i][j] != '.') {
                mapSquare[board[i][j]]++;
                if (mapSquare[board[i][j]] > 1) return false;
            }
        }
    }
    mapSquare.clear();
    for (int i = 6; i < 9; i++) {
        for (int j = 6; j < 9; j++) {
            if (board[i][j] != '.') {
                mapSquare[board[i][j]]++;
                if (mapSquare[board[i][j]] > 1) return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board;
    for (int i = 0; i < 9; i++) {
        vector<char> v;
        for (int j = 0; j < 9; j++) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        board.push_back(v);
    }
    cout << boolalpha << isValidSudoku(board);
    return 0;
}