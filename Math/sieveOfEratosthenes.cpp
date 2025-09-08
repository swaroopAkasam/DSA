#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sieve(int n) {
        vector<bool> isPrime(n+1, true);
        isPrime[0] = isPrime[1] = false;
        for(int i=2; i*i<=n; i++) {
            if(isPrime[i]) {
                for(int j=i*i; j<=n; j+=i) {
                    isPrime[j] = false;
                }
            }
        }
        cout << "Prime number up to " << n << ": ";
        for(int i=2; i<=n; i++) {
            if(isPrime[i]) {
                cout << i << " ";
            }
        }
        cout << endl;
    }

    void primeFactor(int n) {
        vector<int> spf(n+1, 0);
        for(int i=2; i<=n; i++) {
            spf[i] = i;
        }
        for(int i=2; i<=n; i++) {
            if(spf[i]==i) {
                for(int j=i; j<=n; j+=i) {
                    if(spf[j]==j) {
                        spf[j] = i;
                    }
                }
            }
        }
        while(n!=1) {
            cout << spf[n] << " ";
            n = n/spf[n];
        }
        cout << endl;
    }

    void primeFactorizationNaiveMeth(int n) {
        while(n%2 == 0) {
            cout << 2 << " ";
            n /= 2;
        }

        for(int i=3; i<=sqrt(n); i+=2) {
            while(n%i == 0) {
                cout << i << " ";
                n /= i;
            }
        }

        if(n>2) cout << n;
        cout << endl;
    }
};

int main() {
    Solution sol;
    cout << "Find prime number upto : ";
    int n;
    cin >> n;
    sol.sieve(n);
    
    cout << "Find prime factors of : ";
    cin >> n;
    sol.primeFactor(n);

    cout << "Find prime factors of : ";
    cin >> n;
    sol.primeFactorizationNaiveMeth(n);
    return 0;
}