/*
108. Convert Sorted Array to Binary Search Tree
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if(left>right) return NULL;
        int mid = left + (right-left)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid-1);
        root->right = helper(nums, mid+1, right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }

    TreeNode* sortedArrayToBSTiterative(vector<int>& nums) {
        struct NodeInfo {
            TreeNode* node;
            int left; int right;
        };
        queue<NodeInfo> q;
        int n = nums.size();
        int mid = n/2;
        TreeNode* root = new TreeNode(nums[mid]);
        q.push({root, 0, mid-1});
        q.push({root, mid+1, n-1});
        while(!q.empty()) {
            NodeInfo curr = q.front();
            q.pop();
            if (curr.left<=curr.right) {
                mid = curr.left + (curr.right-curr.left)/2;
                TreeNode* child = new TreeNode(nums[mid]);
                if(nums[mid]<curr.node->val) {
                    curr.node->left = child;
                }
                else {
                    curr.node->right = child;
                }
                q.push({child, curr.left, mid-1});
                q.push({child, mid+1, curr.right});
            }
        }
        return root;
    }
};

int main()
{
    vector<int> v = {-10,-3,0,5,9};
    Solution sol;
    sol.sortedArrayToBST(v);
    return 0;
}

