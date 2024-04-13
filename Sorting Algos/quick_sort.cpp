#include <iostream>
using namespace std;

int partition(int arr[], int l, int r){
    int pivot_idx = l;
    int count = 0;
    // count the number of elements smaller than pivot element
    for(int i = l+1; i <= r; i++){
        if(arr[pivot_idx] > arr[i])
            count++;
    }
    int position = l + count;
    swap(arr[pivot_idx] , arr[position]); // places the pivot element at it's exact position
    pivot_idx = position;
    int s = l;
    int e = r;
    // smaller elements are kept on left side of pivot element and larger elements are kept on the right side of pivot element
    while(s < pivot_idx && e > pivot_idx){
        while(arr[s] < arr[pivot_idx])
            s++;
        while(arr[e] > arr[pivot_idx])
            e--;
        if(arr[s] > arr[pivot_idx] && arr[e] < arr[pivot_idx])
            swap(arr[s], arr[e]);
    }

    return pivot_idx;

}

void quick_sort(int arr[], int l, int r){
    if(l < r){
        int p = partition(arr, l, r); // gives the exact index of pivot element
        quick_sort(arr, l, p-1); // sort the left part of pivot index
        quick_sort(arr, p+1, r); // sort the right part of pivot index
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
    quick_sort(arr, 0, n-1);
    print(arr, n);
}
