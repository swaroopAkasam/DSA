/*
31. Next Permutation
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printVector(vector<int>& arr) {
        for(const int ele: arr) {
            cout << ele << " ";
        }
        cout << endl;
    }

    void printPermutations(vector<int>& arr, unordered_map<int, bool>& um, vector<int>& temp) {
        if(temp.size() == arr.size()) {
            printVector(temp);
        }   
        for(int i=0; i<arr.size(); i++) {
            if(!um[i]) {
                temp.push_back(arr[i]);
                um[i] = true;
                printPermutations(arr, um, temp);
                temp.pop_back();
                um[i] = false;
            }
        }
    }
    /*
    T.C : n! * n
    S.C : O(n) + O(n)
    */

    void printPermutationsUsingSwap(vector<int>& arr, int ind) {
        if(ind >= arr.size()) {
            printVector(arr);
        }
        for(int i = ind; i<arr.size(); i++) {
            swap(arr[i], arr[ind]);
            printPermutationsUsingSwap(arr, ind+1);
            swap(arr[i], arr[ind]);
        }
    }
    /*
    T.C : n! * n
    S.C : No extra space except the space for the recursion stack
    */

    void printNextPermutationSTL(vector<int>& arr) {
        next_permutation(arr.begin(), arr.end());
        printVector(arr);
    }
    /*
    T.C : O(n)
    */

    void printNextPermutation(vector<int>& arr) {
        int index = -1;
        int n = arr.size();
        for(int i=n-2; i>=0; i--) {
            if(arr[i] < arr[i+1]) {
                index = i;
                break;
            }
        }

        if(index == -1) {
            reverse(arr.begin(), arr.end());
            printVector(arr);
            return;
        }

        for(int i=n-1; i>index; i--) {
            if(arr[i] > arr[index]) {
                swap(arr[i], arr[index]);
                break;
            }
        }

        reverse(arr.begin()+index+1, arr.end());
        printVector(arr);
        return;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3};
    vector<int> temp;
    unordered_map<int, bool> um;
    // sol.printPermutations(arr, um, temp);
    // sol.printPermutationsUsingSwap(arr, 0);
    sol.printNextPermutationSTL(arr);
    arr = {1, 2, 3};
    sol.printNextPermutation(arr);
    return 0;
}