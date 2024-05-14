#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    // constructor
    Node(): data(0), left(NULL), right(NULL){}
    Node(int x): data(x), left(NULL), right(NULL){}
    ~Node(){
        left = NULL;
        right = NULL;
    }
};

class Tree{
    public:
    Node* root;

    // constructor
    Tree(): root(NULL){}

    Node* insert(Node* ,int);
    void display(Node*);
};