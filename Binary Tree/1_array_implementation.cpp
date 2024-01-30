#include<bits/stdc++.h>
#define MAX 10
using namespace std;

// Implement binary tree using array(0 based impl.)
/*
     a
    / \
   b  c
  / \
 d  e
*/

char tree[MAX];

// add root
void root(char r) {
    if(tree[0] != '\0') 
        cout << "Root already exists!\n";
    else 
        tree[0] = r;
}

// add left child in parent node
void left(char data, int parent) {
    if(tree[parent] == '\0') 
        cout << "Parent does't exists!\n";
    else 
        tree[2 * parent + 1] = data;
}

// add right child in parent node
void right(char data, int parent) {
    if(tree[parent] == '\0') 
        cout << "Parent does't exists!\n";
    else 
        tree[2 * parent + 2] = data;
}

void print() {
    for(int i = 0; i < MAX; i++) {
        if(tree[i] == '\0') 
            cout << "* ";
        else 
            cout << tree[i] << " ";
    }
    cout << endl;
}

int main() {
    root('a');
    left('b', 0);
    right('c', 0);
    left('d', 1);
    right('e', 1);

    print();
    
    
    return 0;
}