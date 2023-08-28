#include <bits/stdc++.h>

using namespace std;

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    int output = 0;
    vector <bool> visited(n, false);
    for (int i = 0; i < n; i += 1) {
        if (!visited[i]) {
            queue <int> q;
            q.push(i);
            while(!q.empty()) {
                int temp = q.front();
                q.pop();
                visited[temp] = true;
                for (int j = 0; j < n; j += 1) {
                    if (isConnected[temp][j] == 1 && j != temp) {
                        if (!visited[j]) {
                            q.push(j);
                        }
                    }
                }
            }
            output += 1;
        }
    }       
    return output;
}

int main() {
    return 0;
}