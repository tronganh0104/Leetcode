#include <bits/stdc++.h>

using namespace std;

int maxArea(vector<int>& height) {
    int output = 0;
    int left = 0;
    int right = height.size() - 1;
    while (left < right) {
        int width = right - left;
        int length = (height[left] >= height[right] ? height[right] : height[left]);
        int area = width * length;
        output = max(area, output);
        if (height[left] >= height[right]) {
            right -= 1;
        } else {
            left += 1;
        }
    }
    return output;
}

int main() {
    int n;
    cin >> n;
    vector <int> height;
    for (int i = 0; i < n; i += 1) {
        int x;
        cin >> x;
        height.push_back(x);
    }
    cout << maxArea(height);
    return 0;
}