#include <bits/stdc++.h>

using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack <int> st;
    int nPush = pushed.size();
    int nPop = popped.size();
    int j = 0;
    for (int i = 0; i < nPush; i += 1) {
        st.push(pushed[i]);
        while ( !st.empty() && st.top() == popped[j] && j < nPop) {
            st.pop();
            j += 1;
        }
    }
    return j == nPop;
}

int main() {
    int n;
    cin >> n;
    vector<int> pushed;
    vector<int> popped;
    for (int i = 0; i < n; i += 1) {
        int x;
        cin >> x;
        pushed.push_back(x);
    }
    for (int i = 0; i < n; i += 1) {
        int x;
        cin >> x;
        popped.push_back(x);
    }
    cout << boolalpha << validateStackSequences(pushed, popped);
    return 0;
}