#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }

        int flag = 0;
        for(int i=0; i<n; i++) {
            for(int j= i+1; j<n; j++) {
                if(__gcd(a[i], a[j]) <= 2) {
                    flag = 1;
                    break;
                }
                if(flag==1) break;
            }
        }
        if(flag == 0) cout << "No" << endl;
        else cout << "Yes" << endl;
    }

    return 0;
}