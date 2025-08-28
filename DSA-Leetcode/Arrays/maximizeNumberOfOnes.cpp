/*
Maximize Number of 1's
Given a binary array arr[] containing only 0s and 1s and an integer k, you are allowed to flip at most k 0s to 1s. Find the maximum number of consecutive 1's that can be obtained in the array after performing the operation at most k times.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int n = arr.size();
        int left = 0, right = 0;
        int ans = 0, zeros = 0;
        for(; right<n; right++) {
            if(arr[right]==0) zeros++;
            while(zeros>k) {
                if(arr[left]==0) zeros--;
                left++;
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {1,1,0,0,1,1,0,1},   // Example with some 0s
        {1,1,1,1,1},         // Already all 1s
        {0,0,0,0},           // All zeros
        {1,0,1,0,1,0,1},     // Alternating 1s and 0s
        {1,0,0,1,1,0,1,1,1}  // Mixed
    };

    vector<int> ks = {2, 1, 3, 2, 2};

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test case " << i+1 << ": ";
        for (int num : testCases[i]) cout << num << " ";
        cout << "\nK = " << ks[i] << endl;
        int result = sol.maxOnes(testCases[i], ks[i]);
        cout << "Maximum consecutive 1's after at most " << ks[i] 
             << " flips: " << result << "\n\n";
    }

    return 0;
}
