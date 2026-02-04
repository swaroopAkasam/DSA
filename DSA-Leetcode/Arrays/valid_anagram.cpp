#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 1️⃣ Array approach (only 'a' to 'z')
    bool isAnagramArray(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> count(26, 0);

        for (char c : s) count[c - 'a']++;
        for (char c : t) count[c - 'a']--;

        for (int x : count) {
            if (x != 0) return false;
        }
        return true;
    }

    // 2️⃣ Hash map approach (works for any characters)
    bool isAnagramMap(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> count;

        for (char c : s) count[c]++;
        for (char c : t) {
            if (--count[c] < 0) return false;
        }
        return true;
    }
};

// Helper function to print results
void testCase(const string& s, const string& t, Solution& sol) {
    cout << "s = \"" << s << "\", t = \"" << t << "\"\n";
    cout << "Array approach : "
         << (sol.isAnagramArray(s, t) ? "true" : "false") << "\n";
    cout << "HashMap approach: "
         << (sol.isAnagramMap(s, t) ? "true" : "false") << "\n\n";
}

int main() {
    Solution sol;

    // Test case 1: Valid anagram
    testCase("anagram", "nagaram", sol);

    // Test case 2: Not an anagram
    testCase("rat", "car", sol);

    // Test case 3: Same letters, different order
    testCase("listen", "silent", sol);

    // Test case 4: Single character
    testCase("a", "a", sol);

    // Test case 5: Repeated characters
    testCase("aacc", "ccac", sol);

    return 0;
}
