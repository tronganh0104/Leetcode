#include <bits/stdc++.h>

using namespace std;

void rotate(vector<int>& nums, int k) {
    k = k % nums.size();
    int m = nums.size() - k;
    vector <int> v;
    for (int i = m; i < nums.size(); i++) {
        v.push_back(nums[i]);
    }
    for (int i = 0; i < m; i++) {
        v.push_back(nums[i]);
    }
    nums.erase(nums.begin(), nums.end());
    nums = v;
}

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector <int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    rotate(v, k);
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    return 0;
}