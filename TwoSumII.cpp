#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int start = 0 ; 
    int end = numbers.size() - 1 ; 

    while ((start <= end) && (numbers[start] + numbers[end] != target))
    {
        if (numbers[start] + numbers[end] < target)
        {
            start ++ ;  
        }
        else 
        {
            end -- ; 
        }
    }
    return {start + 1 ,end + 1} ; 
}

int main() {
    vector <int> numbers;
    int n, target;
    cin >> n >> target;
    for (int i = 0;  i < n; i++) {
        int x;
        cin >> x;
        numbers.push_back(x);
    }
    cout << twoSum(numbers, target)[0] << " " << twoSum(numbers, target)[1];
    return 0;
}