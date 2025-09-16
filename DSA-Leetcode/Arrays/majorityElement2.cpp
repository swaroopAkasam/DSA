/*
229. Majority Element II
Medium
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ele1 = -1, ele2 = -1;
        int cnt1 = 0, cnt2 = 0;

        for (auto num : nums) {
            if (num == ele1) cnt1++;
            else if (num == ele2) cnt2++;
            else if (cnt1 == 0) {
                ele1 = num;
                cnt1++;
            } else if (cnt2 == 0) {
                ele2 = num;
                cnt2++;
            } else {
                cnt1--; cnt2--;
            }
        }

        cnt1 = cnt2 = 0;
        for (auto ele : nums) {
            if (ele == ele1) cnt1++;
            if (ele == ele2) cnt2++;
        }

        vector<int> ans;
        if (cnt1 > n/3) ans.push_back(ele1);
        if (cnt2 > n/3) ans.push_back(ele2);

        if (ans.size() == 2) {
            if (ans[0] == ans[1]) {
                return vector<int>{ans[0]};
            }
            if (ans[0] > ans[1]) {
                swap(ans[0], ans[1]);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {3, 2, 3},                  // Majority element is 3
        {1, 1, 1, 3, 3, 2, 2, 2},   // Majority elements are 1 and 2
        {1},                        // Single element
        {1, 2},                     // No majority element
        {2, 2},                     // One element repeated
        {1, 2, 3, 4, 5, 6}          // No element appears > n/3
    };

    for (auto &tc : testCases) {
        vector<int> res = sol.majorityElement(tc);
        cout << "Input: ";
        for (int x : tc) cout << x << " ";
        cout << "\nOutput: ";
        for (int x : res) cout << x << " ";
        cout << "\n\n";
    }

    return 0;
}
