#include<bits/stdc++.h>
using namespace std;

string Solve(int n, vector<int> vec) {
    if(vec[0]==1) return "YES";
    else return "NO";
}

int main() {
    int t;
    cin >> t;

    while(t--) { 
        int n;
        cin >> n;
        vector<int> vec(n);
        for(int i=0; i<n; i++) {
            cin >> vec[i];
        }
        cout << Solve(n, vec) << endl;
    }
    return 0;
}
