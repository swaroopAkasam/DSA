/*
Find the number of islands
Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of 'W's (Water) and 'L's (Land). Find the number of islands.

Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visited) {
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int x=-1; x<=1; x++) {
                for(int y=-1; y<=1; y++) {
                    int curr_row = r+x;
                    int curr_col = c+y;
                    if(curr_row>=0 && curr_row<n && curr_col<m && curr_col>=0 && !visited[curr_row][curr_col] && grid[curr_row][curr_col] == 'L') {
                        visited[curr_row][curr_col] = 1;
                        q.push({curr_row, curr_col});
                    }
                }
            }
        }
    }

    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int> (m,0));
        int ans = 0;
        for(int row=0; row<n; row++) {
            for(int col=0; col<m; col++) {
                if(!visited[row][col] && grid[row][col]=='L') {
                    ans++;
                    bfs(row, col, grid, visited);
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<char>> grid =
    {
        {'L', 'L', 'W', 'W', 'W'},
        {'W', 'L', 'W', 'W', 'L'},
        {'L', 'W', 'W', 'L', 'L'},
        {'W', 'W', 'W', 'W', 'W'},
        {'L', 'W', 'L', 'L', 'W'}
    };
    Solution sol;
    cout << sol.countIslands(grid) << endl; 
    return 0;
}