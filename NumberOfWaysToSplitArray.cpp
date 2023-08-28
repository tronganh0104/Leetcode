#include <bits/stdc++.h>

using namespace std;

int waysToSplitArray(vector<int>& nums) {
    if (nums.size() <= 1) {
        return 0;
    }
    long long left = 0;
    int n = nums.size();
    long long right = 0;
    for (int i = 0; i < n; i++) {
        right += nums[i];
    }       
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        left += nums[i];
        right -= nums[i];
        if (left >= right) {
            count++;
        }
    }
    return count;
}

int main() {
    return 0;
}