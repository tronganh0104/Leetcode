#include <bits/stdc++.h>

using namespace std;

void printArray(vector <int> nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
}

vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
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
    printArray(sortArray(nums));
    return 0;
}