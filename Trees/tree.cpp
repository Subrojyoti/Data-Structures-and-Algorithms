#include "tree.h"
#include <queue>
Node* Tree::insert(Node* root, int val) {
    Node* newNode = new Node(val);
    if (root == NULL) {
        root = newNode;
        return root;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* frontNode = q.front();
        q.pop();
        if (frontNode->left)
            q.push(frontNode->left);
        else {
            frontNode->left = newNode;
            return root;
        }
        if (frontNode->right)
            q.push(frontNode->right);
        else {
            frontNode->right = newNode;
            return root;
        }
    }
    return root;
}

void Tree :: display(Node* root){
    if(root == NULL)
        return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* frontNode = q.front();
        q.pop();
        cout << frontNode->data << " ";
        if(frontNode->left)
            q.push(frontNode->left);
        if(frontNode->right)
            q.push(frontNode->right);
    }
}