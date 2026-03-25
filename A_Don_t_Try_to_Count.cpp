#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) { 
        int n, m;
        string x, s;
        
        cin >> n >> m;
        cin >> x >> s;

        int ans = -1;
        for(int i=0; i<=5; i++) {
            if(x.find(s) != string::npos) {
                ans = i;
                break;
            }
            x+=x;
        }
        cout << ans << endl;
    }
    return 0;
}
