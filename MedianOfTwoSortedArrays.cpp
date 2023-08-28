#include <bits/stdc++.h>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    double output = 0;
    int n = nums1.size();
    int m = nums2.size();
    vector<int> mergeNum;
    int i = 0;
    int j = 0;
    while (i < n || j < m) {
        if (i == n) {
            mergeNum.push_back(nums2[j]);
            j++;
            continue;
        }
        if (j == m) {
            mergeNum.push_back(nums1[i]);
            i++;
            continue;
        }
        if (nums1[i] <= nums2[j]) {
            mergeNum.push_back(nums1[i]);
            i++;
        } else {
            mergeNum.push_back(nums2[j]);
            j++;
        }
    }
    int mid = (n + m) / 2;
    if ((n + m) % 2 == 0) {
        output = double (mergeNum[mid] + mergeNum[mid - 1]) / 2.0;
    } else {
        output = double (mergeNum[mid]);
    }
    return output;
}

int main() {
    return 0;
}