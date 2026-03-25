    #include<bits/stdc++.h>
    using namespace std;

    string Solve(int n, vector<int> vec) {
        int ele1 = 0; 
        int ele2 = 0;
        int cnt1 = 0; 
        int cnt2 = 0;
        for(auto ele: vec) {
            if(ele1==ele || ele1==0) {
                ele1=ele; cnt1++;
            }
            else if(ele2==ele || ele2==0) {
                ele2=ele; cnt2++;
            }
            else {
                return "No";
            }   
        }
        if((cnt1==0 || cnt2==0) || abs(cnt1-cnt2)==1 || (cnt1==cnt2)) return "Yes";
        return "No";
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
