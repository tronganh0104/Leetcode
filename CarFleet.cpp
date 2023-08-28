#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int>a, pair<int, int> b) {
    return a.first > b.first;
}

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<pair<int, int>> ps;
    for (int i = 0; i < position.size(); i += 1) {
        ps.push_back(make_pair(position[i], speed[i]));
    }
    sort(ps.begin(), ps.end(), cmp);
    double time = 0;
    int output = 0;
    for (int i = 0; i < position.size(); i += 1) {
        double temp = (double) (target - ps[i].first) / ps[i].second;
        if (temp > time) {
            output += 1;
            time = temp;
        }
    }
    return output;
}

int main() {
    int target;
    cin >> target;
    int n;
    cin >> n;
    vector<int> speed;
    vector<int> position;
    for (int i = 0; i < n; i += 1) {
        int x, y;
        cin >> x >> y;
        position.push_back(x);
        speed.push_back(y);
    }
    cout << carFleet(target, position, speed);
    
    return 0;
}