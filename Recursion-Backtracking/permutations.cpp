#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void permutations(vector<int> v, vector<int>& temp, vector<vector<int>>& ans, vector<bool>& map) {
        if(temp.size() == v.size()) {
            ans.push_back(temp);
            return;
        }
        for(int i=0; i<v.size(); i++) {
            if(!map[i]) {
                map[i] = 1;
                temp.push_back(v[i]);
                permutations(v, temp, ans, map);
                map[i] = 0;
                temp.pop_back();
            }
        }
    }

    void permutationsWtSwap(vector<int> v, vector<vector<int>>& ans, int index) {
        if(index>=v.size()) {
            ans.push_back(v);
            return;
        }
        for(int i=index; i<v.size(); i++) {
            swap(v[index], v[i]);
            permutationsWtSwap(v, ans, index+1);
            swap(v[index], v[i]);
        }
    }

    vector<int> nextPermutationBrute(vector<int>& arr) {
        /*
        Steps in your algorithm
        Generate all permutations via backtracking (permutationsWtSwap).
        There are n! permutations of size n.
        Each permutation requires O(n) work (copying into ans).
        So this step is O(n · n!).
        Sort all permutations.
        Number of permutations = n!.
        Sorting cost = O(n! · log(n!)).
        But each comparison between two permutations can take O(n) time (comparing vectors of size n).
        So sorting = O(n · n! · log(n!)).
        Linear search for the input permutation in the sorted list.
        O(n! · n) (since comparing two arrays costs O(n)).
        Return the next permutation = O(n).
        Final Complexity
        Time Complexity =
        O(n · n!)   +   O(n · n! · log(n!))   +   O(n · n!)
        ≈ O(n · n! · log(n!))

        Space Complexity =
        To store all permutations: O(n · n!)
        Recursion stack: O(n)
        Total = O(n · n!)
        So this brute force method is extremely expensive — works only for very small n (say n ≤ 8).
        For larger n, the optimal in-place algorithm (O(n)) is used.
        */

        vector<vector<int>> perms;
        this->permutationsWtSwap(arr, perms, 0);

        sort(perms.begin(), perms.end());

        // Step 3: Linear search for the current permutation
        for (int i = 0; i < perms.size(); i++) {
            if (perms[i] == arr) {
                // Step 4: Return next (wrap around if last)
                return perms[(i + 1) % perms.size()];
            }
        }

        // Fallback (should not happen)
        return arr;
    }

    vector<int> nextPermutationInBuilt(vector<int> arr) {
        next_permutation(arr.begin(), arr.end());
        return arr;
    }
};

void printMat(vector<vector<int>>& v) {
    int n = v.size();
    int m = v[0].size();
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printVec(vector<int>& arr) {
    for(auto ele: arr) {
        cout << ele << " ";
    }
    cout << endl;
}

int main() {
    Solution sol;
    vector<int> v = {1, 2, 3};

    vector<vector<int>> perms; 
    /*
    vector<int> temp; 
    vector<bool> map(v.size(), 0);
    sol.permutations(v, temp, perms, map);
    printMat(perms);
    */

    /*
    int index = 0;
    perms.clear();
    sol.permutationsWtSwap(v, perms, index);
    printMat(perms);
    */

    /*
    vector<int> nextPerm = sol.nextPermutationBrute(v);
    printVec(nextPerm);
    */

    vector<int> nextPerm = sol.nextPermutationInBuilt(v);
    printVec(nextPerm);

    return 0;
}