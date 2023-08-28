#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> final;
    map<map<char,int>, vector<string>> mp;
    for (string str : strs) {
        map<char, int> mapString;
        for (char c : str) {
            mapString[c]++;
        }
        mp[mapString].push_back(str);
    }
    for (auto it : mp) {
        final.push_back(it.second);
    }
    return final;
}

int main() {
    vector <string> strs;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        strs.push_back(s);
    }
    return 0;
}