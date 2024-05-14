#include "queue.cpp"
int main(){
    Queue q;
    for(int i = 10; i <= 100 ; i += 10)
        q.insert(i);
    
    cout << "Front: " << q.frontData() <<endl;
    cout << "Size: " << q.size() << endl;
    cout << "After Poping out front from queue"<<endl;
    q._delete();
    cout << "Front: "<< q.frontData() << endl;
    cout << "Size: " << q.size() << endl;

    return 0;
}