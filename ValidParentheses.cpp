#include <bits/stdc++.h>

using namespace std;

bool isValid(string s) {
    stack <char> st;
    map <char, char> mp;
    mp['('] = ')';
    mp['{'] = '}';
    mp['['] = ']';
    for (int i = 0; i < s.length(); i += 1) {
        if (st.empty()) {
            st.push(s[i]);
        } else {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                char front = st.top();
                if (mp[front] == s[i]) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
    }
    return st.empty();
}

int main() {
    string s;
    getline(cin, s);
    cout << boolalpha << isValid(s);
    return 0;
}