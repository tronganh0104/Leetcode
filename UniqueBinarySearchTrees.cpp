#include <bits/stdc++.h>

using namespace std;

int numTrees(int n) {
    vector<int> num;
    for (int i = 0; i <= n; i += 1) {
        num.push_back(0);
    }
    for (int i = 0; i <= n; i += 1) {
        if (i == 0 || i == 1) {
            num[i] = 1;
            continue;
        }
        if (i == 2) {
            num[i] = 2;
            continue;
        }
        int sum = 0;
        for (int j = 1; j <= i; j += 1) {
            sum = sum + (num[j - 1] * num[i - j]);
        }
        num[i] = sum;
    }
    return num[n];
}

int main() {
    int n;
    cin >> n;
    cout << numTrees(n);
    return 0;
}