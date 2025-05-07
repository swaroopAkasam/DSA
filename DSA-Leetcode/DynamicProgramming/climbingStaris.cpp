/*
70. Climbing Stairs

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?


Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 
*/


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int solveRecursive(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;
        int ans = INT_MAX;
        for(auto ele: coins) {
            int curr = solveRecursive(coins, amount-ele);
            if(curr != INT_MAX) {
                ans = min(ans, curr+1);
            }
        }
        return ans;
    }
    int solveMem(vector<int>& coins, int amount, vector<int>& dp) {
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;
        if(dp[amount]!=-1) return dp[amount];
        int ans = INT_MAX;
        for(auto ele: coins) {
            int curr = solveMem(coins, amount-ele, dp);
            if(curr != INT_MAX) {
                ans = min(ans, curr+1);
            }
        }
        dp[amount] = ans; 
        return dp[amount];
    }
    int solveTab(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int i=1; i<=amount; i++) {
            for(auto ele: coins) {
                if(i-ele >=0 && dp[i-ele] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i-ele] + 1);
                }
            }
        }
        if(dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};
int main() {
    Solution sol;
    vector<int> coins = {1,2,5};
    int amount = 11;
    int ans =  sol.solveRecursive(coins, amount);
    ans = ans == INT_MAX ? -1 : ans;
    cout << ans << endl;
    vector<int> dp(amount+1, -1);
    ans = sol.solveMem(coins, amount, dp);
    ans = ans == INT_MAX ? -1 : ans;
    cout << ans << endl;
    ans = sol.solveTab(coins, amount);
    ans = ans == INT_MAX ? -1 : ans;
    cout << ans << endl;
}