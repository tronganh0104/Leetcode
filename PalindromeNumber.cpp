#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(int x) {
    if (x < 0) return false;
    int countNum = log10(x) + 1;
    int num = 0;
    for (int i = 0; i < countNum/2; i++)
    {
        num = (num * 10) + (x % 10);
        x = x / 10;
    }
    if (countNum % 2 != 0) {
        x = x / 10;
    }
    return (num == x);
}

int main() {
    int x;
    cin >> x;
    cout << boolalpha << isPalindrome(x);    
    return 0;
}