#include <bits/stdc++.h>

using namespace std;

//Khởi tạo tam giác pascal
vector<vector<long long>> trianglePascal;
long long mod=1e9+7;

void makeTrianglePascal(int n) {
    for (int i = 0; i < n; i++) {
        vector<long long> row (n, 0);
        row[0] = 1;
        trianglePascal.push_back(row);
    }
    
    for (long long i = 1; i < n; i++) {
        for (long long j = 1; j < n; j++) {
            trianglePascal[i][j] = trianglePascal[i - 1][j - 1] + trianglePascal[i - 1][j];
            
        }
    }
}

int numWays(vector<int> nums) {
    if (nums.size() < 3) {
        return 1;
    }
    vector<int> left;
    vector<int> right;
    int n = nums.size();
    int root = nums[0];
    for (int i = 1; i < n; i++) {
        if (nums[i] < root) {
            left.push_back(nums[i]);
        } else {
            right.push_back(nums[i]);
        }
    }
    int k = left.size();
    cout << n << " " << k << "\n";
    return trianglePascal[n - 1][k] * (numWays(left) % mod) * (numWays(right) % mod);
}

int numOfWays(vector<int>& nums) {
    int n = nums.size();
    makeTrianglePascal(n + 1);
    return numWays(nums) - 1;
}


int main() {
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    cout << numOfWays(nums);
}