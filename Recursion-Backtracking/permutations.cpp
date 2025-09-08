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

int main() {
    Solution sol;
    vector<int> v = {1, 2, 3};

    vector<vector<int>> ans; 
    vector<int> temp; 
    vector<bool> map(v.size(), 0);
    sol.permutations(v, temp, ans, map);
    printMat(ans);

    int index = 0;
    ans.clear();
    sol.permutationsWtSwap(v, ans, index);
    printMat(ans);
    return 0;
}