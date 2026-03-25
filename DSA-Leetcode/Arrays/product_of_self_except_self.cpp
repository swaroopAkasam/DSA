/*
238. Product of Array Except Self
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            int prod = 1;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    prod *= nums[j];
                }
            }
            res[i] = prod;
        }
        return res;
    }
    // Time complexity: O(n^2)
    // Space complexity: O(n) space for the output array.

    vector<int> productExceptSelfDivision(vector<int>& nums) {
        int prod = 1, zeroCount = 0;
        for(int num: nums) {
            if(num!=0) {
                prod*=num;
            }
            else zeroCount++;
        }
        if(zeroCount>1) {
            return vector<int> (nums.size(), 0);
        }
        vector<int> ans(nums.size());
        for(int i=0; i<nums.size(); i++) {
            if(zeroCount>0) {
                ans[i] = (nums[i]==0) ? prod : 0;
            }
            else {
                ans[i] = prod / nums[i];
            }
        }
        return ans;
    }
    // Time complexity: O(n)
    // Space complexity: O(n) space for the output array.   

    vector<int> productExceptSelfPrefixSuffix(vector<int>& nums) {
        
    }
};

void printVector(const vector<int>& v) {
    cout << "[ ";
    for (int x : v) cout << x << " ";
    cout << "]\n";
}

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {1, 2, 3, 4},
        {2, 3, 4, 5},
        {1, 0, 3, 4},
        {0, 0, 2, 3},
        {5}
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test case " << i + 1 << ":\n";
        cout << "Input:  ";
        printVector(testCases[i]);

        vector<int> result = sol.productExceptSelf(testCases[i]);

        cout << "Output: ";
        printVector(result);
        cout << "--------------------\n";
    }

    return 0;
}
