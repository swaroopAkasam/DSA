/*
76. Minimum Window Substring
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.
Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Difficulty: Hard
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";

        unordered_map<char, int> need, window;
        for(const char ch: t) need[ch]++;

        int need_total = need.size();
        int have = 0;
        
        int left = 0, right = 0;
        int min_len = INT_MAX;
        int start_idx = 0;

        for(; right<s.size(); right++) {
            char c = s[right];
            if(need.find(c)!= need.end()) {
                window[c]++;
                if(window[c]==need[c]) have++;
            }

            // Shrink
            while(have==need_total) {
                if(right-left+1 < min_len) {
                    min_len = right-left+1;
                    start_idx = left;
                }
                char lc = s[left];
                if(need.find(lc)!=need.end()) {
                    window[lc]--;
                    if(window[lc]<need[lc]) have--;
                }
                left++;
            }
        }        
        return min_len==INT_MAX ? "" : s.substr(start_idx, min_len);
    }
};
    
int main() {
    Solution sol;
    string s, t;

    // Testcase 1
    s = "ADOBECODEBANC"; 
    t = "ABC";
    cout << "Output: " << sol.minWindow(s, t) << endl; // Expected: "BANC"

    // Testcase 2
    s = "a"; 
    t = "a";
    cout << "Output: " << sol.minWindow(s, t) << endl; // Expected: "a"

    // Testcase 3
    s = "a"; 
    t = "aa";
    cout << "Output: " << sol.minWindow(s, t) << endl; // Expected: ""

    // Testcase 4
    s = "ab"; 
    t = "b";
    cout << "Output: " << sol.minWindow(s, t) << endl; // Expected: "b"

    return 0;
}
