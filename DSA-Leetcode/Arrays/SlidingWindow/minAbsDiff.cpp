/*
1200. Minimum Absolute Difference
Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.

Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr
Example 2:

Input: arr = [1,3,6,10,15]
Output: [[1,3]]
Example 3:

Input: arr = [3,8,-10,23,19,-4,-14,27]
Output: [[-14,-10],[19,23],[23,27]]
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int n = arr.size();
        int mini = INT_MAX;
        for(int i=0; i<n-1; i++) {
            mini = min(mini, abs(arr[i]-arr[i+1]));
        }
        for(int i=0; i<n-1; i++) {
            if(abs(arr[i]-arr[i+1]) == mini) {
                ans.push_back({arr[i], arr[i+1]});
            }
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int>nums = {3,8,-10,23,19,-4,-14,27};
    bool ans = sol.minimumAbsDifference(nums);
    cout << ans << endl;
    return 0;
}