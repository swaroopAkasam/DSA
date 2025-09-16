/*
GFG
Majority Element
Difficulty: Medium
Given an array arr[]. Find the majority element in the array. If no majority element exists, return -1.

Note: A majority element in an array is an element that appears strictly more than arr.size()/2 times in the array.

Leetcode
169. Majority Element
Difficulty: Easy
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/

#include <bits/stdc++.h>
using namespace std;

int majorityElementGFG(int arr[], int n) {
    int mc = 1;
    int me = arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i]==me) {
            mc++;
        } else {
            mc--;
        }
        if(mc==0) {
            me = arr[i];
            mc = 1;
        }
    }
    int count = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] == me) count++;
    }
    return count > n/2 ? me : -1;
}

int majorityElementLeet(int arr[], int n) {
    int mc = 1;
    int me = nums[0];
    int n = nums.size();
    for(int i=1; i<n; i++) {
        if(me==nums[i]) {
            mc++;
        }
        else {
            mc--;
        }
        if(mc==0) {
            me = nums[i];
            mc++;
        }
    }
    return me;
}

int main() {
    // Test Case 1: Majority element exists
    int arr1[] = {2, 2, 1, 1, 2, 2, 2};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    cout << "Test 1: " << majorityElementGFG(arr1, n1) << endl; // Expected 2
    // cout << "Test 1: " << majorityElementLeet(arr1, n1) << endl; // Expected 2

    // Test Case 2: No majority element
    int arr2[] = {1, 2, 3, 4};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    cout << "Test 2: " << majorityElementGFG(arr2, n2) << endl; // Expected -1

    // Test Case 3: Single element array
    int arr3[] = {5};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    cout << "Test 3: " << majorityElementGFG(arr3, n3) << endl; // Expected 5
    // cout << "Test 3: " << majorityElementLeet(arr3, n3) << endl; // Expected 5

    // Test Case 4: All elements same
    int arr4[] = {7, 7, 7, 7, 7};
    int n4 = sizeof(arr4)/sizeof(arr4[0]);
    cout << "Test 4: " << majorityElementGFG(arr4, n4) << endl; // Expected 7
    // cout << "Test 4: " << majorityElementLeet(arr4, n4) << endl; // Expected 7

    // Test Case 5: Even length array with majority
    int arr5[] = {3, 3, 4, 3, 3, 5};
    int n5 = sizeof(arr5)/sizeof(arr5[0]);
    cout << "Test 5: " << majorityElementGFG(arr5, n5) << endl; // Expected 3
    // cout << "Test 5: " << majorityElementLeet(arr5, n5) << endl; // Expected 3

    // Test Case 6: Even length array without majority
    int arr6[] = {1, 1, 2, 2};
    int n6 = sizeof(arr6)/sizeof(arr6[0]);
    cout << "Test 6: " << majorityElementGFG(arr6, n6) << endl; // Expected -1
    // cout << "Test 6: " << majorityElementLeet(arr6, n6) << endl; // Expected -1

    return 0;
}
