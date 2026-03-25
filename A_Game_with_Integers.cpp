#include<bits/stdc++.h>
using namespace std;

string Solve(int n) {
    if(n==1 || n%3) return "First";
    else return "Second";
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
         
        cout << Solve(n) << endl;
    }
    return 0;
}
