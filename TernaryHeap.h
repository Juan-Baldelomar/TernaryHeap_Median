//
// Created by juan on 04/10/20.
//

#ifndef PA1_T8_TERNARYHEAP_H
#define PA1_T8_TERNARYHEAP_H

typedef struct HeapStruct{
    int capacity;
    int size; //also next available position
    int *data;
}THeap;


int left(int i);
int right(int i);
int middle(int i);
int parent(int i);
THeap * createTHeap(int n);
void bottomUpHeapify(int *arr, int k);
void topDownHeapify(int *arr, int k, int n);
int topNonLeafNode(THeap *h);
void insert(THeap *h, int data);
void printHeap(THeap *h);
void verifyHeapProperty(THeap *h);
int getMax(THeap *h);
int removeMax(THeap *h);


void minBottomUpHeapify(int *arr, int k);
void minTopDownHeapify(int *arr, int k, int n);
void minHeapInsert(THeap *h, int data);
int getMin(THeap *h);
int removeMin(THeap *h);
void verifyMinHeapProperty(THeap *h);

#endif //PA1_T8_TERNARYHEAP_H
