#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> output;
    map<int, int> mp1;
    map<int, int> mp2;
    vector<int> temp1, temp2;
    for (int i = 0; i < nums1.size(); i += 1) {
        if (mp1.find(nums1[i]) == mp1.end()) {
            temp1.push_back(nums1[i]);
            mp1[nums1[i]]++;
        } 
    }
    for (int i = 0; i < nums2.size(); i += 1) {
        if (mp2.find(nums2[i]) == mp2.end()) {
            temp2.push_back(nums2[i]);
            mp2[nums2[i]]++;
        } 
    }
    vector<int> answer1;
    for (int i : temp1) {
        if (mp2.find(i) == mp2.end()) {
            answer1.push_back(i);
        }
    }
    vector<int> answer2;
    for (int i : temp2) {
        if (mp1.find(i) == mp1.end()) {
            answer2.push_back(i);
        }
    }
    output.push_back(answer1);
    output.push_back(answer2);
    return output;
}

int main() {
    return 0;
}