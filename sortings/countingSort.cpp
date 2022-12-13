#include<iostream>
using namespace std;

// O(N)
int max_element( int arr[], int n){
    int letMax = arr[0];
    for( int i = 1; i < n; i++ ){
        if( arr[i] > letMax ){
            letMax = arr[i];
        }
    }

    return letMax;
}

void countingSort( int arr[], int n ){
    int max_value = max_element(arr, n);
    int frequency[ max_value + 1 ] = {0};

    // add frequency to each arr[i] value  O(N)
    for( int i = 0; i < n; i++ ){
        frequency[ arr[i] ]++;
    }

    // set index to arr[i] value based on frequency  O(max_value) = O(M)
    for( int i = 1; i <= max_value; i++ ){
        frequency[i] = frequency[i-1] + frequency[i];
    }

    // put the value of arr[i] at the index given by frequency[ arr[i] ] O(N) 
    int newArr[n];
    for( int i = n - 1; i >= 0; i-- ){
        newArr[ frequency[arr[i]]-1 ] = arr[i];
        frequency[arr[i]]--;
    }

    // copy value to original array O(N)
    for( int i = 0; i < n; i++ )
       arr[i] = newArr[i];
}

int main(){
    int arr[] = {4,1,0,3,0,2,1};
    int size = sizeof(arr) / sizeof(int);

    countingSort(arr,size);
    for( int i = 0; i < size; i++ ){
        cout << arr[i] << " ";
    }

    return 0;
}

// Time complexity = O( N + N + M + N + N ) = O(N)