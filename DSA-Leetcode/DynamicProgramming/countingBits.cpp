/*
338. Counting Bits
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Meth 1: 
    int count(int n) {
        int count=0;
        while(n > 0) {
            count++;
            n = n & (n-1);
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0; i<=n; i++) {
            ans.push_back(count(i));
        }
        return ans;
    }
    // Meth 2:
    vector<int> countBitsDP(int n) {
        vector<int> dp(n+1, 0);
        int offset = 1;
        for(int i=1; i<=n; i++) {
            if(!(i&(i-1))) // To check if the number is poer of 2.
                offset = i;
            dp[i] = 1 + dp[i-offset];
        }
        return dp;
    }

    // Meth 3:
    vector<int> countBitsMeth3(int n) {
        vector<int> ans(n+1, 0);
        for(int i=0; i<=n; i++) {
            // for odd numbers
            if(i&1) {
                ans[i] = ans[i/2]+1;
            }
            // for even numbers
            else {
                ans[i] = ans[i/2];
            }
        }
        return ans;
    }
};

void printVect(vector<int> v) {
    for(auto ele: v) {
        cout << ele << " ";
    }
    cout << endl;
}
int main() {
    Solution sol;
    int n = 4;
    vector<int> ans = sol.countBits(n);
    printVect(ans);
    ans = sol.countBitsDP(n);
    printVect(ans);
    ans = sol.countBitsMeth3(n);
    printVect(ans);
    return 0;
}