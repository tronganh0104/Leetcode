#include <bits/stdc++.h>

using namespace std;

double average(vector<int>& salary) {
    if (salary.size() <= 2) return 0;
    sort(salary.begin(), salary.end());
    double sum = 0;
    for (int i = 1; i < salary.size() - 1; i += 1) {
        sum += salary[i];
    }
    return (double) (sum / (salary.size() - 2));
}

int main() {
    return 0;
}