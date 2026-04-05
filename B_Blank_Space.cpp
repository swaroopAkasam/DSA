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

        int ans = 0;
        int temp = 0;
        for(auto ele: a) {
            if(ele == 0) temp++;
            else {
                ans = max(ans, temp);
                temp = 0;
            }
        }
        cout << max(ans, temp) << endl;
    }
    return 0;
}