// c++ program to construct tree using
// inorder and preorder traversals
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
  public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// Print tree as level order
void printLevelOrder(Node *root) {
    if (root == nullptr) {
        cout << "N ";
        return;
    }

    queue<Node *> qq;
    qq.push(root);
    int nonNull = 1;

    while (!qq.empty() && nonNull > 0) {
        Node *curr = qq.front();
        qq.pop();

        if (curr == nullptr) {
            cout << "N ";
            continue;
        }
        nonNull--;

        cout << (curr->data) << " ";
        qq.push(curr->left);
        qq.push(curr->right);
        if (curr->left)
            nonNull++;
        if (curr->right)
            nonNull++;
    }
}

// Function to find the index of an element in the array.
int search(vector<int> &inorder, int value, int left, int right) {

    for (int i = left; i <= right; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Recursive function to build the binary tree.
Node *buildTreeRecur(vector<int> &inorder, vector<int> &preorder, 
                         int &preIndex, int left, int right) {

    // For empty inorder array, return null
    if (left > right)
        return nullptr;

    int rootVal = preorder[preIndex];
    preIndex++;

    // create the root Node
    Node *root = new Node(rootVal);

    // find the index of Root element in the in-order array.
    int index = search(inorder, rootVal, left, right);

    // Recursively create the left and right subtree.
    root->left = buildTreeRecur(inorder, preorder, preIndex, left, index - 1);
    root->right = buildTreeRecur(inorder, preorder, preIndex, index + 1, right);

    return root;
}

// Function to construct tree from its inorder and preorder traversals
Node *buildTree(vector<int> &inorder, vector<int> &preorder) {

    int preIndex = 0;
    Node *root = buildTreeRecur(inorder, preorder, preIndex, 0, preorder.size() - 1);

    return root;
}

int main() {
    vector<int> inorder = {3, 1, 4, 0, 5, 2};
    vector<int> preorder = {0, 1, 3, 4, 2, 5};
    Node *root = buildTree(inorder, preorder);

    printLevelOrder(root);

    return 0;
}
