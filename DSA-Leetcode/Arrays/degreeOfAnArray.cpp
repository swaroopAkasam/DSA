/*
697. Degree of an Array
Solved
Easy
Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq, first, last;
        
        for (int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            freq[n]++;
            if (first.find(n) == first.end())
                first[n] = i;
            last[n] = i;
        }

        int degree = 0;
        for (auto& [num, count] : freq)
            degree = max(degree, count);

        int minLength = nums.size();
        for (auto& [num, count] : freq) {
            if (count == degree) {
                int length = last[num] - first[num] + 1;
                minLength = min(minLength, length);
            }
        }

        return minLength;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {1, 2, 2, 3, 1},       // Expected output: 2
        {1, 2, 2, 3, 1, 4, 2}, // Expected output: 6
        {1, 2, 3, 4, 5},       // Expected output: 1 (all unique)
        {1, 1, 1, 1},          // Expected output: 4
        {1, 2, 1, 3, 2, 2, 1}  // Expected output: 6
    };

    for (int i = 0; i < testCases.size(); ++i) {
        cout << "Test Case " << i + 1 << ": ";
        for (int num : testCases[i]) cout << num << " ";
        cout << "\nResult: " << sol.findShortestSubArray(testCases[i]) << "\n\n";
    }

    return 0;
}
