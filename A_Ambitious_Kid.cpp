#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    int ans = INT_MAX;
    for(auto ele: a) {
        if(ele == 0) {
            ans = 0;
            break;
        }
        ans = min(ans, abs(ele));
    }

    cout << ans << endl;
    return 0;
}
