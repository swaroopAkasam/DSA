// Problem Stmnt
// 1365. How Many Numbers Are Smaller Than the Current Number
// Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

// Return the answer in an array.
// Input: nums = [8,1,2,2,3]
// Output: [4,0,1,1,3]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> um;
        for(int i=0; i<sorted.size(); i++) {
            if(um.find(sorted[i]) == um.end()) {
                um[sorted[i]] = i;
            }
        }
        vector<int> ans;
        for(int ele: nums) {
            ans.push_back(um[ele]); 
        }
        return ans;
    }

    vector<int> smallerNumsUsingCountSort(vector<int>& nums) {
        vector<int> count(101,0);

        for(int ele: nums) {
            count[ele]++;
        }

        for(int i=1; i<101; i++) {
            count[i] += count[i-1];
        }

        vector<int> ans;
        for(int ele: nums) {
            ans.push_back(ele==0 ? 0 : count[ele-1]);
        }
        return ans;
    }
};

void printVector(vector<int>& v) {
    for(auto ele: v){
        cout << ele << " ";
    }
    cout << endl;
}

int main() {
    Solution sol;
    vector<int>nums = {8,1,2,2,3};
    vector<int> ans = sol.smallerNumbersThanCurrent(nums);
    printVector(ans);
    ans = sol.smallerNumsUsingCountSort(nums);
    printVector(ans);;
    return 0;
}

// Approach	Time Complexity	Space	Use When...
// Sorting + Hash Map	O(n log n)	O(n)	General input (no bounds)
// Counting Sort (Optimal)	O(n)	O(1)	Input is bounded (0 ≤ nums[i] ≤ 100)
