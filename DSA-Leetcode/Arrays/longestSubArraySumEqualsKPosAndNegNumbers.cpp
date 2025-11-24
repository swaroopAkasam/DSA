/*
Longest Subarray with sum K | [Postives and Negatives]
Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> um;
        um[0] = -1;
        int sum = 0;
        int maxi = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            int remain = sum - k;

            if (um.find(remain) != um.end()) {
                maxi = max(maxi, i - um[remain]);
            }

            if (um.find(sum) == um.end()) {
                um[sum] = i;
            }
        }
        return maxi;
    }
};

int main() {
    Solution sol;

    vector<pair<vector<int>, int>> tests = {
        {{10, 5, 2, 7, 1, 9}, 15},   // expected 4 ([5,2,7,1])
        {{1, 2, 3}, 3},              // expected 2 ([1,2])
        {{1, -1, 5, -2, 3}, 3},      // expected 4 ([1, -1, 5, -2])
        {{-1, -1, 1}, 0},            // expected 1 ([-1, 1] or [1, -1])
        {{1, 2, 1, 2, 1}, 3},        // expected 2 ([1,2] or [2,1])
        {{1, 2, 3, 4, 5}, 9},        // expected 2 ([4,5])
        {{-2, -1, 2, 1}, 1},         // expected 2 ([-1, 2])
        {{1, 2, 3}, 10},             // expected 0 (no subarray)
        {{0, 0, 0, 0}, 0},           // expected 4 (whole array sums to 0)
        {{2, 3}, 3}                     // expected 1 (single element equals k)
    };

    for (int i = 0; i < tests.size(); i++) {
        auto [arr, k] = tests[i];
        int result = sol.longestSubarray(arr, k);
        cout << "Test " << i + 1 << ": k = " << k << ", arr = [ ";
        for (int x : arr) cout << x << " ";
        cout << "] -> Longest length = " << result << endl;
    }

    return 0;
}
