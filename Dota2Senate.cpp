#include <bits/stdc++.h>

using namespace std;

string predictPartyVictory(string senate) {
    queue<int> radiant;
    queue<int> dire;
    int n = senate.size();
    for (int i = 0; i < n; i += 1) {
        if (senate[i] == 'R') {
            radiant.push(i);
        } else {
            dire.push(i);
        }
    }
    while (!radiant.empty() && !dire.empty()) {
        int indexR = radiant.front();
        radiant.pop();
        int indexD = dire.front();
        dire.pop();
        if (indexR < indexD) {
            radiant.push(n + indexR);
        } else {
            dire.push(n + indexD);
        }
    }
    return (radiant.size() > dire.size()) ? "Radiant" : "Dire";
}

int main() {
    return 0;
}