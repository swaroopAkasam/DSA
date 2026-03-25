#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }

        int odd     = 0;
        for(auto ele: a) {
            if(ele&1) odd++;
        }

        if(odd&1) cout << "NO" << endl;       
        else cout << "YES" << endl;
    }

    return 0;
}