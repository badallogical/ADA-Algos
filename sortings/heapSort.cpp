#include<iostream>
using namespace std;

void Heapify( int arr[], int n, int i ){
    int leftChild = 2*i;
    int rightChild = 2*i + 1;

    if( i == 0 ){
        leftChild = 1;
        rightChild = 2;
    }

    int largest = i;

    if( leftChild < n && arr[leftChild] >= arr[i] ){
        largest = leftChild;
    }

    if( rightChild < n && arr[rightChild] > arr[largest] ){
        largest = rightChild;
    }

    if( largest != i ){
        arr[i] = arr[i] + arr[largest];
        arr[largest] = arr[i] - arr[largest];
        arr[i] = arr[i] - arr[largest];

        Heapify(arr, n, largest );
    }

}

void buildMaxHeap( int arr[], int n ){
    for( int i = n / 2; i >= 0; i--){
        Heapify(arr,n,i);
    }
}

void heapSort(int arr[], int n){
    buildMaxHeap(arr,n);
    
    for( int i = n - 1; n > 0; i-- ){
        swap(arr[0],arr[i]);
        n--;
        Heapify(arr, n, 0);
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