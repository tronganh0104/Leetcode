#include <bits/stdc++.h>

using namespace std;

bool hasAllCodes(string s, int k) {
    if (k > s.length()) {
        return false;
    } 
    int sum = 1;
    for (int i = 0; i < k; i++) {
        sum *= 2;
    }
    int left = 0;
    int right = k - 1;
    int n = s.length();
    map<string, int> mp;
    while (right < n) {
        string temp = s.substr(left, k);
        mp[temp]++;
        left++;
        right++;
    }
    return (mp.size() == sum);
}

int main() {
    return 0;
}