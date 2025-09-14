/*
31. Next Permutation
Medium
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1;
        int n = nums.size();
        for(int i=n-2; i>=0; i--) {
            if(nums[i] < nums[i+1]) {
                pivot = i;
                break;
            }
        }
        if(pivot == -1) {
            reverse(nums.begin(), nums.end());
        }
        else {
            for(int i=n-1; i>pivot; i--) {
                if(nums[i] > nums[pivot]) {
                    swap(nums[i], nums[pivot]);
                    break;
                }
            }
            reverse(nums.begin()+pivot+1, nums.end());
        }
    }
};

/*
Time Complexity
    Finding pivot: O(n) (scan from right).
    Finding the rightmost successor: O(n) in worst case.
    Reversing the suffix: O(n).
    Total = O(n)

Space Complexity
    Works in-place (only swaps and reverses).
    Extra space = O(1)
*/

// Utility to print vector
void printVector(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << endl;
}

int main() {
    Solution sol;

    // Test case 1: Example case
    vector<int> v1 = {2,1,5,3,4,0,0};
    sol.nextPermutation(v1);
    cout << "Next permutation of [2,1,5,3,4,0,0]: ";
    printVector(v1); // Expected: 2 1 5 4 0 0 3

    // Test case 2: Already largest permutation
    vector<int> v2 = {3,2,1};
    sol.nextPermutation(v2);
    cout << "Next permutation of [3,2,1]: ";
    printVector(v2); // Expected: 1 2 3

    // Test case 3: Already smallest permutation
    vector<int> v3 = {1,2,3};
    sol.nextPermutation(v3);
    cout << "Next permutation of [1,2,3]: ";
    printVector(v3); // Expected: 1 3 2

    // Test case 4: With duplicates
    vector<int> v4 = {1,1,5};
    sol.nextPermutation(v4);
    cout << "Next permutation of [1,1,5]: ";
    printVector(v4); // Expected: 1 5 1

    // Test case 5: Single element
    vector<int> v5 = {7};
    sol.nextPermutation(v5);
    cout << "Next permutation of [7]: ";
    printVector(v5); // Expected: 7

    // Test case 6: Two elements
    vector<int> v6 = {1,5};
    sol.nextPermutation(v6);
    cout << "Next permutation of [1,5]: ";
    printVector(v6); // Expected: 5 1

    return 0;
}
