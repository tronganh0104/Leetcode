#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> output;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int preValue = nums[0];
    for (int i = 0; i < n && nums[i] <= 0; i += 1) {
        if (preValue == nums[i] && i != 0) {
            continue;
        }
        int left = i + 1;
        int right = n - 1;
        int preLeft = nums[i];
        int preRight = nums[n - 1];
        while (left < right) {
            if (nums[left] == preLeft && left != i + 1) {
                left += 1;
                continue;
            }
            if (nums[right] == preRight && right != n - 1) {
                right -= 1;
                continue;
            }
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                vector <int> v;
                v.push_back(nums[i]);
                v.push_back(nums[left]);
                v.push_back(nums[right]);
                output.push_back(v);
                preLeft = nums[left];
                preRight = nums[right];
                left += 1;
                right -= 1;
            } else if (sum > 0) {
                right -= 1;
            } else if (sum < 0) {
                left += 1;
            }
        }
        preValue = nums[i];
    }
    return output;
}

int main() {
    int n;
    cin >> n;
    vector <int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    sort(nums.begin(), nums.end());
    vector<vector<int>> output = threeSum(nums);
    for (int i = 0; i < output.size(); i += 1) {
        for (int j = 0; j < 3; j += 1) {
            cout << output[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}