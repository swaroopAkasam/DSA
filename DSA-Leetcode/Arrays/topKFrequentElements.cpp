/*
347. Top K Frequent Elements
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
*/

#include <bits/stdc++.h>
using namespace std;

// 1. Sorting
vector<int> topKFrequentSorting(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for(int num: nums) freq[num]++;

    vector<pair<int, int>> arr;
    for(const auto& ele: freq) arr.push_back({ele.second, ele.first});

    sort(arr.rbegin(), arr.rend());

    vector<int> ans;
    for(int i=0; i<k; i++) {
        ans.push_back(arr[i].second);
    }

    return ans;
}
/*
Time & Space Complexity
Time complexity: O(nlogn)
Space complexity: O(n)
*/

// 2. Min-Heap
vector<int> topKFrequentMinHeap(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int x : nums) freq[x]++;

    // min heap by frequency
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    for (auto& [num, count] : freq) {
        pq.push({count, num});
        if (pq.size() > k)
            pq.pop();
    }

    vector<int> result;
    while (!pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }
    return result;
}

/*
Time & Space Complexity
Time complexity: O(nlogk)
Space complexity: O(n+k)
*/

// 3. Bucket Sort
vector<int> topKFrequentBucketSort(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    vector<vector<int>> freq(nums.size() + 1);

    for (int n : nums) {
        count[n] = 1 + count[n];
    }
    for (const auto& entry : count) {
        freq[entry.second].push_back(entry.first);
    }

    vector<int> res;
    for (int i = freq.size() - 1; i > 0; --i) {
        for (int n : freq[i]) {
            res.push_back(n);
            k--;
            if (k==0) {
                return res;
            }
        }
    }
    return res;
}

void runTest(vector<int> nums, int k) {
    vector<int> res = topKFrequent(nums, k);
    cout << "Input: ";
    for (int x : nums) cout << x << " ";
    cout << "\nK = " << k << "\nOutput: ";
    for (int x : res) cout << x << " ";
    cout << "\n---------------------\n";
}

int main() {
    runTest({1,1,1,2,2,3}, 2);          // expected: 1,2
    runTest({1}, 1);                    // expected: 1
    runTest({4,4,4,6,6,7}, 1);          // expected: 4
    runTest({1,2,3,4,5}, 3);            // any 3 elements
    runTest({5,5,5,5,6,6,7,7,7}, 2);    // expected: 5,7

    return 0;
}
