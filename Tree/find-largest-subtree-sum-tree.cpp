#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

int findLargestSubtreeSumRecursion(Node* root, int& sum) {
    // Using Recursion – O(n) Time and O(h) Space
    // The idea is to do post order traversal of the binary tree. At every node, find left subtree value and right subtree value recursively. 
    // The value of subtree rooted at current node is equal to sum of current node value, left node subtree sum and right node subtree sum. 
    // Compare current subtree sum with overall maximum subtree sum so far.
    if(!root) return 0;
    int left = findLargestSubtreeSumRecursion(root->left, sum);
    int right = findLargestSubtreeSumRecursion(root->right, sum);
    int curr_sum = root->data + left + right;
    sum = max(curr_sum, sum);
    return curr_sum;
}
int findLargestSubtreeSumBFS(Node* root) {
    // The idea is to use breadth first search to store nodes (level wise) at each level in some container and then traverse these levels in reverse order from bottom level to top level and keep storing the subtree sum value rooted at nodes at each level. 
    // We can then reuse these values for upper levels. Subtree sum rooted at node = value of node + (subtree sum rooted at node->left) + (subtree sum rooted at node->right)
    if(!root) return 0;
    int ans = INT_MIN;
    queue<Node*> q;
    vector<vector<Node*>> levels;
    unordered_map<Node*, int> subtreeSum;
    
    q.push(root);
    while(!q.empty()) {
        int q_size = q.size();
        vector<Node*> currLevel;
        while(q_size--) {
            Node* node = q.front();
            q.pop();
            currLevel.push_back(node);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        levels.push_back(currLevel);
    }

    for(int i=levels.size()-1; i>=0; i--) {
        for(auto node: levels[i]) {
            subtreeSum[node] = node->data;
            if(node->left) {
                subtreeSum[node] += subtreeSum[node->left];
            }
            if(node->right) {
                subtreeSum[node] += subtreeSum[node->right];
            }
            ans = max(ans, subtreeSum[node]);
        }
    }
    return ans;
}

pair<int, int> findLargestSubtreeSum(Node* root) {
    int sum = 0;
    findLargestSubtreeSumRecursion(root, sum);
    int ans_bfs = findLargestSubtreeSumBFS(root);
    return {sum, ans_bfs};
}

int main() {
  
    // Representation of the given tree
    //          1
    //        /   \
    //      -2     3
    //      / \   / \
    //     4   5 -6  2
    Node* root = new Node(1);
    root->left = new Node(-2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(-6);
    root->right->right = new Node(2);

    pair<int, int> ans = findLargestSubtreeSum(root);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}