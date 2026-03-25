#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<int> b(n), ans;
        for(int i=0; i<n; i++) {
            cin >> b[i];
        }
        ans.push_back(b[0]);
        for(int i=1; i<n; i++) {
            if(b[i]>=b[i-1]) {
                ans.push_back(b[i]);
            } else {
                ans.push_back(b[i]);
                ans.push_back(b[i]);
            }
        }
        cout << ans.size() << endl;
        for(auto ele: ans) cout << ele << " ";
        
        cout << endl;
    }
    return 0;
}
