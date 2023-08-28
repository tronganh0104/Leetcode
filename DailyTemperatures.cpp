#include <bits/stdc++.h>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> output;
    int n = temperatures.size();
    for (int i = 0; i < n; i += 1) {
        output.push_back(0);
    }
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i += 1) {
        while (!st.empty() && st.top().second < temperatures[i]) {
            int x = st.top().first;
            st.pop();
            output[x] = i - x;
        }
        st.push(make_pair(i, temperatures[i]));
    }
    return output;
}

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i += 1) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    v = dailyTemperatures(v);
    for (int i = 0; i < n; i += 1) {
        cout << v[i] << " ";
    }
    return 0;
}