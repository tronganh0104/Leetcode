#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int i = 0;
    int j = 0;
    int l = s.length();
    map <char, int> m;
    int maxLen = 0;
    int windowSize;
    int mapSize;
    while (i < l && j < l) {
        m[s[j]]++;
        windowSize = j - i + 1;
        mapSize = m.size();
        if (mapSize == windowSize) {
            maxLen = max(maxLen, mapSize);
        } else {
            while (mapSize != windowSize) {
                m[s[i]] -= 1;
                if (m[s[i]] == 0) m.erase(s[i]);
                i += 1;
                windowSize -= 1;
                mapSize = m.size();
            }
            maxLen = max(maxLen, mapSize);
        }
        j++;
    }
    return maxLen;
}

int main() {
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s);
    return 0;   
}