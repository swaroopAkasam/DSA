/*
88. Merge Sorted Array
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

// Function to print a vector
void printVector(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1_1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2_1 = {2, 5, 6};
    sol.merge(nums1_1, 3, nums2_1, 3);
    cout << "Test Case 1: ";
    printVector(nums1_1); // Expected: 1 2 2 3 5 6

    // Test Case 2
    vector<int> nums1_2 = {1};
    vector<int> nums2_2 = {};
    sol.merge(nums1_2, 1, nums2_2, 0);
    cout << "Test Case 2: ";
    printVector(nums1_2); // Expected: 1

    // Test Case 3
    vector<int> nums1_3 = {0};
    vector<int> nums2_3 = {1};
    sol.merge(nums1_3, 0, nums2_3, 1);
    cout << "Test Case 3: ";
    printVector(nums1_3); // Expected: 1

    // Test Case 4
    vector<int> nums1_4 = {4, 5, 6, 0, 0, 0};
    vector<int> nums2_4 = {1, 2, 3};
    sol.merge(nums1_4, 3, nums2_4, 3);
    cout << "Test Case 4: ";
    printVector(nums1_4); // Expected: 1 2 3 4 5 6

    // Test Case 5 (Duplicate elements)
    vector<int> nums1_5 = {1, 1, 1, 0, 0, 0};
    vector<int> nums2_5 = {1, 1, 1};
    sol.merge(nums1_5, 3, nums2_5, 3);
    cout << "Test Case 5: ";
    printVector(nums1_5); // Expected: 1 1 1 1 1 1

    return 0;
}
