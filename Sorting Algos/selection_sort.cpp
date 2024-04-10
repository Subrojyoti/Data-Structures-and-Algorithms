#include <iostream>
using namespace std;

template<class T>
void selection_sort(T arr[], int n){
    for(int i = 0; i < n-1; i++){
        int mini = i;
        for(int j = i + 1; j < n; j++){
            if(arr[mini] > arr[j])
                mini = j;
        }
        swap(arr[i], arr[mini]);
    }
}

template<class T>
void print(T arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int arr[] = {3, 2, 9, 1, 8, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    selection_sort(arr, n);
    print(arr, n);
}