#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    // constructor
    Node(): data(0), next(NULL){}
    Node(int x): data(x), next(NULL){}
    ~Node(){ next = NULL;}
};


class Queue{
    public:
    Node* front;
    Node* rear;
    int numOfElement;

    // constructors
    Queue();

    void insert(int val);
    void _delete();
    int size();
    int frontData();
};

