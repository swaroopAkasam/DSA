
/*
137. Single Number II - Difficulty : Medium
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.
*/

#include <bits/stdc++.h>
using namespace std;


/*
Intuition
    If every number except one appears 3 times, then for each bit-position:
    The sum of all bits in that position will be a multiple of 3,
    Except for the bits contributed by the unique element.
    So if we count the bits column by column and take mod 3, we recover the unique number.
*/

// Bit Manipulation Method-1
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        
        for (int bit = 0; bit < 32; bit++) {
            int count = 0;
            for (int num : nums) {
                if (num & (1 << bit)) {
                    count++;
                }
            }
            if (count % 3 != 0) {
                result |= (1 << bit);
            }
        }
        
        return result;
    }
};

// Time: O(n) (since 32 is constant)
// Space: O(1)

// Sorting
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i+=3) {
            if(nums[i]!=nums[i-1]) return nums[i-1];
        }
        return nums[nums.size()-1];
    }
};

// Bit Manipulation Method-2 (Optimized, elegant)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        return ones;
    }
};


int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {2, 2, 3, 2},               // single = 3
        {0, 1, 0, 1, 0, 1, 99},     // single = 99
        {-2, -2, -2, -5},           // single = -5
        {7},                        // single = 7 (edge: only one element)
        {5, 5, 5, -100, 3, 3, 3},   // single = -100
        {INT_MAX, 1, 1, 1, INT_MAX, INT_MAX, -50} // single = -50
    };

    for (auto& arr : testCases) {
        cout << "Input: ";
        for (int n : arr) cout << n << " ";
        cout << "\nOutput: " << sol.singleNumber(arr) << "\n\n";
    }

    return 0;
}
