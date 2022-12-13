#include<iostream>
using namespace std;

int size = 0;
int capacity = 50;
struct node{
    int data;
    int priority;
};

void Heapify( node pqueue[],int i ){
    int leftChild = 2*i;
    int rightChild = 2*i + 1;

    int largest = i;

    if( leftChild < size && pqueue[leftChild].priority >= pqueue[i].priority ){
        largest = leftChild;
    }

    if( rightChild < size && pqueue[rightChild].priority > pqueue[largest].priority ){
        largest = rightChild;
    }

    if( largest != i ){
        swap( pqueue[largest], pqueue[i]);
        Heapify(pqueue, largest );
    }

}

void increase_priority( node pqueue[], int i, int priority ){
    int curNode = i;
    int par = i / 2;
    pqueue[curNode].priority = priority;

    while( curNode > 1 && pqueue[curNode].priority > pqueue[par].priority ){
        swap( pqueue[curNode], pqueue[par]);
        curNode = par;
        par = par / 2;
    }
}

void insert( node pqueue[], int newData, int priority ){
    size = size + 1;
    pqueue[size].data = newData;
    pqueue[size].priority = -1;

    increase_priority(pqueue,size,priority);
}

node deleteElement( node pqueue[] ){
    node save = pqueue[1];
    swap(pqueue[1], pqueue[size]);
    size--;
    Heapify(pqueue,1);
    return save;
}

void display(node pqueue[] ){
    cout << "Queue : " ;
    for( int i = 1;i <= size; i++ ){
        cout << pqueue[i].data << ", " << pqueue[i].priority << " = ";
    }
    cout << endl;
}

int main(){
    node pqueue[capacity];
    insert(pqueue,10,1);
    display(pqueue);
    insert(pqueue,8,5);
    display(pqueue);
    insert(pqueue,5,3);
    display(pqueue);
    insert(pqueue,5,10);
    display(pqueue);

    node temp = deleteElement(pqueue);
    cout << "delete " << temp.data << " ," << temp.priority << endl; 
    display(pqueue);
    temp = deleteElement(pqueue);
    cout <<  "delete " << temp.data << " ," << temp.priority << endl;
    display(pqueue); 
    temp = deleteElement(pqueue);
    cout <<  "delete " << temp.data << " ," << temp.priority << endl;
    display(pqueue); 
    
    return 0;
}

