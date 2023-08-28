#include <bits/stdc++.h>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    map<int, int> mp;
    for (auto i : nums) {
        mp[i]++;
    }
    for (auto m : mp) {
        if (m.second > 1) return true;
    }
    return false;
}

int main() {
    vector <int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << containsDuplicate(v);
    return 0;
}