#include <bits/stdc++.h>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> mp;
    vector<int> top;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (int i = 0; i < nums.size(); i++) {
        mp[nums[i]]++;
    }
    for (auto m : mp) {
        q.push({m.second, m.first});
        if (q.size() > k) {
            q.pop();
        }
    }
    while (!q.empty()) {
        top.push_back(q.top().second);
        q.pop();
    }
    return top;
}

int main() {
    int n, k;
    cin >> n, k;
    vector <int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    vector<int> top = topKFrequent(nums, k);
    for (int i = 0; i < top.size(); i++) {
        cout << top[i] << " ";
    }
    return 0;
}