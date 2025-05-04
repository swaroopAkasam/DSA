/*
15. 3Sum
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i=0; i<n-2 && nums[i]<=0; i++) {
            if(i>0 && nums[i]==nums[i-1]) {
                continue;
            }
            int j = i+1; int k = n-1;
            while(j<k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0) {
                    j++;
                }
                else if (sum > 0) {
                    k--;
                }
                else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++; k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int>nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = sol.threeSum(nums);
    for(auto vec: ans){
        for(auto ele: vec)
            cout << ele << " ";
        cout << endl;
    }
    cout << endl;
    return 0;
}