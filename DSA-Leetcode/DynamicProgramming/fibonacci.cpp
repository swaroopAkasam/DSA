#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fibonacciTopDown(int n, vector<int>& dp) {
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
        int ans = fibonacciTopDown(n-1, dp) + fibonacciTopDown(n-2, dp);
        dp[n] = ans;
        return dp[n];
    }

    int fibonacciTabulation(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }

    int fibonacciSpaceOpt(int n) {
        int prev1 = 0, prev2 = 1;
        if(n<=1) return n;
        for(int i=2; i<=n; i++) {
            int curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }
};

int main() {
    Solution sol;
    int n = 10;
    vector<int> dp(n+1, -1);
    int ans = sol.fibonacciTopDown(n, dp);
    cout << ans << endl;
    ans = sol.fibonacciTabulation(n);
    cout << ans << endl;
    ans = sol.fibonacciSpaceOpt(n);
    cout << ans << endl;
    return 0;
}