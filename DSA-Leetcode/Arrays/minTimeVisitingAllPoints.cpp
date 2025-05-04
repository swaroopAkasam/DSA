/*
1266. Minimum Time Visiting All Points
On a 2D plane, there are n points with integer coordinates points[i] = [xi, yi]. Return the minimum time in seconds to visit all the points in the order given by points.

You can move according to these rules:

In 1 second, you can either:
move vertically by one unit,
move horizontally by one unit, or
move diagonally sqrt(2) units (in other words, move one unit vertically then one unit horizontally in 1 second).
You have to visit the points in the same order as they appear in the array.
You are allowed to pass through points that appear later in the order, but these do not count as visits.
Input: points = [[1,1],[3,4],[-1,0]]
Output: 7
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i=1; i<points.size(); i++) {
            int dx = abs(points[i][0] - points[i-1][0]);
            int dy = abs(points[i][1] - points[i-1][1]);
            ans += max(dx, dy);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> points = {{1,1},{3,4},{-1,0}};
    int ans = sol.minTimeToVisitAllPoints(points);
    cout << "Minimum Time : " << ans << endl;
    return 0;
}

/*
Explanation:
The robot can move one unit per second in any of these directions:

Up: (x, y+1)

Down: (x, y-1)

Right: (x+1, y)

Left: (x-1, y)

Diagonally: (x±1, y±1)

So in one move, the robot can change:

Only x (horizontal)

Only y (vertical)

Both x and y at the same time (diagonal)
Let's Visualize With an Example
Suppose you want to move from (1, 1) to (4, 3).

Δx=∣4−1∣=3
Δy=∣3−1∣=2

🧭 Strategy: Use Diagonal Moves First
Diagonal moves change both x and y together.

So:

You can take 2 diagonal steps, each of which moves you from (1,1) → (2,2) → (3,3)

After that, you’re at (3,3), but you still need to reach (4,3)

🚶 Remaining Move:
Just 1 step to the right → (3,3) → (4,3)

⏱️ Total time:
2 diagonal steps + 1 horizontal step = 3 seconds

Which is max(dx, dy) = max(3, 2) = 3

General Rule
You can always take min(dx, dy) diagonal steps.

After that:

You’re aligned along either the same x or y

You need |dx - dy| additional straight steps

So total time is:
min(dx,dy)+∣dx−dy∣=max(dx,dy)
*/