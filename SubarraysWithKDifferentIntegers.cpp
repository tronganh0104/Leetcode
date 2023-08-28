#include <bits/stdc++.h>

using namespace std;

int subarraysWithKDistinct(vector<int>& nums, int k) {
    int left = 0;
    int right = 0;
    int count = 0;
    int n = nums.size();
    map<int, int> mp;
    while (right < n) {
        mp[nums[right]]++;
        while (mp.size() > k) {
            mp[nums[left]]--;
            if (mp[nums[left]] == 0) {
                mp.erase(nums[left]);
            }
            left++;
        }
        if (mp.size() == k) {
            map<int, int> tempMp = mp;
            int tempLeft = left;
            while (tempMp.size() == k) {
                count++;
                tempMp[nums[tempLeft]]--;
                if (tempMp[nums[tempLeft]] == 0) {
                    tempMp.erase(nums[tempLeft]);
                }
                tempLeft++;
            }
        }
        right++;
    }
    return count;
}

int main() {
    
    vector<int> nums;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    cout << subarraysWithKDistinct(nums, k);
    
    
    return 0;
}