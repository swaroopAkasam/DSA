/*
Wave Array
Given an sorted array arr[] of integers. Sort the array into a wave-like array(In Place). In other words, arrange the elements into a sequence such that arr[1] >= arr[2] <= arr[3] >= arr[4] <= arr[5] ..... and so on. If there are multiple solutions, find the lexicographically smallest one.

Note: The given array is sorted in ascending order, and modify the given array in-place without returning a new array.

Difficulty: Easy
*/

#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(int n, vector<int>& arr){
        
        // Your code here
        for(int i=0; i<n-1; i+=2) {
            swap(arr[i], arr[i+1]);
        }
        
    }
};

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {1,2,3,4,5},          // Odd length
        {2,4,6,8},            // Even length
        {10},                 // Single element
        {1,2},                // Smallest valid wave
        {9,7,5,3,1,2},        // Unsorted input
        {1,1,1,1,1,1}         // All elements same
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test case " << i+1 << ": ";
        for (int num : testCases[i]) cout << num << " ";
        cout << "\nWave form: ";
        sol.convertToWave(testCases[i].size(), testCases[i]);
        for (int num : testCases[i]) cout << num << " ";
        cout << "\n\n";
    }

    return 0;
}
