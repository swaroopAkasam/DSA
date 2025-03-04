#include <bits/stdc++.h>
using namespace std;



class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = right = nullptr;
    }
};

void findKSumPaths(Node* root, vector<int>& path, int k) {
    if(!root) return;
    path.push_back(root->data);

}

void printKSumPaths(Node* root, int K) {
    vector<int> path;
    findKSumPaths(root, path, K);
}

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
