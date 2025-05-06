/*
219. Contains Duplicate II
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: fals
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        int left = 0;
        for(int i=0; i<nums.size(); i++) {
            if(i-left > k) {
                s.erase(nums[left]);
                left++;
            }
            if(s.count(nums[i])) {
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int>nums = {1,2,3,1,2,3};
    int k = 2;
    bool ans = sol.containsNearbyDuplicate(nums);
    cout << ans << endl;
    return 0;
}