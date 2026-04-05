#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n, k;
        cin >> n >> k;

        if(!((n-k)&1) || !(n&1)) {
            cout << "YES" << endl;
        } else {
           cout << "NO" << endl; 
        }
    }
    return 0;
}