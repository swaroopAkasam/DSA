// Problem Stmnt
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> um;
        for(int i=0; i<nums.size(); i++) {
            int ele = nums[i];
            if(um.find(target-ele) != um.end()) {
                ans.push_back(i);
                ans.push_back(um[target-ele]);
                return ans;
            }
            um[ele] = i;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int>nums = {2,7,11,15};
    int target = 9;
    vector<int> ans = sol.twoSum(nums, target);
    for(auto ele: ans){
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}