#include "queue.h"

Queue :: Queue(){
    front = rear = NULL;
    numOfElement = 0;
}

void Queue :: insert(int val){
    Node* newNode = new Node(val);
    if(front == NULL){
        front = rear = newNode;
        numOfElement++;
        return;
    }
    rear->next = newNode;
    rear = newNode;
    numOfElement++;
}

void Queue :: _delete(){
    Node* temp = front;
    front = front->next;
    delete temp;
    numOfElement--;
}

int Queue :: size(){
    return numOfElement;
}

int Queue :: frontData(){
    return front->data;
}