/*
Leetcode:
2149. Rearrange Array Elements by Sign
You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should return the array of nums such that the the array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

GFG:
Alternate Positive Negative
Given an unsorted array arr containing both positive and negative numbers. Your task is to rearrange the array and convert it into an array of alternate positive and negative numbers without changing the relative order.

Note:
- Resulting array should start with a positive integer (0 will also be considered as a positive integer).
- If any of the positive or negative integers are exhausted, then add the remaining integers in the answer as it is by maintaining the relative order.
- The array may or may not have the equal number of positive and negative integers.

Difficulty: Easy/Medium
*/


#include <bits/stdc++.h>
using namespace std;



// Leetcode 
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        for (int x : nums) {
            if (x > 0) pos.push_back(x);
            else neg.push_back(x);
        }

        vector<int> ans;
        int n = pos.size(); // same as neg.size()
        for (int i = 0; i < n; i++) {
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
    }
};


// Leetcode
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        int posIndex = 0; // even positions
        int negIndex = 1; // odd positions
        
        for (int x : nums) {
            if (x > 0) {
                ans[posIndex] = x;
                posIndex += 2;
            } else {
                ans[negIndex] = x;
                negIndex += 2;
            }
        }
        
        return ans;
    }
};

// Leetcode
// in-place solution that preserves order.
// But this algo hits TLE for large inputs.
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // Check if current index has correct sign
            if (i % 2 == 0 && nums[i] < 0) {
                // even index must be positive
                int j = i + 1;
                while (j < n && nums[j] < 0) j++;
                if (j == n) break; // no more positives left
                rightRotate(nums, i, j);
            } 
            else if (i % 2 == 1 && nums[i] > 0) {
                // odd index must be negative
                int j = i + 1;
                while (j < n && nums[j] > 0) j++;
                if (j == n) break; // no more negatives left
                rightRotate(nums, i, j);
            }
        }
        
        return nums;
    }

private:
    // Utility to right rotate subarray [i..j]
    void rightRotate(vector<int>& nums, int i, int j) {
        int temp = nums[j];
        for (int k = j; k > i; k--) {
            nums[k] = nums[k - 1];
        }
        nums[i] = temp;
    }
};


// GFG
class Solution {
  public:
    vector<int> rearrange(vector<int> &nums) {
        vector<int> pos, neg;
        vector<int> arr(nums.size());
        for(const int ele: nums) {
            if(ele>=0) pos.push_back(ele);
            else
              neg.push_back(ele);
        }
        int i=0, j=0;
        int idx = 0;
        while(i<pos.size() && j<neg.size()) {
            arr[idx++] = pos[i++];
            arr[idx++] = neg[j++];
        }
        while(i<pos.size()) {
            arr[idx++] = pos[i++];
        }
        while(j<neg.size()) {
            arr[idx++] = neg[j++];
        }
    }
};

// Gfg
class Solution {
  public:
    void rearrange(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            bool needPositive = (i % 2 == 0);  // even index -> positive
            
            if (needPositive && arr[i] < 0) {
                // find next positive
                int j = i + 1;
                while (j < n && arr[j] < 0) j++;
                if (j == n) return; // no more positives
                rotate(arr.begin() + i, arr.begin() + j, arr.begin() + j + 1);
            }
            else if (!needPositive && arr[i] >= 0) {
                // find next negative
                int j = i + 1;
                while (j < n && arr[j] >= 0) j++;
                if (j == n) return; // no more negatives
                rotate(arr.begin() + i, arr.begin() + j, arr.begin() + j + 1);
            }
        }
    }
};



int main() {
    Solution sol;

    vector<int> arr1 = {1, 2, 3, -4, -1, 4};
    auto res1 = sol.rearrange(arr1);
    cout << "Test 1 -> ";
    for (int x : res1) cout << x << " ";
    cout << endl;
    // Expected: 1 -4 2 -1 3 4

    vector<int> arr2 = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    auto res2 = sol.rearrange(arr2);
    cout << "Test 2 -> ";
    for (int x : res2) cout << x << " ";
    cout << endl;
    // Expected: 5 -5 2 -2 4 -8 7 1 8 0

    vector<int> arr3 = {-1, -2, -3, -4};
    auto res3 = sol.rearrange(arr3);
    cout << "Test 3 -> ";
    for (int x : res3) cout << x << " ";
    cout << endl;
    // Expected: -1 -2 -3 -4 (all negatives)

    vector<int> arr4 = {0, 2, 4, 6};
    auto res4 = sol.rearrange(arr4);
    cout << "Test 4 -> ";
    for (int x : res4) cout << x << " ";
    cout << endl;
    // Expected: 0 2 4 6 (all positives, starting with 0)

    return 0;
}
