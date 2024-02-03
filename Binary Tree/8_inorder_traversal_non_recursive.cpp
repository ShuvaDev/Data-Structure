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
            cout << "\nPress 1 for add a node otherwise press 0 : ";
            cin >> input;

            if(input == 0) {
                return NULL;
            }

            Node *newNode = new Node();
            cout << "Enter your data : "; cin >> data;
            newNode -> data = data;
            cout << "\nLEFT CHILD OF " << newNode -> data << " : ";
            newNode -> left = createTree();
            cout << "\nRIGHT CHILD OF " << newNode -> data << " : ";
            newNode -> right = createTree();

            return newNode;  
        }

        void inorder(Node *root) {
            stack<Node *> s;
            Node *ptr = root;

            while(1) {
                while(ptr -> left != NULL) {
                    s.push(ptr);
                    ptr = ptr -> left;
                }

                while(ptr -> right == NULL) {
                    cout << ptr -> data << " ";
                    if(s.empty()) {
                        return;
                    }
                    ptr = s.top();
                    s.pop();
                }

                cout << ptr -> data << " ";
                ptr = ptr -> right;
            }
        }
};



int main() {
    BinaryTree T;
    Node *root = T.createTree();

    T.inorder(root);
}

/*
Algorithm
Step 1 : Initialize the pointer ptr by the address of the root node.
Step 2 : Push the address of the node pointed by ptr and make ptr point to the
         left child of the node.
Step 3 : Repeat step 2 untill the ptr points to the bottom-most left child.
Step 4 : If node pointed by ptr has no right child print the data of the node pointed
         by ptr. If stack is empty then stop algorithm otherwise pop the address from
         the stack. Finally put the address inside ptr.
Step 5 : Repeat step 4 until node pointed by ptr has a right child.
Step 6 : If node pointed by ptr has a right child then print the data of the node and
         update ptr by the address of the right child of the node. Finally go to step 2.
*/