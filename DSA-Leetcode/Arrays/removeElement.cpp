/*
27. Remove Element
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.

Difficulty: Easy
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != val){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {3, 2, 2, 3};
    int val1 = 3;
    int k1 = sol.removeElement(nums1, val1);
    cout << "Test 1 -> New length: " << k1 << ", Array: ";
    for(int i=0; i<k1; i++) cout << nums1[i] << " ";
    cout << endl;
    // Expected: length = 2, array = [2,2]

    // Test case 2
    vector<int> nums2 = {0,1,2,2,3,0,4,2};
    int val2 = 2;
    int k2 = sol.removeElement(nums2, val2);
    cout << "Test 2 -> New length: " << k2 << ", Array: ";
    for(int i=0; i<k2; i++) cout << nums2[i] << " ";
    cout << endl;
    // Expected: length = 5, array = [0,1,3,0,4]

    // Test case 3
    vector<int> nums3 = {1,1,1,1};
    int val3 = 1;
    int k3 = sol.removeElement(nums3, val3);
    cout << "Test 3 -> New length: " << k3 << ", Array: ";
    for(int i=0; i<k3; i++) cout << nums3[i] << " ";
    cout << endl;
    // Expected: length = 0, array = []

    // Test case 4
    vector<int> nums4 = {1,2,3,4,5};
    int val4 = 6;
    int k4 = sol.removeElement(nums4, val4);
    cout << "Test 4 -> New length: " << k4 << ", Array: ";
    for(int i=0; i<k4; i++) cout << nums4[i] << " ";
    cout << endl;
    // Expected: length = 5, array = [1,2,3,4,5]

    // Test case 5 (empty array)
    vector<int> nums5 = {};
    int val5 = 0;
    int k5 = sol.removeElement(nums5, val5);
    cout << "Test 5 -> New length: " << k5 << ", Array: ";
    for(int i=0; i<k5; i++) cout << nums5[i] << " ";
    cout << endl;
    // Expected: length = 0, array = []

    return 0;
}
