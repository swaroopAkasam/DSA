/*
Rotate Array
Given an array arr[]. Rotate the array to the left (counter-clockwise direction) by d steps, where d is a positive integer. Do the mentioned change in the array in place.

Note: Consider the array as circular.
*/


#include<bits/stdc++.h>
using namespace std;

// // Using Extra Space (O(n))
// class Solution {
//   public:

//     // Function to rotate an array by d elements in counter-clockwise direction.
//     void rotateArr(vector<int>& arr, int d) {   
//         int n = arr.size();
//         if (n == 0) return;   // handle empty array
//         d = d % n;            // normalize d

//         vector<int> temp(n);
//         for (int i = 0; i < n; i++) {
//             temp[i] = arr[(i + d) % n];  // shift left by d
//         }
//         arr = temp;
//     }
// };

// class Solution {
//   public:

//     // Function to rotate an array by d elements in counter-clockwise direction.
//     void rotateArr(vector<int>& arr, int d) {   
//         int n = arr.size();
//         if (n == 0) return;   // handle empty array
//         d = d % n;            // normalize d

//         while(d--) {
//             int temp = arr[0];
//             for(int i=0; i<n-1; i++) {
//                 arr[i] = arr[i+1];
//             }
//             arr[n-1] = temp;
//         }
//     }
// };

// ***Reverse Algorithm (In-place, O(1) space)***

class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {   
        int n = arr.size();
        if (n == 0) return;   // handle empty array
        d = d % n;            // normalize d

        reverse(arr.begin(), arr.begin()+d);
        reverse(arr.begin()+d, arr.end());
        reverse(arr.begin(), arr.end());
    }
};


// Helper to print array
void printVector(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}


int main() {
    Solution sol;

    // Testcase 1: Basic left rotation
    vector<int> arr1 = {1, 2, 3, 4, 5};
    sol.rotateArr(arr1, 2); // Expected: 3 4 5 1 2
    cout << "Test 1: ";
    printVector(arr1);

    // Testcase 2: Rotation by 0 (no change)
    vector<int> arr2 = {10, 20, 30, 40};
    sol.rotateArr(arr2, 0); // Expected: 10 20 30 40
    cout << "Test 2: ";
    printVector(arr2);

    // Testcase 3: Rotation by n (no change)
    vector<int> arr3 = {7, 8, 9};
    sol.rotateArr(arr3, 3); // Expected: 7 8 9
    cout << "Test 3: ";
    printVector(arr3);

    // Testcase 4: Rotation by > n
    vector<int> arr4 = {1, 2, 3, 4, 5};
    sol.rotateArr(arr4, 7); // Same as rotate by 2, Expected: 3 4 5 1 2
    cout << "Test 4: ";
    printVector(arr4);

    // Testcase 5: Single element
    vector<int> arr5 = {42};
    sol.rotateArr(arr5, 5); // Expected: 42
    cout << "Test 5: ";
    printVector(arr5);

    // Testcase 6: Empty array
    vector<int> arr6 = {};
    sol.rotateArr(arr6, 2); // Expected: (empty output)
    cout << "Test 6: ";
    printVector(arr6);

    return 0;
}
