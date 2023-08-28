#include <bits/stdc++.h>

using namespace std;

void printVector(vector <int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " "; 
    }
}

vector<int> productExceptSelf(vector<int>& nums) {
    vector <int> output;
    int n = nums.size();
    vector <int> left(n);
    vector <int> right(n);
    left[0] = 1;
    for (int i = 1; i < n; i++) {
        left[i] = left[i - 1] * nums[i - 1];
    }
    right[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        right[i] = right[i + 1] * nums[i + 1];
    }
    for (int i = 0; i < n; i++) {
        output.push_back(left[i] * right[i]);
    }
    return output;
}

int main() {
    vector <int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    v = productExceptSelf(v);
    printVector(v);
    return 0;
}