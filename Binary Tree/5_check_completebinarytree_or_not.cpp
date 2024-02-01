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
        Node* createTree() {
            int input, data;
            cout << "Do you want to add a node? (0 for no and 1 for yes) : ";
            cin >> input;

            if(!input) return NULL;
            else {
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
            if(root == NULL) return 0;
            if(root -> left == NULL && root -> right == NULL) return 1;

            int leftCount = countNode(root -> left);
            int rightCount = countNode(root -> right);

            return leftCount + rightCount + 1;
        }

        bool isCompleteBinaryTree(Node *root, int index, int totalNode) {
            if(root == NULL) return true;
            if(index > totalNode) return false;

            
            bool left = isCompleteBinaryTree(root -> left, index * 2, totalNode);
            bool right = isCompleteBinaryTree(root -> right, index * 2 + 1, totalNode);

            return left && right;
        }
};


int main() {
    BinaryTree t;

    auto root = t.createTree();

    int totalNode = t.countNode(root);

    if(t.isCompleteBinaryTree(root, 1, totalNode)) {
        cout << "The Given Binary Tree is a Complete Binary Tree\n";
    } else {
        cout << "The Given Binary Tree is not Complete Binary Tree\n";
    }
    
    
    
    return 0;
}