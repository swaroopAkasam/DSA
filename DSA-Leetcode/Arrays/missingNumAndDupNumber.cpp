/*
Missing And Repeating
Given an unsorted array arr[] of size n, containing elements from the range 1 to n, it is known that one number in this range is missing, and another number occurs twice in the array, find both the duplicate number and the missing number.

Difficulty: Easy
*/

#include <bits/stdc++.h>
using namespace std;


// [Approach 1] Using Visited Array - O(n) Time and O(n) Space
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        
        int n = arr.size();  
        // frequency array to count occurrences
        vector<int> freq(n + 1, 0); 
        int repeating = -1, missing = -1;
        
        // count frequency of each element
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }
        
        // identify repeating and missing elements
        for (int i = 1; i <= n; i++) {
            if (freq[i] == 0) missing = i;
            else if (freq[i] == 2) repeating = i;
        }
        
        return {repeating, missing};
    }
};

// [Approach 2] Using Array Marking - O(n) Time and O(1) Space
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        vector<int> ans(2);
        
        for(const int ele: arr) {
            int ptr = ele<0 ? ele*-1 : ele;
            if(arr[ptr-1]<0) {
                ans[0] = ptr;
            }
            if(arr[ptr-1]>0) 
                arr[ptr-1] = -1*arr[ptr-1];
        }
        
        for(int i=0; i<arr.size(); i++) {
            if(arr[i]>0) {
                ans[1] = i+1;
                break;
            }
        }
        return ans;
    }
};


// [Approach 3] Making Two Math Equations - O(n) Time and O(1) Space
/*
We start with:
S = n(n+1)/2 = sum of first n natural numbers (expected sum)
S_actual = sum(arr) = sum of elements actually present in the array
Now:
s = S - S_actual;
S_actual = S - (missing) + (repeating)
But s = S - S_actual in code.
s = x - y
where x = missing, y = repeating.

same for squares as well.

ssq = x^2 - y^2 = (x - y)(x + y)
x - y = s

x - y = s
x + y = ssq / s

x = (s + ssq/s) / 2 (missing number)
y = x - s (duplicate number)
*/
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();

        // Sum of first n natural numbers
        long long  s = (n * (n + 1)) / 2;
        // Sum of squares of first n natural numbers
        long long ssq = (n * (n + 1) * (2 * n + 1)) / 6;

        // Subtract actual values from expected sums
        for (int i = 0; i < n; i++) {
            s -= arr[i];
            ssq -= arr[i] * arr[i];
        }

        // Using the equations: missing - repeating = s
        // missing^2 - repeating^2 = ssq
        int missing = (s + ssq / s) / 2;
        int repeating = missing - s;

        return {repeating, missing};
    }
};

// Using XOR - O(n) Time and O(1) Space
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        int xor_val = 0;
        for(int i=0; i<n; i++) {
            xor_val ^= arr[i];
            xor_val ^= (i+1);
        }

        int setBitIndex = xor_val & ~(xor_val - 1);
        int x = 0, y = 0;
        for(int i=0; i<n; i++) {
            int ele = arr[i];

            if(ele & setBitIndex) x ^= ele;
            else y ^= ele;

            if((i+1) & setBitIndex) x ^= (i+1);
            else y ^= (i+1);
        }
        
        int missing, repeating;
        int x_count = 0;
        for(int i=0; i<n; i++) {
            if(arr[i]==x) x_count++;
        }

        if(x_count==0) {
            missing = x; repeating = y;
        }
        else {
            missing = y; repeating = x;
        }
        return {repeating, missing};
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3, 1, 3};
    vector<int> ans = sol.findTwoElement(arr);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}