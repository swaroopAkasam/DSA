
/*
66. Plus One
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

Difficulty: Easy
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1; i>=0; i--) {
            if(digits[i]!=9) {
                digits[i]++;
                return digits;
            }
            else {
                digits[i] = 0;
            }
        }
        digits.push_back(0);
        digits[0] = 1;
        return digits;
    }
};

/*
// Recursive Solution
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        return helper(digits, digits.size()-1);
    }

    vector<int> helper(vector<int> digits, int idx) {
        if (idx < 0) {
            digits.insert(digits.begin(), 1); // all 9’s case
            return digits;
        }
        if (digits[idx] < 9) {
            digits[idx]++; 
            return digits;
        }
        digits[idx] = 0;
        return helper(digits, idx-1);
    }
};
*/

/*
// Using Reverse Traversal with Carry Variable
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;  // we want to add 1
        for (int i = digits.size()-1; i >= 0 && carry; i--) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        if (carry) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
*/

/*
// Convert to Number (Not Practical for Large Inputs)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        long long num = 0;
        for (int d : digits) {
            num = num * 10 + d;
        }
        num += 1;
        
        vector<int> result;
        string s = to_string(num);
        for (char c : s) result.push_back(c - '0');
        return result;
    }
};

*/

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {1,2,3},       // simple increment
        {9},           // single 9
        {9,9,9},       // carry propagates fully
        {4,3,2,1},     // normal case
        {0},           // edge case
        {8,9,9,9},     // multiple carries
        {2,9,8,9}      // mixed carries
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test case " << i+1 << ": ";
        for (int d : testCases[i]) cout << d << " ";
        cout << "\nAfter plusOne: ";
        vector<int> result = sol.plusOne(testCases[i]);
        for (int d : result) cout << d << " ";
        cout << "\n\n";
    }

    return 0;
}
