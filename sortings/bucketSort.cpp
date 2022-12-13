#include<iostream>
using namespace std;

void insertionSort( float arr[], int size ){

    for( int i = 1; i < size; i++ ){
        float temp = arr[i];
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
    float bucket[10][n];

    for( int i = 0; i < n; i++ ){
        int index = arr[i] * 10;
        bucket[ index ][bucketCount[ index ]] = arr[i];
        bucketCount[ index ]++;
    }

    for( int i = 0; i < 10; i++ ){
        insertionSort( bucket[i],  bucketCount[i] );
    }

    float newArr[n];
    int k = 0;
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
    float arr[] = {0.41,0.35,0.22,0.87,0.15,0.33,0.27};
    int n = sizeof(arr) / sizeof(int);
    bucketSort(arr, n);

    for( int i = 0; i < n; i++  ){
        cout << arr[i] << " ";
    }

    return 0;
}