/*
Missing ranges of numbers
Difficulty: Easy
You have an inclusive interval [lower, upper] and a sorted array of unique integers arr[], all of which lie within this interval. A number x is considered missing if x is in the range [lower, upper] but not present in arr[]. Your task is to return the smallest set of sorted ranges that includes all missing numbers, ensuring no element from arr is within any range, and every missing number is covered exactly once.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> missingRanges(vector<int> &arr, int lower, int upper) {
        int n = arr.size();
        vector<vector<int>> res;

        // Check for missing range before the first element
        if (lower < arr[0])
            res.push_back({lower, arr[0] - 1});

        // Check for missing ranges between consecutive elements
        for (int i = 0; i < n - 1; ++i)
            if (arr[i + 1] - arr[i] > 1)
                res.push_back({arr[i] + 1, arr[i + 1] - 1});

        // Check for missing range after the last element
        if (n > 0 && upper > arr[n - 1])
            res.push_back({arr[n - 1] + 1, upper});

        return res;
    }
};

int main() {
    Solution sol;

    vector<pair<vector<int>, pair<int,int>>> testCases = {
        {{0, 1, 3, 50, 75}, {0, 99}},    // Example from LeetCode
        {{1, 3, 50, 75}, {0, 99}},       // missing range includes lower
        {{0, 1, 3, 50, 75}, {0, 75}},    // upper bound matches last element
        {{}, {1, 5}},                    // empty array
        {{1, 2, 3, 4}, {1, 4}},          // no missing ranges
        {{2}, {0, 9}},                   // single element in range
        {{5}, {5, 5}}                    // single element matches both bounds
    };

    for (auto &tc : testCases) {
        auto arr = tc.first;
        int lower = tc.second.first, upper = tc.second.second;
        cout << "Input: arr = [";
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << (i + 1 < arr.size() ? "," : "");
        }
        cout << "], lower = " << lower << ", upper = " << upper << "\n";

        auto result = sol.missingRanges(arr, lower, upper);
        cout << "Output: ";
        for (auto &range : result) {
            cout << "[" << range[0] << "," << range[1] << "] ";
        }
        cout << "\n\n";
    }

    return 0;
}
