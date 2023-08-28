#include <bits/stdc++.h>

using namespace std;

void makeOutput(vector<string> &output, int open, int close, int n, string s) {
    if (s.size() == n*2) {
        output.push_back(s);
        return;
    }
    if (open < n) {
        makeOutput(output, open + 1, close, n, s + "(");
    }
    if (close < open) {
        makeOutput(output, open, close + 1, n, s + ")");
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> output;
    makeOutput(output, 0, 0, n, "");
    return output;
}

int main() {
    int n;
    cin >> n;
    vector<string> output;
    
    output = generateParenthesis(n);
    for (int i = 0; i < output.size(); i += 1) {
        cout << output[i] << " ";
    }
    return 0;
}