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

        int countNode(Node *root) {
            if(root == NULL) {
                return 0;
            }
            if(root -> left == NULL && root -> right == NULL) {
                return 1;
            }

            int left_cnt = countNode(root -> left);
            int right_cnt = countNode(root -> right);

            return left_cnt + right_cnt + 1;
        }
};

int main() {
    BinaryTree T;
    auto root = T.createTree();

    cout << T.countNode(root) << endl;
    
    
    return 0;
}