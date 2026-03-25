#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        
        long long mini = INT_MAX;
        for(int i=0; i<n-1; i++) {
            if(a[i] <= a[i+1]) {
                long long diff = a[i+1] - a[i];
                long long required_ops = diff/2 + 1;
                mini = min(mini, required_ops);
            }
            else {
                mini = 0;
                break;
            }
        }
        cout << mini << endl;
    }
    return 0;
}
