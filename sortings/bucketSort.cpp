#include<iostream>
using namespace std;

void insertionSort( int arr[], int size ){

    for( int i = 1; i < size; i++ ){
        int temp = arr[i];
        int j = i - 1;
        while( j > -1 ){
            if( arr[j] > temp ){
                arr[j+1] = arr[j];
                j--;
            }else{
                break;
            }
        }

        arr[j+1] = temp;
    }
}

// input is from 0.0 to 0.9
void bucketSort(float arr[], int n){
    int bucketCount[10] = {0};
    int bucket[10][n];

    for( int i = 0; i < n; i++ ){
        bucket[ int(arr[i] * 10) ][bucketCount[ int(arr[i] * 10) ]] = arr[i];
        bucketCount[ int(arr[i] * 10) ]++;
    }

    for( int i = 0; i < 10; i++ ){
        insertionSort( bucket[i], bucketCount[i] );
    }

    int newArr[n], k = 0;
    for( int i = 0; i < 10; i++ ){
        for( int j = 0; j < bucketCount[i]; j++ ){
            newArr[k++] = bucket[i][j];
        }
    }

    for( int i = 0; i < n; i++ ){
        arr[i] = newArr[i];
    }
}

int main(){
    int arr[] = {41,35,22,87,15,33,27};
    int n = sizeof(arr) / sizeof(int);
    insertionSort(arr, n);

    for( int i = 0; i < n; i++  ){
        cout << arr[i] << " ";
    }

    return 0;
}