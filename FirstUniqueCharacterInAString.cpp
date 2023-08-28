#include <bits/stdc++.h>

using namespace std;

int firstUniqChar(string s) {
    map<char, int> mp;
    for (int i = 0; i < s.length(); i++) {
        mp[s[i]]++;
    }
    for (int i = 0; i < s.length(); i++) {
        if (mp[s[i]] == 1) {
            return i;
        }
    }
    return -1;
}   

int main() {    
    return 0;
}