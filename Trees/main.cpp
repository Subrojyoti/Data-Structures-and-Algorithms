#include "tree.cpp"

int main(){
    Tree *t = new Tree;

    for(int i=10; i<=100; i+= 10){
        t->root = t->insert(t->root, i);
    }
    
    cout << "Elements of the tree `t` are:" <<endl;
    t->display(t->root);
    return 0;
}