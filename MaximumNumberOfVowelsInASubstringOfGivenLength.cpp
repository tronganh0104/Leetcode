#include <bits/stdc++.h>

using namespace std;

int maxVowels(string s, int k) {
    int output = 0;
    int temp = 0;
    queue <char> q;
    for (int i = 0; i < k; i += 1) {
        q.push(s[i]);
        if (s[i] == 'u' || s[i] == 'e' || s[i] == 'o' || s[i] == 'a' || s[i] == 'i') {
            temp += 1;
        }
    }       
    output = max(temp, output);
    for (int i = k; i < s.length(); i += 1) {
        if (q.front() == 'u' || q.front() == 'e' || q.front() == 'o' || q.front() == 'a' || q.front() == 'i') {
            temp -= 1;
        }
        q.pop(); 
        if (s[i] == 'u' || s[i] == 'e' || s[i] == 'o' || s[i] == 'a' || s[i] == 'i') {
            temp += 1;
        }
        q.push(s[i]);
        output = max(temp, output);
    }
    return output;
}

int main() {
    return 0;
}