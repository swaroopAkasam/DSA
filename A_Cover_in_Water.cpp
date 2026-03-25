#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int CoverInWater(int n, vector<char> vec) {
        int ans = 0;
        int empty_cells = 0;
        for(char c: vec) {
            if(c=='.') empty_cells++;
            else{ 
                if(empty_cells > 2) {
                    return 2;
                } else {
                    ans += empty_cells;
                }
                empty_cells = 0;
            }
        }
        if(empty_cells > 2) {
            return 2;
        } else {
            ans += empty_cells;
        }        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<char> vec(n);
        for(int i=0; i<n; i++) {
            cin >> vec[i];
        }

        Solution sol;
        cout << sol.CoverInWater(n, vec) << endl;
    }
    return 0;
}