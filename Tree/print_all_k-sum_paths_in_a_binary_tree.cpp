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

void printPath(vector<int>& path, int j) {
    cout << "Path: ";
    for(int i=j; i<path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
}

void findKSumPaths(Node* root, vector<int>& path, int K) {
    if (!root) return;

    // Add current node to path
    path.push_back(root->data);

    // Check for K-sum paths ending at this node
    int sum = 0;
    for (int i = path.size() - 1; i >= 0; i--) {
        sum += path[i];
        if (sum == K) {
            printPath(path, i);
        }
    }

    // Recur for left and right subtrees
    findKSumPaths(root->left, path, K);
    findKSumPaths(root->right, path, K);

    // Remove the current node (Backtracking)
    path.pop_back();
}

// Wrapper function
void printKSumPaths(Node* root, int K) {
    vector<int> path;
    findKSumPaths(root, path, K);
}

// Driver Code
int main() {
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(-1);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(6);

    int K = 5;
    cout << "Paths with sum " << K << " are:\n";
    printKSumPaths(root, K);
    
    return 0;
}
