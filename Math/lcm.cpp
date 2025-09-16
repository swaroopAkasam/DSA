#include <bits/stdc++.h>
using namespace std;

// Function to compute GCD
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute LCM of two integers
long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;  // prevent overflow
}

// Function to compute LCM of an array of integers
long long lcmOfArray(const vector<long long>& arr) {
    long long result = arr[0];
    for (size_t i = 1; i < arr.size(); i++) {
        result = lcm(result, arr[i]);
    }
    return result;
}

int main() {
    // Example: LCM of two integers
    long long a = 12, b = 18;
    cout << "LCM of " << a << " and " << b << " is: " << lcm(a, b) << endl;

    // Example: LCM of an array
    vector<long long> arr = {4, 6, 8, 12};
    cout << "LCM of array is: " << lcmOfArray(arr) << endl;

    return 0;
}
