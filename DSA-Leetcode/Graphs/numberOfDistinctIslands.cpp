/*
GFG
Number of Distinct Islands

Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    void dfs(int i, int j, vector<pair<int, int>> &vec, vector<vector<int>>& grid, vector<vector<int>>& vis, int base_row, int base_col) {
        vis[i][j] = 1;
        vec.push_back({i-base_row, j-base_col});
        int n = grid.size();
        int m = grid[0].size();
        for(const auto &dir: directions) {
            int curr_x = i+dir[0];
            int curr_y = j+dir[1];
            if(curr_x>=0 && curr_y>=0 && curr_x<n && curr_y<m && !vis[curr_x][curr_y] && grid[curr_x][curr_y]==1) {
                dfs(curr_x, curr_y, vec, grid, vis, base_row, base_col);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
       int n = grid.size(); 
       int m = grid[0].size();
       set<vector<pair<int, int>>> st;
       vector<vector<int>> vis(n, vector<int>(m, 0));
       for(int i=0; i<n; i++) {
           for(int j=0; j<m; j++) {
               if(!vis[i][j] && grid[i][j]==1){
                   vector<pair<int, int>> vec;
                   dfs(i, j, vec, grid, vis, i, j);
                   st.insert(vec);
               }
           }
       }
       return st.size();
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 0, 0}
    };
    // Distinct shapes = 2

    cout << sol.countDistinctIslands(grid) << endl;
    return 0;
}

/*
Time Complexity
    Each cell visited once → O(n * m)
    DFS explores 4 directions per cell → O(1) extra per step
    Inserting into set costs O(K log K) where K = number of cells in island.
    But total K across all islands ≤ n*m.

    Overall O(n * m * log(n*m)) in worst case
    If you use unordered_set with hashing → average O(n * m)

Space Complexity
    vis matrix = O(n*m)
    Recursion stack = O(n*m) worst case (if one big island)
    Storing island shapes in set = O(n*m)
    Overall O(n*m)
*/