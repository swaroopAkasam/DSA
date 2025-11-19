/*
73. Set Matrix Zeroes
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.
*/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach Start
void markRow(vector<vector<int>>& matrix, int n, int m, int i) {
    for(int j=0; j<m; j++) {
        if(matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}
void markCol(vector<vector<int>>& matrix, int n, int m, int j) {
    for(int i=0; i<n; i++) {
        if(matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}
void setZeroesBrute(vector<vector<int>>& matrix, int n, int m) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(matrix[i][j] == 0) {
                markRow(matrix, n, m, i);
                markCol(matrix, n, m, j);
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }
}
/*
Time Complexity: O((N*M)*(N + M)) + O(N*M), where N = no. of rows in the matrix and M = no. of columns in the matrix.
Reason: Firstly, we are traversing the matrix to find the cells with the value 0. It takes O(N*M). Now, whenever we find any such cell we mark that row and column with -1. This process takes O(N+M). So, combining this the whole process, finding and marking, takes O((N*M)*(N + M)).
Another O(N*M) is taken to mark all the cells with -1 as 0 finally.

Space Complexity: O(1) as we are not using any extra space.
*/
// Brute Force Approach Start


// Better Approach Start
vector<vector<int>> zeroMatrixBetter(vector<vector<int>> &matrix, int n, int m) {

    int row[n] = {0}; // row array
    int col[m] = {0}; // col array

    // Traverse the matrix:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark ith index of row wih 1:
                row[i] = 1;

                // mark jth index of col wih 1:
                col[j] = 1;
            }
        }
    }

    // Finally, mark all (i, j) as 0
    // if row[i] or col[j] is marked with 1.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}
/*
Time Complexity: O(2*(N*M)), where N = no. of rows in the matrix and M = no. of columns in the matrix.
Reason: We are traversing the entire matrix 2 times and each traversal is taking O(N*M) time complexity.

Space Complexity: O(N) + O(M), where N = no. of rows in the matrix and M = no. of columns in the matrix.
Reason: O(N) is for using the row array and O(M) is for using the col array.
*/
// Better Approach End

// Optimal Approach Start
void setZeroesOptimal(vector<vector<int>>& matrix, int n, int m) {
    int col0 = 1;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(matrix[i][j]==0) {
                matrix[i][0] = 0;

                if(j!=0) matrix[0][j] = 0;
                else col0 = 0; 
            }
        }
    }

    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            if(matrix[i][j]!=0) {
                if(matrix[i][0] || matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    if(matrix[0][0]==0) {
        for(int j=0; j<m; j++) {
            matrix[0][j] = 0;
        }
    }
    if(col0 == 0) {
        for(int i=0; i<n; i++) {
            matrix[i][0] = 0;
        }
    }
}
/*
Time Complexity: O(2*(N*M)), where N = no. of rows in the matrix and M = no. of columns in the matrix.
Reason: In this approach, we are also traversing the entire matrix 2 times and each traversal is taking O(N*M) time complexity.

Space Complexity: O(1) as we are not using any extra space.
*/
// Optimal Approach End


void printMatrix(vector<vector<int>>& matrix) {
    cout << "The Final matrix is: \n";
    for (auto it : matrix) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    printMatrix(matrix); cout << endl;
    int n = matrix.size();
    int m = matrix[0].size();
    // setZeroesBrute(matrix, n, m);
    // zeroMatrixBetter(matrix, n, m);
    setZeroesOptimal(matrix, n, m);
    printMatrix(matrix);

    return 0;
}