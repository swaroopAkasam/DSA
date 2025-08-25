/*
Third largest element
Given an array, arr of positive integers. Find the third largest element in it. Return -1 if the third largest element is not found.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int thirdLargest(vector<int> &arr) {
        int n = arr.size();
        if(n<3) return -1;
        
        int first = 0, sec = -1, third = -1;
        
        for(int i=0; i<n; i++) {
            if(arr[first] < arr[i]) first = i;
        }
        for(int i=0; i<n; i++) {
            if(i==first) continue;
            if (sec == -1 || (arr[i] <= arr[first] && arr[i] > arr[sec])) {
                sec = i;
            }
        }
        
        if (sec == -1) return -1; // no second found
        
        for(int i=0; i<n; i++) {
            if (i == first || i == sec) continue;
            if (third == -1 || (arr[i] <= arr[sec] && arr[i] > arr[third])) {
                third = i;
            }
        }
        return third==-1 ? -1 : arr[third];
    }
};


// *****One pass solution****
class Solution2 {
  public:
    int thirdLargest(vector<int> &arr) {
        int n = arr.size();
        int first = INT_MIN, sec = INT_MIN, third = INT_MIN;
        for(auto ele: arr) {
            if(ele > first) {
                third = sec;{}
                sec = first;
                first = ele;
            }
            else if(ele > sec) {
                third = sec;
                sec = ele;
            }
            else if(ele > third) {
                third = ele;
            }
        }
        return third==INT_MIN ? -1 : third;
    }
};

// We want the third distinct maximum in the array. Leetcode 414. Third Maximum Number
class Solution3 {
public:
    int thirdDistinctMax(vector<int>& arr) {
        int n = arr.size();
        long first = LONG_MIN, sec = LONG_MIN, third = LONG_MIN;
        for(auto ele: arr) {
            if(ele==first || ele==sec || ele==third) continue;
            if(ele > first) {
                third = sec;{}
                sec = first;
                first = ele;
            }
            else if(ele > sec) {
                third = sec;
                sec = ele;
            }   
            else if(ele > third) {
                third = ele;
            }
        }
        return (third == LONG_MIN) ? (int)first : (int)third;
    
    }
};

int main() {
    Solution2 sol;

    vector<vector<int>> testCases = {
        {1, 2, 3},                                  // simple increasing
        {5, 5, 5, 5},                              // all same
        {10, 20},                                  // only 2 elements
        {855, 450, 132, 359, 233, 825, 604, 481, 262, 337, 720, 525, 652, 300, 906, 219, 926, 906, 293, 864, 817, 498, 30, 639, 661}, // large case
        {9, 8, 7, 6, 5},                           // descending
        {4, 4, 6, 6, 6, 8, 8},                     // duplicates mixed
        {42}                                       // single element
    };

    for(auto &tc : testCases) {
        cout << "Input: ";
        for(int x : tc) cout << x << " ";
        cout << "\nOutput: " << sol.thirdLargest(tc) << "\n\n";
    }

    return 0;
}