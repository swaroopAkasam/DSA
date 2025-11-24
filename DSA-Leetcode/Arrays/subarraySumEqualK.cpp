/*
560. Subarray Sum Equals K
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

#include<bits/stdc++.h>
using namespace std;

int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int n = arr.size();
    unordered_map<int, int> um;
    um[0] = 1;
    int preSum = 0, cnt = 0;

    for(int i=0; i<n; i++) {
        preSum += arr[i];

        int remain = preSum-k;

        cnt += um[remain];

        um[preSum] += 1;
    }
    return cnt;
}

int main()
{
    // vector arr = {3, 1, 2, 4};
    // int k = 6;
    vector arr = {1, 2, 3};
    int k = 3;
    int cnt = findAllSubarraysWithGivenSum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}

