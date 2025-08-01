/*
77. Combinations
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.
Example 1:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
Example 2:

Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int start, int n, int k, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        for (int i = start; i <= n; i++) {
            current.push_back(i);
            backtrack(i + 1, n, k, current, result);
            current.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(1, n, k, current, result);
        return result;
    }
};

void printVect(vector<vector<int>>& v) {
    for(auto ele: v) {
        for(auto num: ele) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int main() {
    Solution sol;
    int n = 4;
    int k = 3;
    vector<vector<int>> ans = sol.combine(n, k);
    printVect(ans);
    return 0;
}