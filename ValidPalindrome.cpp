#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s) {
    string temp = "";
    for (char c : s) {
        if (((int) c >= 97 && (int) c <= 122) || ((int) c >= 48 && (int) c <= 57)) {
            temp += c;
        } else if ((int) c >= 65 && (int) c <= 90) {
            char m = c + 32;
            temp += m;
        }
    }
    cout << temp << "\n";
    int left = 0;
    int right = temp.length() - 1;
    if (temp.length() == 0) return true;
    while (left < right) {
        if (temp[left] != temp[right]) return false;
        left += 1; right -= 1;
    }
    return true;
}

int main() {
    string s;
    getline(cin, s);
    cout << boolalpha << isPalindrome(s);
    return 0;
}