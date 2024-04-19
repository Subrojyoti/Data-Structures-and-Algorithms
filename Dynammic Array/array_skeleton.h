#ifndef ARRAYSKELETON_H
#define ARRAYSKELETON_H

template <class T>
class TemplateArray{
    T *arr;
    long capacity;
    long numOfElements;
    void resize();

    public:
    static const int DefaultArraySize = 1;

    // constructors
    TemplateArray(long capacity = DefaultArraySize); // default constructor
    TemplateArray(T *thisArray, long thisArraySize); // parameterised constructor
    TemplateArray(const TemplateArray <T>&); // copy constructor

    // destructor
    ~TemplateArray();
};

#endif