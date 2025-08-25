/*
283. Move Zeroes
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for(int j=0; j<nums.size(); j++) {
            if(nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};

int main() {
    Solution sol;

    vector<int> t1 = {0,1,0,3,12};
    sol.moveZeroes(t1);
    for (int x : t1) cout << x << " "; 
    // Output: 1 3 12 0 0
    
    cout << endl;

    vector<int> t2 = {0};
    sol.moveZeroes(t2);
    for (int x : t2) cout << x << " "; 
    // Output: 0

    cout << endl;

    vector<int> t3 = {1,2,3};
    sol.moveZeroes(t3);
    for (int x : t3) cout << x << " "; 
    // Output: 1 2 3
    cout << endl;
}
