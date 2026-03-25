#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){

        long long n;
        cin >> n;

        vector<long long> a(n);
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        vector<long long> b, c;

        long long maxi = a[0];
        for(auto ele: a) {
            maxi = max(maxi, ele);
        }
        for(auto ele: a) {
            if(ele!=maxi) b.push_back(ele);
            else c.push_back(maxi);
        }

        int lenb, lenc;
        lenb = b.size();
        lenc = c.size();
        if(lenb==0) cout << -1 << endl;
        else {
            cout << lenb << " " << lenc << endl;
            for(auto ele: b) {
                cout << ele << " ";
            }
            cout << endl;
            for(auto ele: c) {
                cout << ele << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
