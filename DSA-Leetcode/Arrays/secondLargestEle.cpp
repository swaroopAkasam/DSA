/*
Second Largest
Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

Note: The second largest element should not be equal to the largest element.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        int first = INT_MIN, second = INT_MIN;
        for(auto ele: arr) {
            first = max(first, ele);
        }
        for(auto ele: arr) {
            if(ele==first) continue;
            second = max(second, ele);   
        }
        return second==INT_MIN ? -1 : second;
    }
};


class Solution2 {
  public:
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        if (n < 2) return INT_MIN; // or some sentinel

        int first = INT_MIN, sec = INT_MIN;

        for (int ele : arr) {
            if (ele > first) {
                sec = first;
                first = ele;
            }
            else if (ele > sec && ele != first) {
                sec = ele;
            }
        }
        return (sec == INT_MIN ? -1 : sec); // -1 if no second largest exists
    }
};

int main() {
    Solution sol;

    vector<int> arr1 = {10, 20, 30, 40};
    cout << sol.getSecondLargest(arr1) << endl; // Expected: 30

    vector<int> arr2 = {5, 5, 5, 5};
    cout << sol.getSecondLargest(arr2) << endl; // Expected: -1 (no valid second largest)

    vector<int> arr3 = {1, 2};
    cout << sol.getSecondLargest(arr3) << endl; // Expected: 1

    vector<int> arr4 = {9};
    cout << sol.getSecondLargest(arr4) << endl; // Expected: -1 (not enough elements)

    return 0;
}
