#include<bits/stdc++.h>
using namespace std;

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

            if(!input) return NULL;

            Node *newNode = new Node();
            cout << "Enter your data : "; cin >> data;
            newNode -> data = data;

            cout << "Left Child of " << newNode -> data << " : \n";
            newNode -> left = createTree();
            cout << "Right Child of " << newNode -> data << " : \n"; 
            newNode -> right = createTree();
            return newNode;
        }

        void inorder(Node *root) {
            if(root == NULL) return;

            // call left subtree
            inorder(root -> left);

            cout << root -> data << " ";

            // call right subtree
            inorder(root -> right);
        }

        void preorder(Node *root) {
            if(root == NULL) return;

            cout << root -> data << " ";

            preorder(root -> left);
            preorder(root -> right);
        }

        void postorder(Node *root) {
            if(root == NULL) return;

            postorder(root -> left);
            postorder(root -> right);

            cout << root -> data << " ";
        }
};

int main() {
    BinaryTree t;
    auto root = t.createTree();

    t.inorder(root); cout << endl;
    t.preorder(root); cout << endl;
    t.postorder(root); cout << endl;
    
    
    
    return 0;
}