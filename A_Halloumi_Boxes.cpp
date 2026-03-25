#include <bits/stdc++.h>
using namespace std;


string Solve(int n, int k, vector<long long> vec) {
    if(k>1) return "YES";
    
    for(int i=1; i<n; i++) {
        if(vec[i]<vec[i-1]) return "NO";
    }
    return "YES";
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        cout << Solve(n, k, a) << endl;
        // ---- Write your logic here ----



        // ---- Print result ----
        // Example:
        // cout << "YES\n";
        // or
        // cout << "NO\n";
    }

    return 0;
}