#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Define the Tree Node structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to create a complete binary tree from array
TreeNode* buildCompleteBinaryTree(const vector<int>& arr) {
    if (arr.empty()) return nullptr;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (i < arr.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // Add left child
        if (i < arr.size()) {
            curr->left = new TreeNode(arr[i++]);
            q.push(curr->left);
        }

        // Add right child
        if (i < arr.size()) {
            curr->right = new TreeNode(arr[i++]);
            q.push(curr->right);
        }
    }

    return root;
}

// Utility to print the tree in level-order (for verification)
void printLevelOrder(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* curr = q.front(); q.pop();
        cout << curr->val << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    cout << endl;
}

vector<int> getInorderTravMorris(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;
    TreeNode* curr = root;
    while(curr) {
        
    } 
}

int main() {
    vector<int> nodes = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* root = buildCompleteBinaryTree(nodes);

    cout << "Level-order traversal of the complete binary tree:\n";
    printLevelOrder(root);
    return 0;
}
