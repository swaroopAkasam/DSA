#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int TankVolume(int n, int end, vector<int> vec) {
        int ans = vec[0];
        for(int i=1; i<n; i++) {
            ans = max(ans, vec[i]-vec[i-1]);
        }
        ans = max(ans, 2*(end-vec[n-1]));
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;

        vector<int> vec(n);
        for(int i=0; i<n; i++) {
            cin >> vec[i];
        }

        Solution sol;
        cout << sol.TankVolume(n, x, vec) << endl;
    }
    return 0;
}