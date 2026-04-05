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

        sort(a.begin(), a.end());
        int maxi = a[n-1];
        int mini = a[0];
        if(maxi == mini) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << maxi << " ";    
            for(int i=0; i<n-1; i++) cout << a[i] << " ";
            cout << endl;
        }

    }
    return 0;
}