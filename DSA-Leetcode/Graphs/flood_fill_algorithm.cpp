/*
733. Flood Fill
You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int sr, int sc, vector<vector<int>>& image, int color, int old_color, vector<pair<int, int>>& directions) {
        if(image[sr][sc]==color) return;
        image[sr][sc] = color;
        int n = image.size();
        int m = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        while(!q.empty()) {
            int curr_x = q.front().first;
            int curr_y = q.front().second;
            q.pop();
            for(auto dir : directions) {
                int x_dir = dir.first;
                int y_dir = dir.second;
                int x = curr_x+x_dir;
                int y = curr_y+y_dir;
                if(x>=0 && x<n && y>=0 && y<m && image[x][y]==old_color) {
                    image[x][y] = color;
                    q.push({x, y});
                }
            }
        }
    }

    void dfs(int sr, int sc, vector<vector<int>>& image, int color, int old_color, vector<pair<int, int>>& directions) {
        if(image[sr][sc]==color) return;
        image[sr][sc] = color;
        int n = image.size();
        int m = image[0].size();
        for(auto dir : directions) {
            int x_dir = dir.first;
            int y_dir = dir.second;
            int x = sr+x_dir;
            int y = sc+y_dir;
            if(x>=0 && x<n && y>=0 && y<m && image[x][y]==old_color) {
                dfs(x, y, image, color, old_color, directions);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old_color = image[sr][sc];
        vector<pair<int, int>> directions = {{0,1}, {1,0},{-1,0},{0,-1}};
        // bfs(sr, sc, image, color, old_color, directions);
        dfs(sr, sc, image, color, old_color, directions);
        return image;
    }
};

int main() {
    Solution sol;
    // Input image (2D grid)
    vector<vector<int>> image = {
        {1, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 0, 1, 1}
    };
    
    // Starting pixel (row, col)
    int sr = 1, sc = 2;
    
    // New color to apply
    int newColor = 2;        

    // Perform flood fill and get the result
    vector<vector<int>> result = sol.floodFill(image, sr, sc, newColor);

    // Print the updated image
    for (auto& row : result) {
        for (auto& pixel : row) {
            cout << pixel << " ";
        }
        cout << "\n";
    }
    return 0;
}