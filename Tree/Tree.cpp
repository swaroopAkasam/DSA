#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in the left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in the right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp->data << " ";

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

void buildTreeFromLevelOrderTraversal(node* &root) {
    queue<node*> q;
    cout << "Enter the data for the root node: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);
    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter data for left node of: " << temp->data << endl;
        int leftData;
        cin >> leftData;
        if(leftData != -1) {
            temp ->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter data for right node of : " << temp->data << endl;
        int rightData;
        cin >> rightData;
        if(rightData != -1) {
            temp->right = new node(rightData);
            q.push(temp->right);
        }

    }
}

int main()
{

    node *root = NULL;
    // root = buildTree(root);
    buildTreeFromLevelOrderTraversal(root);
    levelOrderTraversal(root);

    return 0;
}