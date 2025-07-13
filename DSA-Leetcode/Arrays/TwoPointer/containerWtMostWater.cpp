#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        int left = 0, right = n-1;
        while(left<right) {
            int area = min(height[left], height[right])*(right-left);
            ans = max(area, ans);
            if(height[left]<height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int ans = sol.maxArea(height);
    cout << ans << endl;
    return 0;
}