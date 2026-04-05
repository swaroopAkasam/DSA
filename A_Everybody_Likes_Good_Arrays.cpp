#include<bits/stdc++.h>
using namespace std;

bool sameParity(int a, int b) {
    if(((a&1) && (b&1)) || (!(a&1) && !(b&1))) return true;
    return false;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i=0; i<n; i++) cin >> a[i];

        int ops = 0;
        for(int i=0; i<n-1; i++) {
            if(sameParity(a[i], a[i+1])) ops++;
        }
        cout << ops << endl;
    }
    return 0;
}