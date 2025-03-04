
// g++ -o Tree Tree.cpp
// ./Tree

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int d) {
        this->data = d;
        this->left = this->right = nullptr;
    }
};

// Function to build a tree recursively
Node* buildTree() {
    cout << "Enter node data (-1 for NULL): ";
    int data;
    cin >> data;
    
    if (data == -1) return nullptr;
    
    Node* root = new Node(data);
    cout << "Entering left subtree of " << data << endl;
    root->left = buildTree();
    
    cout << "Entering right subtree of " << data << endl;
    root->right = buildTree();
    
    return root;
}

// Function to perform level order traversal
void levelOrderTraversal(Node* root) {
    if (!root) return;
    
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* temp = q.front();
            q.pop();
            cout << temp->data << " ";
            
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        cout << endl; // Move to the next level
    }
}

// Function to build a tree from level order input
void buildTreeFromLevelOrder(Node*& root) {
    cout << "Enter root node data: ";
    int data;
    cin >> data;
    
    if (data == -1) return;
    
    root = new Node(data);
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        
        cout << "Enter left child of " << temp->data << " (-1 for NULL): ";
        int leftData;
        cin >> leftData;
        if (leftData != -1) {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right child of " << temp->data << " (-1 for NULL): ";
        int rightData;
        cin >> rightData;
        if (rightData != -1) {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}


int main() {
    Node* root = buildTree();
    levelOrderTraversal(root);
    
    // // Build the tree using level order input
    // buildTreeFromLevelOrder(root);
    
    // cout << "Level Order Traversal:" << endl;
    // levelOrderTraversal(root);
    
    return 0;
}