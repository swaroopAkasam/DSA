/*
Reverse array in groups
Given an array arr[] of positive integers. Reverse every sub-array group of size k.
Note: If at any instance, k is greater or equal to the array size, then reverse the entire array. 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void reverse(vector<int> &arr, int i, int j) {
        while (i < j) {
            swap(arr[i], arr[j]);
            i++; j--;
        }
    }

    void reverseInGroups(vector<int> &arr, int k) {
        int n = arr.size();
        if (k <= 0) return; // safety check

        for (int i = 0; i < n; i += k) {
            int right = min(i + k - 1, n - 1); // last index of this group
            reverse(arr, i, right);
        }
    }
};

void printArray(const vector<int>& arr) {
    for (int num : arr) cout << num << " ";
    cout << endl;
}

int main() {
    Solution sol;

    vector<vector<int>> testArrays = {
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5, 6, 7},
        {1, 2, 3, 4, 5},
        {1, 2, 3},
        {1, 2, 3},
        {}
    };

    vector<int> ks = {2, 3, 5, 10, 1, 3};

    for (int t = 0; t < testArrays.size(); t++) {
        cout << "Test case " << t + 1 << ": ";
        cout << "Input = ";
        printArray(testArrays[t]);
        cout << "k = " << ks[t] << endl;

        sol.reverseInGroups(testArrays[t], ks[t]);

        cout << "Output = ";
        printArray(testArrays[t]);
        cout << "-----------------------" << endl;
    }

    return 0;
}
