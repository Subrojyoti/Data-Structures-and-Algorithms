#include <iostream>
using namespace std;

template<class T>
void merge(T arr[], int, int);
template<class T>
void merge_sort(T arr[], int l, int r){
    if(l < r){
        int mid = l + (r - l)/2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid+1, r);
        merge(arr, l, r);
    }
}

template<class T>
void merge(T arr[], int l, int r){
    int mid = l + (r - l) / 2;
    int len1 = mid -l + 1;
    int len2 = r - mid;
    T *first = new T[len1];
    T *second = new T[len2];
    int k = l;
    for(int i=0; i < len1; i++)
        first[i] = arr[k++];
    k = mid+1;
    for(int i = 0; i < len2; i++)
        second[i] = arr[k++];
    int i = 0, j = 0;
    k = l;
    while(i < len1 && j < len2){
        if(first[i] < second[j])
            arr[k++] = first[i++];
        else
            arr[k++] = second[j++];
    }
    while(i < len1)
        arr[k++] = first[i++];
    while(j < len2)
        arr[k++] = second[j++];

    delete [] first;
    delete [] second;
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
    merge_sort(arr, 0, n-1);
    print(arr, n);
}