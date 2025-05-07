/*
53. Maximum Subarray
Given an integer array nums, find the subarray with the largest sum, and return its sum.
Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        dp[0] = nums[0];
        int maxi = dp[0];
        for(int i=1; i<n; i++) {
            dp[i] = max(nums[i], nums[i]+dp[i-1]);
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
    int kadanes(vector<int>& nums) {
        int currSum = 0;
        int maxi = nums[0];
        for(auto ele: nums) {
            currSum += ele;
            maxi = max(maxi, currSum);
            if(currSum<0) currSum = 0;
        }
        return maxi;
    }
};

int main() {
    Solution sol;
    // vector<int> nums = {5,4,-1,7,8};
    vector<int> nums = {-2,-1};
    int ans = sol.maxSubArray(nums);
    cout << ans << endl;
    ans = sol.kadanes(nums);
    cout << ans << endl;
    return 0;
}