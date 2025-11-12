/*
75. Sort Colors
Medium
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() -1;
        while(mid<=high) {
            if(nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                mid++; low++;
            }
            else if(nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int one = 0;
        int two = 0;
        for(auto ele : nums) {
            if(ele == 0) {
                zero++;
            }
            else if(ele == 1) {
                one++;
            }
            else {
                two++;
            }
        }
        int i=0;
        while(zero) {
            nums[i] = 0;
            zero--; i++;
        }
        while(one) {
            nums[i] = 1;
            one--;i++;
        }
        while(two) {
            nums[i] = 2;
            two--;i++;
        }
    }
};

int main() {
    Solution sol;

    vector<vector<int>> tests = {
        {2, 0, 2, 1, 1, 0},   // mixed order
        {0, 1, 2, 0, 1, 2},   // alternating
        {0, 0, 0},            // all reds
        {2, 2, 2},            // all blues
        {1, 1, 1},            // all whites
        {2, 0, 1},            // all distinct once
        {1, 0, 2, 1, 0},      // random pattern
        {},                   // empty array
        {0},                  // single element
        {2, 1, 0, 2, 1, 0, 1, 2, 0} // longer pattern
    };

    for (int i = 0; i < tests.size(); i++) {
        vector<int> nums = tests[i];
        sol.sortColors(nums);

        cout << "Test " << i + 1 << ": ";
        for (int x : nums) cout << x << " ";
        cout << endl;
    }

    return 0;
}
