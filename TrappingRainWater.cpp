#include <bits/stdc++.h>

using namespace std;

int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        int n = height.size(), maxLeft = height[0], maxRight = height[n-1];
        int left = 1, right = n - 2, ans = 0;
        while (left <= right) {
            if (maxLeft < maxRight) {
                if (height[left] > maxLeft)
                    maxLeft = height[left];
                else
                    ans += maxLeft - height[left];
                left += 1;
            } else {
                if (height[right] > maxRight)
                    maxRight = height[right];
                else
                    ans += maxRight - height[right];
                right -= 1;
            }
        }
        return ans;
    }

int main() {
    int n;
    cin >> n;
    vector<int> height;
    for (int i = 0; i < n; i += 1) {
        int x;
        cin >> x;
        height.push_back(x);
    }
    cout << trap(height);
    return 0;
}