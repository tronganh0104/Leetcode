#include <bits/stdc++.h>
using namespace std;

int findNum(vector <int> nums, int j, int x)
{   
    for (int i = j + 1; i < nums.size(); i++)
    {
        if (nums[i] == x) return i;
    }
    return -1;
}

vector<int> twoSum(vector<int>& nums, int target) {
    vector <int> final;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int x = target - nums[i];
        if (findNum(nums, i, x) != -1) 
        {
            final.push_back(i);
            final.push_back(findNum(nums, i, x));
            return final;
        }
    }
}

int main() 
{
    vector <int> nums;
    int n, target;
    cin >> n >> target;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    cout << twoSum(nums, target)[0] << " " << twoSum(nums, target)[1];    
    return 0;
}