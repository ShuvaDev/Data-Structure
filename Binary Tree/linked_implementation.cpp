#include<bits/stdc++.h>
using namespace std;
// implementation of binary tree in linked list using recursive procedure

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
};

int main() {
    BinaryTree t;
    Node *root = t.createTree();
    cout << root -> data << endl;
    cout << root -> left -> data << endl;
    cout << root -> right -> data << endl;
    
    
    
    return 0;
}