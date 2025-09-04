/*
260. Single Number III - Difficulty: Medium
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoOddNum(vector<int>& nums) {
        long long xorVal = 0;  // use 64-bit
        for(const int ele : nums) {
            xorVal ^= ele;
        }
        
        long long mask = xorVal & -xorVal;  // safe for INT_MIN
        
        vector<long long> ans(2, 0);
        for(const int ele : nums) {
            if((ele & mask) == 0) {
                ans[0] ^= ele;
            }
            else {
                ans[1] ^= ele;
            }
        }
        if(ans[0] < ans[1]) swap(ans[0], ans[1]);
        return { (int)ans[0], (int)ans[1] };
    }
};

int main() {
    Solution sol;

    // Test 1: simple case
    vector<int> arr1 = {1, 2, 3, 2, 3, 1, 4, 5};
    auto res1 = sol.twoOddNum(arr1);
    cout << "Test 1: " << res1[0] << " " << res1[1] << endl; // expect 5 4

    // Test 2: negative numbers
    vector<int> arr2 = {-3, -3, -7, 6, 6, 9};
    auto res2 = sol.twoOddNum(arr2);
    cout << "Test 2: " << res2[0] << " " << res2[1] << endl; // expect 9 -7

    // Test 3: mix of positives and negatives
    vector<int> arr3 = {10, -5, 10, 20, 20, -7, -7, -5, 30, 40};
    auto res3 = sol.twoOddNum(arr3);
    cout << "Test 3: " << res3[0] << " " << res3[1] << endl; // expect 40 30

    // Test 4: edge case with 0 and INT_MIN
    vector<int> arr4 = {1, 1, 0, INT_MIN};
    auto res4 = sol.twoOddNum(arr4);
    cout << "Test 4: " << res4[0] << " " << res4[1] << endl; // expect 0 -2147483648

    // Test 5: both odd numbers negative
    vector<int> arr5 = {-10, -20, -10, -30, -30, -40};
    auto res5 = sol.twoOddNum(arr5);
    cout << "Test 5: " << res5[0] << " " << res5[1] << endl; // expect -20 -40

    return 0;
}
