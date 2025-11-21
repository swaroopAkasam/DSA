/*
48. Rotate Image

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>rotate(vector<vector<int>>& arr) {
    int n = arr.size();
    vector<vector<int>> rotated(n, vector<int>(n, 0));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            rotated[j][n-i-1] = arr[i][j];
        }
    }

    return rotated;
}

void rotateOptimal(vector < vector < int >> & matrix) {
    int n = matrix.size();
    //transposing the matrix
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
        swap(matrix[i][j], matrix[j][i]);
    }
    }
    //reversing each row of the matrix
    for (int i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
    }
}


void rotateOptimal2(vector < vector < int >> & matrix) {
    int n = matrix.size();
    int l = 0;
    int r = n-1;
    while(l<r) {
        for(int i=0; i<(r-l); i++) {
            int top = l;
            int bottom = r;
            // save top left
            int topLeft = matrix[top][l+i];

            // move bottom left into top left
            matrix[top][l+i] = matrix[bottom-i][l];

            // move bottom right into bottom left
            matrix[bottom-i][l] = matrix[bottom][r-i];

            // move top right to bottom right
            matrix[bottom][r-i] = matrix[top+i][r];

            // move top left into top right
            matrix[top+i][r] = topLeft;
        }
        r--;
        l++;
    }
}

void printMatrix(vector<vector<int>>& arr) {
    for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); j++) {
        cout << arr[i][j] << " ";
    }
    cout << "\n";
    }
}

int main() {
    vector<vector<int>> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    printMatrix(arr);
    // vector<vector<int>> rotated = rotate(arr);
    // cout << "Rotated Image" << endl;
    // printMatrix(rotated);

    rotateOptimal2(arr);
    cout << "Rotated Image" << endl;
    printMatrix(arr);
    return 0;
}


