#include <bits/stdc++.h>

using namespace std;

bool check(map <char, int> m1, map <char, int> m2) {
    if (m1.size() != m2.size()) {
        return false;
    }

    auto mis = mismatch(m1.begin(), m1.end(), m2.begin());
    if (mis.first != m1.end()) {
        return false;
    } else {
        return true;
    }
}

bool checkInclusion(string s1, string s2) {
    int l1 = s1.length();
    map <char, int> m1;
    map <char, int> mWindow;
    int i = 0;
    int j = l1 - 1;
    for (int i = 0; i < l1; i++) {
        m1[s1[i]]++;
        mWindow[s2[i]]++;
    }
    int l2 = s2.length();
    while (i < l2 && j < l2) {
        if (check(m1, mWindow)) {
            return true;
        }
        mWindow[s2[i]] -= 1;
        if (mWindow[s2[i]] == 0) mWindow.erase(s2[i]);
        j += 1;
        mWindow[s2[j]] += 1;
        i += 1;
    }
    return false;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << boolalpha << checkInclusion(s1, s2);   
    return 0;
}