/*
2496. Maximum Value of a String in an Array
Easy
The value of an alphanumeric string can be defined as:

The numeric representation of the string in base 10, if it comprises of digits only.
The length of the string, otherwise.
Given an array strs of alphanumeric strings, return the maximum value of any string in strs.

Example 1:

Input: strs = ["alic3","bob","3","4","00000"]
Output: 5
Explanation: 
- "alic3" consists of both letters and digits, so its value is its length, i.e. 5.
- "bob" consists only of letters, so its value is also its length, i.e. 3.
- "3" consists only of digits, so its value is its numeric equivalent, i.e. 3.
- "4" also consists only of digits, so its value is 4.
- "00000" consists only of digits, so its value is 0.
Hence, the maximum value is 5, of "alic3".
Example 2:

Input: strs = ["1","01","001","0001"]
Output: 1
Explanation: 
Each string in the array has value 1. Hence, we return 1.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNumeric(const string& s) {
        for (char c : s)
            if (!isdigit(static_cast<unsigned char>(c)))
                return false;
        return !s.empty();
    }

    int maximumValue(vector<string>& strs) {
        int maxVal = 0;
        for (auto& s : strs) {
            int val;
            if (isNumeric(s))
                val = stoi(s);       // numeric string → integer value
            else
                val = s.length();    // alphanumeric → length
            maxVal = max(maxVal, val);
        }
        return maxVal;
    }

    int maximumValueMeth2(vector<string>& strs) {
        int maxi = 0;
        for(const string& s: strs) {
            int val = 0;
            for(const int&c : s) {
                if(c>=48 && c<=57) {
                    val = val*10 + (c-48);
                } else {
                    val = s.size();
                    break;
                }
            }
            maxi = max(maxi, val);
        }
        return maxi;
    }

};

int main() {
    Solution sol;

    vector<vector<string>> testCases = {
        {"alic3", "bob", "3", "4", "00000"},   // Expected: 5
        {"1", "01", "001", "0001"},            // Expected: 1
        {"abc", "1234", "ab12", "000"},        // Expected: 4
        {"000", "00", "0"},                    // Expected: 0
        {"a1b2c3", "999", "xyz"}               // Expected: 6 (length of "a1b2c3")
    };

    for (int i = 0; i < testCases.size(); ++i) {
        cout << "Test Case " << i + 1 << ": ";
        for (auto& s : testCases[i]) cout << s << " ";
        cout << "\nResult: " << sol.maximumValue(testCases[i]) << "\n\n";
        cout << "\nResult: " << sol.maximumValueMeth2(testCases[i]) << "\n\n";
    }

    return 0;
}
