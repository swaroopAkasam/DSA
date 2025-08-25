/*
628. Maximum Product of Three Numbers
Given an integer array nums, find three numbers whose product is maximum and return the maximum product.
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;
        
        for (int x : nums) {
            // Track top 3 maximums
            if (x > max1) {
                max3 = max2;
                max2 = max1;
                max1 = x;
            } else if (x > max2) {
                max3 = max2;
                max2 = x;
            } else if (x > max3) {
                max3 = x;
            }
            
            // Track two minimums
            if (x < min1) {
                min2 = min1;
                min1 = x;
            } else if (x < min2) {
                min2 = x;
            }
        }
        
        return max(max1 * max2 * max3, min1 * min2 * max1);
    }
};

int main() {
    Solution sol;

    vector<int> t1 = {1,2,3};
    cout << sol.maximumProduct(t1) << endl; // 6

    vector<int> t2 = {1,2,3,4};
    cout << sol.maximumProduct(t2) << endl; // 24 (2*3*4)

    vector<int> t3 = {-1,-2,-3};
    cout << sol.maximumProduct(t3) << endl; // -6 (-1*-2*-3)

    vector<int> t4 = {-10,-10,5,2};
    cout << sol.maximumProduct(t4) << endl; // 500 (-10*-10*5)

    vector<int> t5 = {-100,-98,-1,2,3,4};
    cout << sol.maximumProduct(t5) << endl; // 39200 (-100*-98*4)
}
