
/*
1493. Longest Subarray of 1's After Deleting One Element
Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, zeros = 0, ans = 0;

        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) zeros++;

            // shrink window if more than 1 zero
            while (zeros > 1) {
                if (nums[left] == 0) zeros--;
                left++;
            }

            // window length minus one zero
            ans = max(ans, right - left);
        }

        return ans;
    }
};


int main() {
    Solution sol;

    vector<int> nums1 = {0,1,1,1,0,1,1,0,1};
    cout << sol.longestSubarray(nums1) << endl; // 5

    vector<int> nums2 = {1,1,1};
    cout << sol.longestSubarray(nums2) << endl; // 2 (must delete one)

    vector<int> nums3 = {1,1,0,1};
    cout << sol.longestSubarray(nums3) << endl; // 3

    vector<int> nums4 = {0,0,0};
    cout << sol.longestSubarray(nums4) << endl; // 0

    return 0;
}

/*
Time Complexity: O(n) (each index visited at most twice).
Space Complexity: O(1) (just pointers & counters).
*/