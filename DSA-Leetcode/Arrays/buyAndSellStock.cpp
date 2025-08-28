/*
Stock Buy and Sell – Max one Transaction Allowed
Given an array prices[] of length n, representing the prices of the stocks on different days. The task is to find the maximum profit possible by buying and selling the stocks on different days when at most one transaction is allowed. Here one transaction means 1 buy + 1 Sell. If it is not possible to make a profit then return 0.

Note: Stock must be bought before being sold.

Difficulty: Easy
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int mini = INT_MAX;
        int ans = 0;
        for(auto ele: prices) {
            mini = min(mini, ele);
            ans = max(ans, ele - mini);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {7,1,5,3,6,4},    // buy at 1, sell at 6 → profit = 5
        {7,6,4,3,1},      // always decreasing → profit = 0
        {1,2,3,4,5},      // buy at 1, sell at 5 → profit = 4
        {2,4,1},          // buy at 2, sell at 4 → profit = 2
        {3,3,3,3},        // flat prices → profit = 0
        {1},              // single element → profit = 0
        {2,1,2,1,2,1,2},  // buy at 1, sell at 2 → profit = 1
        {100,180,260,310,40,535,695} // buy at 40, sell at 695 → profit = 655
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test case " << i+1 << ": ";
        for (int p : testCases[i]) cout << p << " ";
        int result = sol.maximumProfit(testCases[i]);
        cout << "\nMaximum Profit = " << result << "\n\n";
    }

    return 0;
}
