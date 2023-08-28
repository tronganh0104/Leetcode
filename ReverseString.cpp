#include <bits/stdc++.h>

using namespace std;

void printVector(vector <char> s) {
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }
    cout << "\n";
}

void reverseString(vector<char>& s) {
    int l = 0;
    int r = s.size() - 1;
    while (l < r) {
        swap(s[l], s[r]);
        l++; r--;
    }
}

int main() {
    vector <char> v;
    int n;
    cin >> n;
    for (int i = 0 ; i < n; i++) {
        char c;
        cin >> c;
        v.push_back(c);
    }
    reverseString(v);
    for (int i = 0 ; i < n; i++) {
        cout << v[i] << " ";
    }
    return 0;
}