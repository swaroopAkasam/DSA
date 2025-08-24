/*
542. 01 Matrix
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.

Note: This question is the same as 1765: https://leetcode.com/problems/map-of-highest-peak/


*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<int>> distance;
    vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
    
    void dfs(int row, int col) {
        for (auto &dir : directions) {
            int nr = row + dir[0];
            int nc = col + dir[1];
            if (nr >= 0 && nc >= 0 && nr < m && nc < n) {
                if (distance[nr][nc] > distance[row][col] + 1) {
                    distance[nr][nc] = distance[row][col] + 1;
                    dfs(nr, nc);
                }
            }
        }
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        distance.assign(m, vector<int>(n, INT_MAX));
        
        // Initialize distances for 0s
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    distance[i][j] = 0;
                }
            }
        }
        
        // Run DFS from each 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dfs(i, j);
                }
            }
        }
        
        return distance;
    }
};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> distance(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j]==0) {
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }
        vector<vector<int>> directions = {{0, -1},{0, 1},{1, 0},{-1, 0}};
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            distance[row][col] = dist;
            for(auto &dir: directions) {
                int curr_row = row+dir[0];
                int curr_col = col+dir[1];
                if(curr_row>=0 && curr_col>=0 && curr_row<m && curr_col<n && vis[curr_row][curr_col]==0) {
                    vis[curr_row][curr_col] = 1;
                    q.push({{curr_row, curr_col}, dist+1});
                }
            }
        }
        return distance;
    }
};

void printMatrix(vector<vector<int>> mat) {
    for (auto &row : mat) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << "------" << endl;
}

int main() {
    Solution sol;

    // 🔹 Test case 1: Simple matrix
    vector<vector<int>> mat1 = {
        {0,1,1},
        {1,1,1},
        {1,1,0}
    };
    cout << "Test Case 1:" << endl;
    printMatrix(sol.updateMatrix(mat1));

    // 🔹 Test case 2: Single 0
    vector<vector<int>> mat2 = {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };
    cout << "Test Case 2:" << endl;
    printMatrix(sol.updateMatrix(mat2));

    // 🔹 Test case 3: All 0s
    vector<vector<int>> mat3 = {
        {0,0},
        {0,0}
    };
    cout << "Test Case 3:" << endl;
    printMatrix(sol.updateMatrix(mat3));

    // 🔹 Test case 4: Single row
    vector<vector<int>> mat4 = {
        {1,0,1,1,0,1}
    };
    cout << "Test Case 4:" << endl;
    printMatrix(sol.updateMatrix(mat4));

    // 🔹 Test case 5: Single column
    vector<vector<int>> mat5 = {
        {1},
        {0},
        {1},
        {1},
        {0}
    };
    cout << "Test Case 5:" << endl;
    printMatrix(sol.updateMatrix(mat5));

    return 0;
}
