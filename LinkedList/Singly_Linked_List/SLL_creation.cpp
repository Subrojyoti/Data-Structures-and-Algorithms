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
    int CountNodes();
    template<class U>
    friend ostream& operator <<(ostream&, const SLinkedList<U>&);
};

template <class T>
SLinkedList<T> :: ~SLinkedList(){
    Node<T>* temp = head;
    while( !temp ){
        head = head->getNext();
        delete temp;
        temp = head;
    }
    head = NULL;
}
template <class T>
void SLinkedList<T> :: addNodeAtHead(T data){
    Node<T>* newNode = new Node<T>(data);
    if(head == NULL)
        head = newNode;
    else{
        newNode->setNext(head);
        head = newNode;
    }
}

template <class T>
void SLinkedList<T> :: deleteNodeFromHead(){
    if(head == NULL){
        cout << "The list is already empty."<< endl;
        return;
    }
    else if(head->getNext() == NULL){
        delete head;
        head = NULL;
    }
    else{
        Node<T>* temp = head->getNext();
        delete head;
        head = temp;
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
        Node<T>* temp2 = head;
        while(temp2->getNext() != temp)
            temp2 = temp2->getNext();
        temp2->setNext(NULL);
        delete temp;
    }
}

template<class T>
void SLinkedList<T> :: deleteNodeFromMiddle(){
    if(head == NULL){
        cout << "The list is empty"<<endl;
    }
    else if(head->getNext() == NULL){
        delete head;
    }
    else{
        Node<T>* slow = head;
        Node<T>* fast = head->getNext();
        while(fast != NULL && fast->getNext() != NULL){
            fast = fast->getNext()->getNext();
            slow = slow->getNext();
        }
        // here slow is now the middle node
        Node<T>* temp = head;
        while(temp->getNext() != slow)
            temp = temp->getNext();
        
        temp->setNext(slow->getNext());
        delete slow;
    }
}

template<class T>
int SLinkedList<T> :: CountNodes(){
    int count = 0;
    Node<T>* temp = head;
    while(temp){
        count++;
        temp = temp->getNext();
    }
    return count;
}

template<class T>
ostream& operator <<(ostream& out, const SLinkedList<T>& lst){
    Node<T>* temp = lst.head;
    while(temp){
        out << temp->getData() << " ";
        temp = temp->getNext();
    }
    return out;
}


int main(){
    SLinkedList<int> l1;
    l1.addNodeAtHead(1);
    l1.addNodeAtTail(2);
    l1.addNodeAtHead(3);
    l1.addNodeAtTail(4);
    l1.addNodeAtHead(5);


    cout << "l1 count: "<<l1.CountNodes()<<endl;
    cout << "List l1: "<<l1 <<endl;

    l1.deleteNodeFromTail();
    cout << "List l1: "<<l1;
    return 0;
}