/*
322. Coin Change
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coins supply


Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 
*/


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int climbStairsMem(int n, vector<int>& dp) {
        if(n<=2) return n;
        if(dp[n] != -1) return dp[n];
        dp[n] = climbStairs(n-1) + climbStairs(n-2);
        return dp[n];
    }
    int climbStairsTab(int n) {
        if(n<=2) return n;
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
int main() {
    Solution sol;
    int n = 4;
    vector<int> dp(n+1, -1);
    int ans = sol.climbStairsMem(n, dp);
    cout << ans << endl;
    ans = sol.climbStairsTab(n);
    cout << ans << endl;
    return 0;
}