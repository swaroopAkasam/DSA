
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicateWithSorting(vector<int> & nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n-1; i++) {
            if(nums[i]==nums[i+1]) {
                return true; // we found duplicate element
            }
        }
        return false;
    }

    bool containsDuplicateUsingHashMap(vector<int>& nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.count(num)) {
                return true; // duplicate found
            }
            seen.insert(num);
        }

        return false; // no duplicates
    }

};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1, 2, 3, 1};

    // Call function and print result
    bool result = sol.containsDuplicateWithSorting(nums);
    cout << (result ? "Contains duplicate" : "No duplicates") << endl;

    return 0;
}
