#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int minimumDeletions(string word, int k) {
//         map<char, int> mp;
//         for(char ele: word) {
//             mp[ele]++;
//         }
//         int smallest_freq = INT_MAX;
//         for(auto ele: mp) {
//             smallest_freq = min(smallest_freq, ele.second);
//         }        
            
//         return 0;
//     }
// };


class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int dupk = k;
        string temp = "";
        vector<string> ans;
        for(char ele: s) {
            temp += ele;
            dupk--;
            if(!duipk) {
                temp = "";
                ans.push_back(temp);    
            }
        }
        for(auto ele: ans) {
            cout << ele << "";
        }
    }
};

int main() {
    Solution sol;
    // string word = "aabcaba";
    string word = "abcdefghi";
    int k = 0;
    // sol.minimumDeletions(word, k);
    char fill = 'x';
    sol.divideString(word, k, fill);
    cout << endl;
    return 0;
}