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

        void levelorder(Node *root) {
            queue<Node *> Q;
            Q.push(root);

            while(!Q.empty()) {
                auto node = Q.front();
                cout << node -> data << " ";
                Q.pop();

                if(node -> left != NULL) {
                    Q.push(node -> left);
                }
                if(node -> right != NULL) {
                    Q.push(node -> right);
                }
            }
        }
};

int main() {
    BinaryTree t;
    auto root = t.createTree();

    t.levelorder(root); 
    
    return 0;
}