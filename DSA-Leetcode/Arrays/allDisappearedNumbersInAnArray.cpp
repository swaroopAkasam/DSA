// Problem Stmnt
// Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.
// Example 1:
// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [5,6]

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        for(auto ele: nums) {
            int index = abs(ele) -1;
            if(nums[index]>0) {
                nums[index] *= -1;
            }
        }
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]>0) {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int>nums = {4,3,2,7,8,2,3,1};
    vector<int> ans = sol.findDisappearedNumbers(nums);
    for(auto ele: ans){
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}