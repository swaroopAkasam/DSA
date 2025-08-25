/*
498. Diagonal Traverse
Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;
        for(int d=0; d<m+n-1; d++) {
            vector<int> temp;
            for(int row=0; row<m; row++) {
                int col = d-row;
                if(col>=0 && col<n) {
                    temp.push_back(mat[row][col]);
                }
            }
            if(d%2==0) {
                reverse(temp.begin(), temp.end());
            }
            ans.insert(ans.end(), temp.begin(), temp.end());
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> mat1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> ans1 = sol.findDiagonalOrder(mat1);
    cout << "Output: ";
    for (int x : ans1) cout << x << " ";
    cout << endl;

    vector<vector<int>> mat2 = {
        {1, 2},
        {3, 4}
    };

    vector<int> ans2 = sol.findDiagonalOrder(mat2);
    cout << "Output: ";
    for (int x : ans2) cout << x << " ";
    cout << endl;

    return 0;
}
