// Creation of a Singly Linked List and operations on it

#include <iostream>
using namespace std;

template <class T>
class Node{
    T data;
    Node<T>* next;
    public:
    void setData(T value) { data = value; }
    T getData() { return data; }
    void setNext(Node* link) { next = link; }
    Node* getNext() { return next; }
    Node(): data(0), next(NULL){}   // default constructor
    Node(T value): data(value), next(NULL){}  // parameterized constructor
    Node(T value, Node* link): data(value), next(link){}   // parametrized constructor
};

template <class T>
class SLinkedList{
    Node<T>* head;
    public:
    void setHead(Node* address) { head = address; }
    Node* getHead() { return head; }
    SLinkedList() { head = NULL; }
    void addNodeAtHead(T);
    void deleteNodeFromHead();
    void addNodeAtTail(T);
    void deleteNodeFromTail();
    void deleteNodeFromMiddle();
    void CountNodes();
};