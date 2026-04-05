#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];

        int total_xor = 0;
        for(auto ele: a) total_xor ^= ele;

        if(n&1) {
            cout << total_xor << endl;
        }else {
            if(total_xor == 0) cout << total_xor << endl;
            else cout << -1 << endl;    
        }
    }
    return 0;
}