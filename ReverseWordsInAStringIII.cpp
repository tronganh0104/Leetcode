#include <bits/stdc++.h>

using namespace std;

string reverseWords(string s) {
    string fn = "";
    stack <string> st;
    string m = "";
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == ' ') {
            st.push(m);
            m = "";
            st.push(" ");
        } else {
            m = m + s[i];
        }
    }
    st.push(m);
    while(!st.empty()) {
        fn = fn + st.top();
        st.pop();
    }
    return fn;
}

int main() {
    string s;
    getline(cin , s);
    cout << reverseWords(s);    
    return 0;
}