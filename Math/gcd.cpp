#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        while(b!=0) {
            int temp = b;
            b = a%b;
            a = temp;
        }
        return a;
    }

    int gcdOfArray(const vector<int>& arr) {
        int result = arr[0];
        for(int i=1; i<arr.size(); i++) {
            result = this->gcd(result, arr[i]);
            if(result==1) return result;
        }
        return result;
    }
};

int main() {
    Solution sol;

    int a = 18, b = 48;
    cout << "GCD of " << a << " and " << b << " is: " << sol.gcd(a, b) << endl;

    vector<int> nums = {48, 18, 30};
    cout << "Array elements: ";
    for(auto ele: nums) cout << ele << " ";
    cout << endl << "GCD of Array is : " << sol.gcdOfArray(nums) << endl;

    return 0;
}