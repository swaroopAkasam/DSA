
/*
Repeated sum of digits (Digital Root of a number)
Given an integer N, recursively sum digits of N until we get a single digit.  The process can be described below
Difficulty: Basic
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int summation(int n) {
        int sum = 0; 
        while(n) {
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
    int repeatedSumOfDigits(int N) {
        if(N<10) return N;
        N = summation(N);
        return repeatedSumOfDigits(N);
    }
};


/*
// O(1) solution
class Solution {
public:
    int repeatedSum(int n) {
        if (n == 0) return 0;
        return 1 + (n - 1) % 9;
    }
};

/*
We want to understand why this magic formula works: 
digitalRoot(n)=1+(n−1)%9(n>0)

1. What is "digital root"?
Digital root = keep adding digits until one digit remains.
Example:
n = 9875
→ 9+8+7+5 = 29
→ 2+9 = 11
→ 1+1 = 2

So the digital root of 9875 is 2.

2. Notice the pattern (relation to 9)
Try dividing numbers by 9:
9 → digital root = 9
10 → 1+0 = 1
11 → 1+1 = 2
12 → 1+2 = 3
…
18 → 1+8 = 9
19 → 1+9 = 10 → 1+0 = 1

See the pattern?
The digital root is basically the remainder when dividing by 9, but with a twist:
if remainder is 0 (like 9, 18, 27), the digital root is 9, not 0.

3. Normal way: n % 9
Let’s check n % 9:
10 % 9 = 1 → digital root = 1 
11 % 9 = 2 → digital root = 2 
18 % 9 = 0 → but digital root = 9 
So we see the problem: n % 9 works except for multiples of 9.

4. Fix for multiples of 9
We want:
n % 9 = 0 → digital root = 9
Trick: use 1 + (n - 1) % 9 instead.
Why?
If n = 18:
(n - 1) % 9 = 17 % 9 = 8
1 + 8 = 9 
If n = 10:
(n - 1) % 9 = 9 % 9 = 0
1 + 0 = 1 
So this fixes the problem perfectly.

5. Special case n = 0
By definition, digital root of 0 is 0 (not 9).
So we just handle that separately.

Final Takeaway
The formula works because:
Digital root = "remainder when divided by 9",
Except multiples of 9 should give 9, not 0,
1 + (n-1) % 9 adjusts it correctly.
*/

int main() {
    Solution sol;
    int n = 999;
    cout << sol.repeatedSumOfDigits(n) << endl;

    return 0;
}