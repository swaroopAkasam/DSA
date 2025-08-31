/*
GFG
Array Leaders
You are given an array arr of positive integers. Your task is to find all the leaders in the array. An element is considered a leader if it is greater than or equal to all elements to its right. The rightmost element is always a leader.

Difficulty: Easy
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the leaders in the array.
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        
        int maxi_ele = arr[n-1];
        for(int i=n-1; i>=0; i--){
            if(arr[i] >= maxi_ele) {
                ans.push_back(arr[i]);
                maxi_ele = arr[i];
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> arr1 = {16, 17, 4, 3, 5, 2};
    vector<int> res1 = sol.leaders(arr1);
    cout << "Leaders in arr1: ";
    for(int x : res1) cout << x << " ";
    cout << "\n";  // Expected: 17 5 2

    // Test case 2
    vector<int> arr2 = {1, 2, 3, 4, 0};
    vector<int> res2 = sol.leaders(arr2);
    cout << "Leaders in arr2: ";
    for(int x : res2) cout << x << " ";
    cout << "\n";  // Expected: 4 0

    // Test case 3
    vector<int> arr3 = {7, 10, 4, 10, 6, 5, 2};
    vector<int> res3 = sol.leaders(arr3);
    cout << "Leaders in arr3: ";
    for(int x : res3) cout << x << " ";
    cout << "\n";  // Expected: 10 10 6 5 2

    // Test case 4
    vector<int> arr4 = {5, 4, 3, 2, 1};
    vector<int> res4 = sol.leaders(arr4);
    cout << "Leaders in arr4: ";
    for(int x : res4) cout << x << " ";
    cout << "\n";  // Expected: 5 4 3 2 1 (since it's decreasing)

    // Test case 5 (single element)
    vector<int> arr5 = {42};
    vector<int> res5 = sol.leaders(arr5);
    cout << "Leaders in arr5: ";
    for(int x : res5) cout << x << " ";
    cout << "\n";  // Expected: 42

    return 0;
}
