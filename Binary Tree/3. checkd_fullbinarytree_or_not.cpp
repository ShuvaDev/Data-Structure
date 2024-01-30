#include<bits/stdc++.h>
using namespace std;
// Check a tree is a full binary tree or not

class Node {
    public:
        int data;
        Node *left;
        Node *right;
};

class BinaryTree {
    public:
        Node * createTree() {
            int input, data;
            cout << "Do you want to add a node? (0 for no and 1 for yes) : ";
            cin >> input;

            if(input == 0) {
                return NULL;
            } else {
                Node *newNode = new Node();
                cout << "Enter the data : "; cin >> data;
                newNode -> data = data;
                cout << "Left child of " << newNode -> data << "\n";
                newNode -> left = createTree();
                cout << "Right child of " << newNode -> data << "\n";
                newNode -> right = createTree();
                return newNode;
            }
        }

        bool isFullbinaryTree(Node *root) {
            if(root -> left == NULL && root -> right == NULL) {
                return true;
            } else if(root -> left && root -> right) {
                bool left = isFullbinaryTree(root -> left);
                bool right = isFullbinaryTree(root -> right);
                return (left && right);
            } else {
                return false;
            }
        }
};

int main() {
    BinaryTree t;
    Node *root = t.createTree();

    cout << t.isFullbinaryTree(root) << endl;
    
    
    return 0;
}