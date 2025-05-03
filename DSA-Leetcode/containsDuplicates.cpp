// g++ -o DSA-Leetcode/containsDuplicates DSA-Leetcode/containsDuplicates.cpp
// ./DSA-Leetcode/containsDuplicates

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1, 2, 3, 4, 1};

    // Call function and print result
    bool result = sol.containsDuplicate(nums);
    cout << (result ? "Contains duplicate" : "No duplicates") << endl;

    return 0;
}
