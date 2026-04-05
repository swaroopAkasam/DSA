#include<bits/stdc++.h>
using namespace std;

bool checkRound(int ele) {
    int count_zero = 0;
    int count_digits = 0;
    while(ele) {
        if(ele%10==0) count_zero++;
        count_digits++;
        ele /= 10;
    }

    return count_zero == count_digits-1;
}

int main() {
    int t;
    cin >> t;

    vector<int> round_nums;
    for(int i=1; i<=999999; i++) {
        if(checkRound(i)) round_nums.push_back(i);
    }

    while(t--) {
        int n; 
        cin >> n;
        int ans = 0;
        for(auto ele: round_nums) {
            if(ele <= n) ans++;
            else break;
        }

        cout << ans << endl;
    }
    return 0;
}