/*
1020. Number of Enclaves
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
*/

#include <bits/stdc++.h>
using namespace std;

class BfsSolution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if((i==0 || i==m-1 || j==0 || j==n-1) && grid[i][j]==1) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        vector<vector<int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(const auto &dir: directions) {
                int curr_row = row+dir[0];
                int curr_col = col+dir[1];
                if(curr_row>=0 && curr_col>=0 && curr_row<m && curr_col<n && grid[curr_row][curr_col]==1 && !vis[curr_row][curr_col]) {
                    vis[curr_row][curr_col] = 1;
                    q.push({curr_row, curr_col});
                }
            }
        }
        int ans = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==1 && !vis[i][j]) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

class DfsSolution {
public:
    vector<vector<int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& board) {
        vis[i][j] = 1;
        int m = board.size();
        int n = board[0].size(); 
        for(const auto &dir: directions) {
            int curr_x = i+dir[0];
            int curr_y = j+dir[1];
            if(curr_x>=0 && curr_y>=0 && curr_x<m && curr_y<n && board[curr_x][curr_y]==1 && !vis[curr_x][curr_y]) {
                dfs(curr_x, curr_y, vis, board);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int j=0; j<n; j++) {
            // First row
            if(!vis[0][j] && board[0][j]==1) {
                dfs(0, j, vis, board);
            }
            // Last row
            if(!vis[m-1][j] && board[m-1][j]==1) {
                dfs(m-1, j, vis, board);
            }
        }
        for(int i=0; i<m; i++) {
            // First col
            if(!vis[i][0] && board[i][0]==1) {
                dfs(i, 0, vis, board);
            }
            // Last col
            if(!vis[i][n-1] && board[i][n-1]==1) {
                dfs(i, n-1, vis, board);
            }
        }
        int ans = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j]==1 && !vis[i][j]) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main() {
    BfsSolution sol;
    // DfsSolution sol;

    // Test case 1
    vector<vector<int>> board1 = {
        {0,0,0,0},
        {1,0,1,0},
        {0,1,1,0},
        {0,0,0,0}
    };
    cout << "Test 1 Output: " << sol.numEnclaves(board1) << endl; // Expected 3

    // Test case 2
    vector<vector<int>> board2 = {
        {0,1,1,0},
        {0,0,1,0},
        {0,0,1,0},
        {0,0,0,0}
    };
    cout << "Test 2 Output: " << sol.numEnclaves(board2) << endl; // Expected 0

    // Test case 3 (all land touching boundary)
    vector<vector<int>> board3 = {
        {1,1,1},
        {1,1,1},
        {1,1,1}
    };
    cout << "Test 3 Output: " << sol.numEnclaves(board3) << endl; // Expected 0

    // Test case 4 (all water)
    vector<vector<int>> board4 = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };
    cout << "Test 4 Output: " << sol.numEnclaves(board4) << endl; // Expected 0

    // Test case 5 (single enclave in middle)
    vector<vector<int>> board5 = {
        {0,0,0,0,0},
        {0,1,1,1,0},
        {0,1,1,1,0},
        {0,0,0,0,0}
    };
    cout << "Test 5 Output: " << sol.numEnclaves(board5) << endl; // Expected 6

    return 0;
}