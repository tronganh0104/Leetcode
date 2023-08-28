#include <bits/stdc++.h>

using namespace std;

long long maxKelements(vector<int>& nums, int k) {
    long long output = 0;
    int n = nums.size();
    priority_queue<int> pq (nums.begin(), nums.end());
    while (k > 0) {
        int maxElement = pq.top();
        pq.pop();
        output += maxElement;
        int newElement = (maxElement % 3 == 0) ? (maxElement / 3) : (maxElement / 3 + 1);
        pq.push(newElement);
        k--;
    }       
    return output;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    cout << maxKelements(nums, k);
    return 0;
}
