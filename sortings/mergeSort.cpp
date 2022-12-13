#include<iostream>
using namespace std;

void merge( int arr[], int start, int mid, int end ){
    int i = start, j = mid+1;
    int newArr[end - start + 1], k = 0;
    while( i <= mid && j <= end ){
        if( arr[i] <= arr[j] ){
            newArr[k++] = arr[i];
            i++;
        }
        else{
            newArr[k++] = arr[j];
            j++;
        }
    }

    while( i <= mid ){
        newArr[k++] = arr[i];
        i++;
    }

    while( j <= end ){
        newArr[k++] = arr[j];
        j++;
    }

    for( int t = start; t <= end; t++ ){
        arr[t] = newArr[t - start];
    }
}

void mergeSort( int arr[], int start, int end ){
    if( start < end ){
        int mid = start + ( end - start ) / 2;
        mergeSort( arr, start, mid );
        mergeSort( arr, mid + 1, end );
        merge( arr, start, mid, end );
    }
}


int main(){
    int arr[] = {4,3,2,3,4,5};
    int size = sizeof(arr) / sizeof(int);
   
    mergeSort(arr, 0, size - 1);

    for( int i = 0; i < size; i++ ){
        cout << arr[i] << " ";
    }

    return 0;
}