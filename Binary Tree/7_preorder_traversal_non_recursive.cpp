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

        void preorder(Node *root) {
            if(root == NULL) return;

            stack<Node *> s;
            s.push(root);

            while(!s.empty()) {
                auto top = s.top();
                s.pop();

                cout << top -> data << " ";

                if(top -> right != NULL) {
                    s.push(top -> right);
                }

                if(top -> left != NULL) {
                    s.push(top -> left);
                }
            }
        }
};



int main() {
    BinaryTree T;
    Node *root = T.createTree();

    T.preorder(root);
}