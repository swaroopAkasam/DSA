/*
122. Best Time to Buy and Sell Stock II
Medium
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i=1; i<prices.size(); i++) {
            if(prices[i] > prices[i-1]) {
                profit += prices[i]-prices[i-1];
            }
        }
        return profit;
    }

    int maxProfitLocMinimaMaxima(vector<int>& prices) {
        int n = prices.size();
        
        // Local Minima
        int lMin = prices[0]; 
        
        // Local Maxima
        int lMax = prices[0];  
        int res = 0;
    
        int i = 0;
        while (i < n - 1) {
        
            // Find local minima 
            while (i < n - 1 && prices[i] >= prices[i + 1]) { i++; }
            lMin = prices[i];
        
            // Local Maxima
            while (i < n - 1 && prices[i] <= prices[i + 1]) { i++; }
            lMax = prices[i];
        
            // Add current profit 
            res = res + (lMax - lMin);
    }
  
    return res;
}
};


int main() {
    Solution sol;

    // Example test case
    vector<int> prices = {1, 2, 3};
    cout << "Prices: ";
    for (int p : prices) cout << p << " ";
    cout << "\n";

    int result = sol.maxProfit(prices);
    cout << "Max Profit = " << result << endl;  // Expected: 7 (buy at 1 sell at 5, buy at 3 sell at 6)

    return 0;
}