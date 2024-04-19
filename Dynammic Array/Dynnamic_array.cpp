#include<iostream>
#include "array_skeleton.h"

template<class T>
void TemplateArray<T> :: resize(){
    T *newarr = new T[2 * capacity];
    for(int i = 0; i < numOfElements; i++)
        newarr[i] = arr[i];
    delete [] arr;
    arr = newarr;
}

template<class T>
TemplateArray<T> :: TemplateArray(long capacity = DefaultArraySize){
    arr = new T[capacity];
    this->capacity = capacity;
    numOfElements = 0;
}