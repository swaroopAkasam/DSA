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

        n++;
        for(auto ele: a) {
            cout << n-ele << " ";
        }
        cout << endl;
    }
    return 0;
}