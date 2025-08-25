/*
498. Diagonal Traverse
Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.
*/

#include<bits/stdc++.h>
using namespace std;
/*
Explanation
1. What are we really doing?
When we traverse a matrix diagonally, we’re basically grouping cells that lie on the same diagonal line.
Notice: for each cell (row, col), the sum row + col is constant along the same diagonal.
Example (3x3 matrix with indices):
    (0,0) → sum = 0
    (0,1),(1,0) → sum = 1
    (0,2),(1,1),(2,0) → sum = 2
    (1,2),(2,1) → sum = 3
    (2,2) → sum = 4

2. Traversal Order
Now, how do we order them?
    For even sums (row+col even), we traverse the diagonal up-right.
    For odd sums (row+col odd), we traverse the diagonal down-left.

That m + n - 1 comes from counting how many diagonals a matrix has.
Why?
    A matrix has m rows and n columns.
    A diagonal is defined by row + col = constant.
    The smallest possible sum is when (row=0, col=0) → 0.
    The largest possible sum is when (row=m-1, col=n-1) → (m-1) + (n-1) = m + n - 2.
    So the valid values of row + col (our diagonal index) range from 0 to m + n - 2.
*/
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

/*
****Approach 2****:
Key Idea
Maintain (row, col) as your current position.
Maintain a direction flag:
    dir = 1 → moving up-right (↗️).
    dir = -1 → moving down-left (↙️).
At each step:
    Add mat[row][col] to the result.
    Try to move in the current direction:
        Up-right → (row-1, col+1)
        Down-left → (row+1, col-1)
If you hit a boundary → adjust position properly and flip direction.
*/
class Solution2 {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;
        int count = 0;
        int row = 0, col = 0, d = 1; // d==1 for up direction, -1 for down direction
        while(count<m*n) {
            count++;
            ans.push_back(mat[row][col]);
            if(d==1) {
                // up means row--, col++
                if(col==n-1) {
                    row++;
                    d=-1;
                }
                else if(row==0) {
                    col++;
                    d=-1;
                }
                else {
                    row--;
                    col++;
                }
            }
            else{
                // down means row++, col--
                if(row==m-1) {
                    col++;
                    d=1;
                }
                else if(col==0) {
                    row++;
                    d=1;
                }
                else{
                    row++; col--;
                }
            }
        }
        return ans;
    }
};

int main() {
    // Solution sol;
    Solution2 sol;

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
