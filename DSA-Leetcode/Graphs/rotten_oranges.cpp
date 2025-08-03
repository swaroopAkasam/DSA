/*
994. Rotting Oranges
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bfs(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==2) q.push({i, j});
                else if(grid[i][j]==1) fresh++;
            }
        }
        if(!fresh) return 0;

        int minutes = -1;
        vector<pair<int, int>> directions = {{0,-1}, {-1,0}, {0,1}, {1,0}};

        while(!q.empty()) {
            int sz = q.size();
            minutes++;
            while(sz--) {
                pair<int, int> front = q.front(); q.pop();
                int curr_i = front.first;
                int curr_j = front.second;
                for(auto dir: directions) {
                    int nx = curr_i+dir.first;
                    int ny = curr_j+dir.second;
                    if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                    }
                }
            }
        }
        return fresh==0 ? minutes : -1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};

int main() {
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };
    Solution sol;
    cout << sol.orangesRotting(grid) << endl;
    return 0;
}