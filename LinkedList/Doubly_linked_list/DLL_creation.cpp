#include<iostream>
using namespace std;

template<class T>
class Node{
    T data;
    Node<T>* prev;
    Node<T>* next;
    public:
    void setData(T value) { data = value; }
    T getData() { return data; }
    void setPrev(Node<T>* link) { prev = link; }
    Node<T>* getPrev() { return prev; }
    void setNext(Node<T>* link) { next = link; }
    Node<T>* getNext() { return next; }
    Node(): data(0), prev(NULL), next(NULL) {}
    Node(T value): data(value), prev(NULL), next(NULL) {}
};

template<class T>
class DLinked_list{
    public:
    Node<T>* head;
    DLinked_list(){ head = NULL; }
    ~DLinked_list();
    void addNodeAtBegining(T);
    void deleteNodeFromBegining();
    void addNodeAtTheEnd(T);
    void deleteNodeFromTheEnd();
    template class<U>
    friend ostream& operator << (ostream&, const DLinked_list<U>&);
};
template<class T>
DLinked_list<T> :: ~DLinked_list(){
    Node<T>* temp = head;
    while(temp){
        Node<T>* temp2 = temp;
        temp = temp->getNext();
        delete temp2;
    }
}

template<class T>
void DLinked_list<T> :: addNodeAtBegining(T val){
    Node<T>* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
    }
    else{
        newNode->setNext(head);
        head->setPrev(newNode);
        head = newNode;
    }
}

template <class T>
void DLinked_list<T> :: deleteNodeFromBegining(){
    if(head == NULL){
        cout << "The list is empty!"<<endl;
    }
    else{
        Node<T>* temp = head;
        head = head->getNext();
        head->setPrev(NULL);
        delete temp;
    }
}

template <class T>
void DLinked_list<T> :: addNodeAtTheEnd(T val){
    Node<T>* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
    }
    else{
        Node<T>* temp = head;
        while(temp->getNext()){
            temp = temp->getNext();
        }
        temp->setNext(newNode);
        newNode->setPrev(temp);
    }
}

template <class T>
void DLinked_list<T> :: deleteNodeFromTheEnd(){
    if(head == NULL){
        cout << "The list is empty !"<<endl;
    }
    else{
        Node<T>* temp = head;
        while(temp->getNext()){
            temp = temp->getNext();
        }
        Node<T>* temp2 = temp->getPrev();
        temp2->setNext(NULL);
        delete temp;
    }
}
template <class U>
ostream& operator << (ostream& out, const DLinked_list<U>& lst){
    Node<U>* temp = head;
    while(temp){
        out << temp->getData() << " ";
    }
    return out;
}