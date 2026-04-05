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

        int twos_counter = 0;
        int current_twos_counter = 0;
        int ans = -1;

        for(auto ele: a) {
            if(ele==2) twos_counter += 1;
        }

        for(int i=0; i<n ; i++) {
            int ele = a[i];
            if(ele == 2) current_twos_counter ++;
            if(current_twos_counter == twos_counter - current_twos_counter) {
                ans = i+1;
                break;
            }
        }

        cout << ans << endl;
    }
    return 0;
}