#include <bits/stdc++.h>

using namespace std;

int evalRPN(vector<string>& tokens) {
    stack <int> st;
    for (int i = 0; i < tokens.size(); i += 1) {
        if (tokens[i] == "+") {
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            x += y;
            st.push(x);
        } else if (tokens[i] == "-") {
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            x = y - x;
            st.push(x);
        } else if (tokens[i] == "*") {
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            x *= y;
            st.push(x);
        } else if (tokens[i] == "/") {
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            x = y / x;
            st.push(x);
        } else {
            int x = atoi(tokens[i].c_str());
            st.push(x);
        }
    }
    return st.top();
}

int main() {
    vector<string> token;
    int n;
    cin >> n;
    for (int i = 0; i < n; i += 1) {
        string s;
        cin >> s;
        token.push_back(s);
    }
    cout << evalRPN(token);
    return 0;
}