#include<iostream>
using namespace std;

template<class T>
class Node{
    T data;
    Node<T>* left;
    Node<T>* right;
    public:
    void setData(T value) { data = value; }
    T getData() { return data; }
    void setLeft(Node<T>* link) { left = link; }
    Node<T>* getLeft() { return left; }
    void setRight(Node<T>* link) { right = link; }
    Node<T>* getRight() { return right; }
    Node(): data(0), left(NULL), right(NULL) {}
    Node(T value): data(value), left(NULL), right(NULL) {}
};

template<class T>
class DLinked_list{
    public:
    Node<T>* head;
    DLinked_list(){ head = NULL; }
};