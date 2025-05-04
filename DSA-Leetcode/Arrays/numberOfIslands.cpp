/*
200. Number of Islands
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int sr, int sc) {
        int row = grid.size();
        int col = grid[0].size();
        visited[sr][sc] = true;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while(!q.empty()) {
            pair<int, int> top = q.front();
            q.pop();
            for(auto dir : directions) {
                int dr = dir.first; int dc = dir.second;
                int nr = top.first + dr;
                int nc = top.second + dc;
                if(nr>=0 && nr<row && nc>=0 && nc<col && !visited[nr][nc] && grid[nr][nc] == '1') {
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }

    }

    void dfs(vector<vector<char>>& grid, int sr, int sc) {
        int row = grid.size();
        int col = grid[0].size();
        if(sr<0 || sc<0 || sr>=row || sc>=col || grid[sr][sc] != '1') {
            return;
        }
        grid[sr][sc] = 'V';
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(auto dir: directions) {
            int dr = dir.first; int dc = dir.second;
            int nr = sr + dr; int nc = sc + dc;
            dfs(grid, nr, nc);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        if(!r) return 0;
        int c = grid[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        int islands = 0;
        for(int i=0; i<r; i++) {                                                            
            for(int j=0; j<c; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    // bfs(grid, visited, i, j); // O(n*m) Time and O(n*m) Space
                    dfs(grid, i, j); // Space Optimized DFS – O(n*m) Time and O(1) Space
                    islands++;
                }
            }
        }
        return islands;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    // Call function and print result
    int result = sol.numIslands(grid);
    cout << "Number of Islands: " << result << endl;

    grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };  
    // Call function and print result
    result = sol.numIslands(grid);
    cout << "Number of Islands: " << result << endl;

    return 0;
}