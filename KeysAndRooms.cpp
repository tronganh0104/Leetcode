#include <bits/stdc++.h>

using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    if (rooms.size() <= 1) return true;
    int output = 1;
    int n = rooms.size();
    vector<bool> vst (n, false);
    queue<int> q;
    q.push(0);
    vst[0] = true;
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        for (int key : rooms[temp]) {
            if (!vst[key]) {
                vst[key] = true;
                q.push(key);
                output++;
            }
        }
    }
    return output == rooms.size();
}

int main() {
    return 0;
}