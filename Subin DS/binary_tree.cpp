#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;        
    Node * right;
};

Node * create_node(int item) {
    Node *new_node = new Node();
    new_node -> data = item;
    new_node -> left = NULL;
    new_node -> right = NULL;

    return new_node;
}

void add_left_child(Node *node, Node *child) {
    node -> left = child;
}

void add_right_child(Node *node, Node *child) {
    node -> right = child;
}

void pre_order_traverse(Node *root) {
    cout << root -> data << " ";

    if(root -> left != NULL) {
        pre_order_traverse(root -> left);
    }

    if(root -> right != NULL) {
        pre_order_traverse(root -> right);
    }
}

void in_order_traverse(Node *root) {

    if(root -> left != NULL) {
        in_order_traverse(root -> left);
    }

    cout << root -> data << " ";

    if(root -> right != NULL) {
        in_order_traverse(root -> right);
    }
}

void post_order_traverse(Node *root) {
    if(root -> left != NULL) {
        post_order_traverse(root -> left);
    }

    if(root -> right != NULL) {
        post_order_traverse(root -> right);
    }
    cout << root -> data << " ";
}

void level_order_traverse(Node *root) {
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

Node* input_tree() {
    int val; cin >> val;

    Node *root;
    queue<Node *> Q;
    if(val == -1) {
        root = NULL;
    } else {
        root = create_node(val);
        Q.push(root);
    }

    while(!Q.empty()) {
        auto node = Q.front();
        Q.pop();

        int leftValue, rightValue;
        cin >> leftValue >> rightValue;

        if(leftValue != -1) {
            auto leftNode = create_node(leftValue);
            node -> left = leftNode;
            Q.push(leftNode);
        }
        if(rightValue != -1) {
            auto rightNode = create_node(rightValue);
            node -> right = rightNode;
            Q.push(rightNode);
        }
    }
    return root;
}

int node_count() {

}

int leaf_node_count() {

}

int get_maximum_height() {

}

/*
     2
     -
    /  \
   3   4
  / \
 5   6
*/

int main() {
    /*
    Node *two = create_node(2);
    Node *three = create_node(3);
    Node *four = create_node(4);

    add_left_child(two, three);
    add_right_child(two, four);

    Node *five = create_node(5);
    Node *six = create_node(6);

    add_left_child(three, five);
    add_right_child(three, six);
    */

    auto root = input_tree();


    in_order_traverse(root); cout << endl;
    pre_order_traverse(root); cout << endl;
    post_order_traverse(root); cout << endl;
    level_order_traverse(root); cout << endl;
    
    return 0;
}