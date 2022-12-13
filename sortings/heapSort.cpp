#include<iostream>
using namespace std;

void Heapify( int arr[], int n, int i ){
    int leftChild = 2*i;
    int rightChild = 2*i + 1;

    int largest = i;

    if( leftChild <= n && arr[leftChild-1] >= arr[i-1] ){
        largest = leftChild;
    }

    if( rightChild <= n && arr[rightChild-1] > arr[largest-1] ){
        largest = rightChild;
    }

    if( largest != i ){
        swap( arr[largest-1], arr[i-1]);
        n--;
        Heapify(arr, n, largest );
    }

}

void buildMaxHeap( int arr[], int n ){
    for( int i = n / 2; i >= 1; i--){
        Heapify(arr,n,i);
    }
}

void heapSort(int arr[], int n){
    buildMaxHeap(arr,n);
    
    for( int i = n; n > 1; i-- ){
        swap(arr[0],arr[i-1]);
        n--;
        Heapify(arr, n, 1);
    }
}

int main(){
    int arr[] = {4,3,2,3,7,9,0,6,4,5};
    int size = sizeof(arr) / sizeof(int);
    heapSort( arr, size);

    for( int i = 0; i < size; i++ ){
        cout << arr[i] << " ";
    }

    return 0;
}