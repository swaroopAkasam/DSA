/*
977. Squares of a Sorted Array
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int left = 0; int right = n-1;
        for(int index = n-1; index>=0; index--) {
            if(abs(nums[left]) > nums[right]) {
                ans[index] = nums[left]*nums[left];
                left++;
            }
            else {
                ans[index] = nums[right]*nums[right];
                right--;
            }
        } 
        return ans;

    }

    vector<int> sortedSquaresMeth2(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int k = 0; 
        while(k<n && nums[k]<0) k++;
        int i = k-1; int j = k;
        while(i>=0 && j<n) {
            if(abs(nums[i]) < nums[j]) {
                ans.push_back(nums[i]*nums[i]);
                i--;
            }
            else {
                ans.push_back(nums[j]*nums[j]);
                j++;
            }
        }
        while(i>=0) {
            ans.push_back(nums[i]*nums[i]);
            i--;
        }
        while(j<n) {
            ans.push_back(nums[j]*nums[j]);
            j++;
        }
        return ans;
    }

};

void printVector(vector<int> ans) {
    for(auto ele: ans){
        cout << ele << " ";
    }
    cout << endl;
}

int main() {
    Solution sol;
    vector<int>nums = {-4,-1,0,3,10};
    vector<int> ans = sol.sortedSquares(nums);
    printVector(ans);
    ans = sol.sortedSquaresMeth2(nums);
    printVector(ans);
    return 0;
}