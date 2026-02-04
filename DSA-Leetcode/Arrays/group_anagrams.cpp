#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um; 
        for (auto& str : strs) {
            string str_sorted = str;
            sort(str_sorted.begin(), str_sorted.end());
            um[str_sorted].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto& pair : um) {
            ans.push_back(pair.second);
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for (const auto& s : strs) {
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i < 26; ++i) {
                key += ',' + to_string(count[i]);
                /*
                why appending ',' necessary?
                count = [1,2,0,0,...]
                key = "120000..."
                count = [12,0,0,0,...]
                key = "120000..."
                */
            }
            res[key].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto& pair : res) {
            result.push_back(pair.second);
        }
        return result;
    }
};

void printResult(const vector<vector<string>>& res) {
    cout << "[\n";
    for (const auto& group : res) {
        cout << "  [ ";
        for (const auto& s : group) {
            cout << "\"" << s << "\" ";
        }
        cout << "]\n";
    }
    cout << "]\n";
}

int main() {
    Solution sol;

    // Test case 1
    vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto res1 = sol.groupAnagrams(strs1);
    cout << "Test case 1:\n";
    printResult(res1);

    // Test case 2
    vector<string> strs2 = {""};
    auto res2 = sol.groupAnagrams(strs2);
    cout << "\nTest case 2:\n";
    printResult(res2);

    // Test case 3
    vector<string> strs3 = {"a"};
    auto res3 = sol.groupAnagrams(strs3);
    cout << "\nTest case 3:\n";
    printResult(res3);

    // Test case 4
    vector<string> strs4 = {"abc", "bca", "cab", "xyz", "zyx", "yxz"};
    auto res4 = sol.groupAnagrams(strs4);
    cout << "\nTest case 4:\n";
    printResult(res4);

    return 0;
}
