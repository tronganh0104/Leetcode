#include <bits/stdc++.h>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    map <int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
        mp[nums[i]]++;
    }
    int maxLen = 1;
    int pre = INT_MAX;
    int len = 1;
    for (auto m : mp) {
        if (pre == INT_MAX) {
            pre = m.first;
            continue;
        }
        if (m.first - pre == 1) {
            len += 1;
            pre = m.first;
        } else {
            maxLen = max(len, maxLen);
            len = 1;
            pre = m.first;
        }
        maxLen = max(len, maxLen);
    }
    return maxLen;
}

int main() {
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    cout << longestConsecutive(nums);
    return 0;
}