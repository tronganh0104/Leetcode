#include <bits/stdc++.h>

using namespace std;

bool isAnagram(string s, string t) {
    int l1 = s.length();
    int l2 = t.length();
    if (l1 != l2) return false;
    map <char, int> mapS;
    map <char, int> mapT;
    for (int i = 0; i < l1; i++) {
        mapS[s[i]]++;
        mapT[t[i]]++;
    }
    if (mapS.size() != mapT.size()) {
        return false;
    } else {
        for (auto it : mapS) {
            if (it.second != mapT[it.first]) return false;
        }
    }
    return true;
}

int main() {
    string s,t;
    getline(cin, s);
    getline(cin, t);
    cout << boolalpha << isAnagram(s, t);
    return 0;
}