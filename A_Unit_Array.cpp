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

        int neg = 0;
        int pos = 0;
        for(auto ele: a) {
            if(ele == 1) pos++;
            else neg++;
        }

        int ans = 0;
        if(pos >= neg) {
            if(neg&1) ans++;
        } else {
            int diff = neg-pos;
            int min = (diff+1)/2;
            if(abs(min-neg)%2==1) ans=min+1;
            else ans=min;
        }
        cout << ans << endl;
    }
    return 0;
}

/*
Method-2 - with extra while loop
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; // Number of test cases
    cin >> t;
    while (t--)
    {
        long long n; // Length of the array
        cin >> n;
        long long a[n]; // Array to store elements
        for (long long i = 0; i < n; i++) // Loop to read array elements
            cin >> a[i];
        // Input complete

        long long positive_count = 0; // Count of +1s in the array
        long long negative_count = 0; // Count of -1s in the array
        for (long long i = 0; i < n; i++) // Loop to count +1s and -1s
        {
            if (a[i] == 1)
                positive_count++;
            else
                negative_count++;
        }

        long long operations = 0; // Number of operations needed to make the array good
        // While the sum of the array is negative or the product condition is not met
        while (positive_count < negative_count || negative_count % 2 == 1) // Loop to make array good
        {
            operations++; // Increment operations as we convert a -1 to 1
            positive_count++; // Increase count of +1s
            negative_count--; // Decrease count of -1s
        }

        cout << operations << endl; // Output the result for the current test case
    }
    return 0;
}

// Time Complexity (TC): O(n) = O(100)
// Space Complexity (SC): O(n) = O(100)
*/