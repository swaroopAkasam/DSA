/*
Remove Duplicates Sorted Array
You are given a sorted array arr[] containing positive integers. Your task is to remove all duplicate elements from this array such that each element appears only once. Return an array containing these distinct elements in the same order as they appeared.

Leet:
26. Remove Duplicates from Sorted Array
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.

Difficulty: Easy
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to remove duplicates from the given array.
    vector<int> removeDuplicates(vector<int> &arr) {
        vector<int> ans;
        int n = arr.size();
        if(n<=1) return arr;
        int curr = arr[0];
        ans.push_back(curr);
        for(int i=1; i<n; i++) {
            if(curr == arr[i]) continue;
            else {
                curr = arr[i];
                ans.push_back(curr);
            }
        }
        return ans;
    }
};

/*
// Leetcode
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int it=0; 
        for(int i=1; i<nums.size();i++){
            if(nums[i]!=nums[it]){
                it++;
                nums[it] = nums[i];
            }            
        }     
        return ++it;
    }
};

*/

int main() {
    Solution sol;

    // Test case 1: Normal case
    vector<int> arr1 = {1,1,2,2,3,3,4};
    vector<int> res1 = sol.removeDuplicates(arr1);
    cout << "Test 1 -> ";
    for(int x : res1) cout << x << " ";
    cout << endl;
    // Expected: 1 2 3 4

    // Test case 2: Already unique
    vector<int> arr2 = {1,2,3,4,5};
    vector<int> res2 = sol.removeDuplicates(arr2);
    cout << "Test 2 -> ";
    for(int x : res2) cout << x << " ";
    cout << endl;
    // Expected: 1 2 3 4 5

    // Test case 3: All elements same
    vector<int> arr3 = {7,7,7,7};
    vector<int> res3 = sol.removeDuplicates(arr3);
    cout << "Test 3 -> ";
    for(int x : res3) cout << x << " ";
    cout << endl;
    // Expected: 7

    // Test case 4: Single element
    vector<int> arr4 = {10};
    vector<int> res4 = sol.removeDuplicates(arr4);
    cout << "Test 4 -> ";
    for(int x : res4) cout << x << " ";
    cout << endl;
    // Expected: 10

    // Test case 5: Empty array
    vector<int> arr5 = {};
    vector<int> res5 = sol.removeDuplicates(arr5);
    cout << "Test 5 -> ";
    for(int x : res5) cout << x << " ";
    cout << endl;
    // Expected: (prints nothing)

    return 0;
}
