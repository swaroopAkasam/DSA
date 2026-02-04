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

    vector<int> twoSumSorting(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        vector<pair<int, int>> numsWithIndex;
        for(int i=0; i<n; i++) {
            numsWithIndex.push_back({nums[i], i});
        }

        sort(numsWithIndex.begin(), numsWithIndex.end());

        int left = 0, right = n-1;
        while(left<right) {
            int sum = numsWithIndex[left].first + numsWithIndex[right].first;
            if(sum == target) {
                ans.push_back(numsWithIndex[left].second); ans.push_back(numsWithIndex[right].second);
                return ans;
            }
            else if(sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int>nums = {2,7,11,15};
    int target = 9;
    vector<int> ans = sol.twoSumSorting(nums, target);
    for(auto ele: ans){
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}