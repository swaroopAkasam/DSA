/*
130. Surrounded Regions
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& board) {
        vis[i][j] = 1;
        int m = board.size();
        int n = board[0].size(); 
        for(const auto &dir: directions) {
            int curr_x = i+dir[0];
            int curr_y = j+dir[1];
            if(curr_x>=0 && curr_y>=0 && curr_x<m && curr_y<n && board[curr_x][curr_y]=='O' && !vis[curr_x][curr_y]) {
                dfs(curr_x, curr_y, vis, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int j=0; j<n; j++) {
            // First row
            if(!vis[0][j] && board[0][j]=='O') {
                dfs(0, j, vis, board);
            }
            // Last row
            if(!vis[m-1][j] && board[m-1][j]=='O') {
                dfs(m-1, j, vis, board);
            }
        }
        for(int i=0; i<m; i++) {
            // First col
            if(!vis[i][0] && board[i][0]=='O') {
                dfs(i, 0, vis, board);
            }
            // Last col
            if(!vis[i][n-1] && board[i][n-1]=='O') {
                dfs(i, n-1, vis, board);
            }
        }
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j]=='O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

void printBoard(vector<vector<char>>& board) {
    for (auto &row : board) {
        for (auto &cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << "------" << endl;
}

int main() {
    Solution sol;

    // 🔹 Test case 1: Example from LeetCode
    vector<vector<char>> board1 = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };
    cout << "Test Case 1 (Before):\n";
    printBoard(board1);
    sol.solve(board1);
    cout << "After:\n";
    printBoard(board1);

    // 🔹 Test case 2: Surrounded O's should flip
    vector<vector<char>> board2 = {
        {'O','O','O'},
        {'O','O','O'},
        {'O','O','O'}
    };
    cout << "Test Case 2 (Before):\n";
    printBoard(board2);
    sol.solve(board2);
    cout << "After:\n";
    printBoard(board2);

    // 🔹 Test case 3: No surrounded regions
    vector<vector<char>> board3 = {
        {'O','X','X'},
        {'X','O','X'},
        {'X','X','O'}
    };
    cout << "Test Case 3 (Before):\n";
    printBoard(board3);
    sol.solve(board3);
    cout << "After:\n";
    printBoard(board3);

    // 🔹 Test case 4: Single row
    vector<vector<char>> board4 = {
        {'O','O','X','O','O'}
    };
    cout << "Test Case 4 (Before):\n";
    printBoard(board4);
    sol.solve(board4);
    cout << "After:\n";
    printBoard(board4);

    // 🔹 Test case 5: Single column
    vector<vector<char>> board5 = {
        {'O'},
        {'X'},
        {'O'},
        {'X'},
        {'O'}
    };
    cout << "Test Case 5 (Before):\n";
    printBoard(board5);
    sol.solve(board5);
    cout << "After:\n";
    printBoard(board5);

    return 0;
}

/*
Time Complexity (TC): O(m × n)
Key operations:
    DFS traversal:
    Each cell (i, j) can be visited at most once by DFS.
    Each DFS call processes up to 4 neighbors (O(1) per neighbor).
    So, the DFS part is O(m × n).
    Final flipping loop:
    You iterate once more over all cells to flip O → X if not visited.
    That’s also O(m × n).
    O(m × n) + O(m × n) = O(m × n)
Space Complexity (SC): O(m × n)
Components:
    Visited array (vis):
    Stores one entry per cell → O(m × n).
    Recursion stack (DFS):
    In the worst case (all cells are 'O'), recursion can go as deep as O(m × n).
    So recursion stack = O(m × n) in the worst case.
    Directions vector: constant size (4 entries) → O(1).
    O(m × n) (visited) + O(m × n) (recursion stack)
*/