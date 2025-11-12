/*
Longest Subarray with sum K | [Postives]

Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.

*/

#include <bits/stdc++.h>
using namespace std;

// the hashmap solution anyways works, but since the array contains only positive numbers we can take advantage of that to build two pointer solution
class SolutionHashMap {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> um;
        um[0] = -1;
        int sum = 0;
        int maxi = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            int remain = sum - k;

            if (um.find(remain) != um.end()) {
                maxi = max(maxi, i - um[remain]);
            }

            if (um.find(sum) == um.end()) {
                um[sum] = i;
            }
        }
        return maxi;
    }
};

/*
Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
Reason: For example, if we are using an unordered_map data structure in C++ the time complexity will be O(N)(though in the worst case, unordered_map takes O(N) to find an element and the time complexity becomes O(N2)) but if we are using a map data structure, the time complexity will be O(N*logN). The least complexity will be O(N) as we are using a loop to traverse the array.

Space Complexity: O(N) as we are using a map data structure.
*/


// Optimal Approach (Using 2 pointers): 
class SolutionTwoPointer {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        int left = 0, right = 0;
        int sum = 0;
        int maxi = 0;

        while (right < n) {
            sum += arr[right];  // expand window

            // shrink window until sum <= k
            while (left <= right && sum > k) {
                sum -= arr[left];
                left++;
            }

            if (sum == k) {
                maxi = max(maxi, right - left + 1);
            }

            right++;
        }

        return maxi;
    }
};


int main() {
    SolutionTwoPointer sol;

    vector<pair<vector<int>, int>> tests = {
        {{1, 2, 3, 1, 1, 1, 1, 4, 2, 3}, 3},  // expected 2 ([1,2])
        {{1, 2, 3, 7, 5}, 12},                // expected 2 ([7,5])
        {{2, 3, 5, 1, 9}, 10},                // expected 3 ([2,3,5])
        {{1, 2, 3}, 3},                       // expected 2 ([1,2])
        {{1, 1, 1, 1, 1}, 3},                 // expected 3 ([1,1,1])
        {{10, 5, 2, 7, 1, 9}, 15},            // expected 4 ([5,2,7,1])
        {{5, 5, 5, 5}, 5},                    // expected 1 ([5])
        {{1, 2, 3, 4, 5}, 15},                // expected 5 (whole array)
        {{1, 2, 3, 4, 5}, 11},                // expected 3 ([3,4,4] impossible → actually [5,6] none) → [5,6]? Let's fix below
        {{1, 2, 3, 4, 5}, 9},                 // expected 2 ([4,5])
        {{1, 2, 3}, 10}                       // expected 0 (no subarray)
    };

    for (int i = 0; i < tests.size(); i++) {
        auto arr = tests[i].first;
        int k = tests[i].second;
        int result = sol.longestSubarray(arr, k);

        cout << "Test " << i + 1 << ": k = " << k << ", arr = [ ";
        for (int x : arr) cout << x << " ";
        cout << "] -> Longest length = " << result << endl;
    }

    return 0;
}
