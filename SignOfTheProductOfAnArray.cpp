#include <bits/stdc++.h>

using namespace std;

int arraySign(vector<int>& nums) {
    int output = 1;
    for (int temp : nums) {
        if (temp == 0) return 0;
        if (temp < 0) output *= -1;
    }       
    return (output == 1 ? 1 : -1);
}

int main() {
    return 0;
}