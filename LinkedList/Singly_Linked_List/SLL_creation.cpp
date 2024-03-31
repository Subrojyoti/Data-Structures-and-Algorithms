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
    ~Node() {delete next;}
};

template <class T>
class SLinkedList{
    public:
    Node<T>* head;
    SLinkedList() { head = NULL; }
    ~SLinkedList();
    void addNodeAtHead(T);
    void deleteNodeFromHead();
    void addNodeAtTail(T);
    void deleteNodeFromTail();
    void deleteNodeFromMiddle();
    void CountNodes();
};

template <class T>
SLinkedList<T> :: ~SLinkedList(){
    Node<T>* temp = head;
    while( !temp ){
        head = head->getNext();
        delete temp;
        temp = head;
    }
}
template <class T>
void SLinkedList<T> :: addNodeAtHead(T data){
    Node<T>* newNode = new Node<T>(data);
    if(head == NULL)
        head = newNode;
    else{
        Node<T>* temp = head;
        while(temp->getNext() != NULL){
            temp = temp->getNext();
        }
        temp->setNext(newNode);
    }
}

template <class T>
void SLinkedList<T> :: deleteNodeFromHead(){
    if(head == NULL){
        cout << "The list is already empty."<< endl;
        return;
    }
    else{
        Node<T>* temp = head;
        head = head->getNext();
        delete temp;
    }
}

template<class T>
void SLinkedList<T> :: addNodeAtTail(T data){
    Node<T>* newNode = new Node<T>(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    else{
        Node<T>* temp = head;
        while(temp->getNext()){
            temp = temp->getNext();
        }
        temp->setNext(newNode);
    }
}
template <class T>
void SLinkedList<T> :: deleteNodeFromTail(){
    if(head == NULL){
        cout << "The list is already empty." << endl;
        return;
    }
    else{
        Node<T>* temp = head;
        while(temp->getNext()){
            temp = temp->getNext();
        }
        delete temp;
    }
}