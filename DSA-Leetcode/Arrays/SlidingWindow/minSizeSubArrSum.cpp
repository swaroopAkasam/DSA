/*
209. Minimum Size Subarray Sum
Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) { // O(n) time complexity
        int left = 0, total = 0;
        int ans = INT_MAX;
        int n = nums.size();

        for(int right=0; right<n; right++) {
            total += nums[right];

        while(total >= target) {
            ans = min(ans, right-left+1);
            total -= nums[left];
            left++;
        }
        }
        return ans == INT_MAX ? 0 : ans;
    }
    int minSubArrayLenUsingPrefSum(int target, vector<int>& nums) { // O(n log n) time complexity 
        int n = nums.size();
        vector<int> prefix(n+1, 0);
        for(int i=0; i<n; i++) {
            prefix[i+1] = nums[i] + prefix[i];
        }
        int ans = INT_MAX;
        for(int i=0; i<n; i++) {
            int to_find = target + prefix[i];
            auto bound = lower_bound(prefix.begin(), prefix.end(), to_find);
            if(bound != prefix.end()) {
                int j = bound - prefix.begin();
                ans = min(ans, j-i);
            }
        }
        return ans==INT_MAX ? 0 : ans;
    }

};

int main() {
    Solution sol;
    vector<int>nums = {2,3,1,2,4,3};
    int target = 2;
    bool ans = sol.minSubArrayLen(target, nums);
    cout << ans << endl;
    ans = sol.minSubArrayLenUsingPrefSum(target, nums);
    cout << ans << endl;
    return 0;
}