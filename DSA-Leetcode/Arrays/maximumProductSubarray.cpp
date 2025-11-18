/*
152. Maximum Product Subarray
Medium
Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

Note that the product of an array with a single element is the value of that element.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = 1, currMin = 1;
        int ans = INT_MIN;
        for(const int ele: nums) {
            if(ele == 0) {
                ans = max(ans, 0);
                currMax = 1; currMin = 1;
                continue;
            }
            int tmp = currMax*ele;
            currMax = max({tmp, currMin*ele, ele});
            currMin = min({tmp, currMin*ele, ele});

            ans = max({ans, currMax});
        }
        return ans;
    }
};

class Solution2 {
public:
    int maxProduct(vector<int>& nums) {
        int left = 1;
        int right = 1;
        int ans = INT_MIN;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(left==0) left = 1;
            if(right==0) right = 1;
            left = left*nums[i];
            right = right*nums[n-i-1];
            ans = max({ans, left, right});
        }
        return ans;
    }
};

// Kadanes
/*
WHY DO WE SWAP currMax AND currMin WHEN x IS NEGATIVE?
Because multiplying by a negative number flips signs:
a positive number becomes negative
a negative number becomes positive
So:
The best (maximum) product so far may suddenly become the worst (minimum).
The worst (minimum) product so far may suddenly become the best (maximum).
To handle this, we simply swap them before multiplying.
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = nums[0];
        int currMin = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i];

            // When x is negative, currMax and currMin swap roles
            if (x < 0) {
                swap(currMax, currMin);
            }

            currMax = max(x, currMax * x);
            currMin = min(x, currMin * x);

            ans = max(ans, currMax);
        }

        return ans;
    }
};

int main() {
    Solution1 sol;

    // Test cases
    vector<vector<int>> tests = {
        {2, 3, -2, 4},          // Expected: 6
        {-2, 0, -1},            // Expected: 0
        {-2},                   // Expected: -2
        {-2, 3, -4},            // Expected: 24
        {0, 2},                 // Expected: 2
        {-1, -3, -10, 0, 60},   // Expected: 60
        {-2, -3, 0, -2, -40},   // Expected: 80
        {1, 2, 3, 4},           // Expected: 24
        {1, -2, -3, 4},         // Expected: 24
        {-1, -2, -3, -4},       // Expected: 24
    };

    for (auto& test : tests) {
        int res = sol.maxProduct(test);
        cout << "Input: ";
        for (int x : test) cout << x << " ";
        cout << "\nMaximum Product Subarray = " << res << "\n\n";
    }

    return 0;
}