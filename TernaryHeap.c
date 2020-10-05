//
// Created by juan on 04/10/20.
//

#include "TernaryHeap.h"
#include <stdlib.h>
#include <stdio.h>

THeap * createTHeap(int capacity) {
    THeap *h = (THeap *) malloc(sizeof(THeap));
    if (h == NULL) {
        printf("ERROR: Memory couldn't get allocated\n");
        return NULL;
    }

    h->capacity = capacity;
    h->data = (int*)malloc(capacity*sizeof(int));

    if (h->data == NULL)
        printf("ERROR: Memory for heap data couldn't get allocated\n");

    return h;
}

void swap(int *arr, int i, int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int left(int i){
    return 3*i+1;
}

int right(int i){
    return 3*i+2;
}

int middle(int i){
    return 3*i+3;
}

int parent(int i){
    return (i-1)/3;
}

void bottomUpHeapify(int *arr, int k){
    int p = parent(k);
    //verify heap property
    while(k>0 && arr[p] < arr[k]){
        swap(arr, p, k);
        // index p is now index of parent
        k = p;
        p = parent(k);
    }
}

void topDownHeapify(int *arr, int k, int size){
    int maxChild;
    int maxVal;
    while(3*k < size){
        if (left(k) >= size)
            return;

        maxChild = left(k);
        maxVal = arr[maxChild];
        //select min child
        int next_child = 1;
        while(maxChild + next_child > size && next_child < 3 ){
            if (maxVal > arr[left(k) + next_child]){
                maxVal = arr[left(k) + next_child];
                maxChild = left(k) + next_child;
            }
            next_child++;
        }
        //verify if heap property is fulfilled
        if (arr[k] > maxVal )
            return;

        //propery not fulfilled, swap elements
        swap(arr, k, maxChild);
        k = maxChild;
    }
}

void insert(THeap *h, int data){
    if (h->size == h->capacity){
        printf("ERROR: full capacity\n");
        return;
    }
    h->data[(h->size)++] = data;
    //verify heap property
    bottomUpHeapify(h->data, h->size - 1);
}

int removeMax(THeap *h){
    int max = h->data[0];
    h->data[0] = h->data[--(h->size)];
    topDownHeapify(h->data, 0, h->size);
    return max;
}

int getMax(THeap *h){
    if (h->size==0){
        printf("HEAP EMPTY\n");
        return 0;
    }
    return h->data[0];
}

void printHeap(THeap *h){
    for (int i = 0; i<h->size; i++)
        printf("%d ", h->data[i]);
    printf("\n");
}

int topNonLeafNode(THeap *h){
    return h->size / 3;
}

void verifyHeapProperty(THeap *h){
    int n = topNonLeafNode(h);

    for (int i = 0; i<n; i++){
        if (left(i)<n && h->data[i] < h->data[left(i)]) {
            printf("HEAP PROPERTY VIOLATED at index %d \n", i);
            return;
        }else if(right(i)<n && h->data[i] < h->data[right(i)]){
            printf("HEAP PROPERTY VIOLATED at index %d \n", i);
            return;
        }else if (middle(i) < n && h->data[i] < h->data[middle(i)]){
            printf("HEAP PROPERTY VIOLATED at index %d \n", i);
            return;
        }
    }
    printf("HEAP OK\n");
}





//MIN HEAP
void minBottomUpHeapify(int *arr, int k){
    int p = parent(k);
    //verify heap property
    while(k>0 && arr[p] > arr[k]){
        swap(arr, p, k);
        // index p is now index of parent
        k = p;
        p = parent(k);
    }
}

void minTopDownHeapify(int *arr, int k, int size){
    int minChild;
    int minVal;
    
    while(3*k< size){
        if (left(k)>= size)
            return;

        minChild = left(k);
        minVal = arr[minChild];
        //select min child
        int next_child = 1;
        while(minChild + next_child < size && next_child < 3 ){
            if (minVal > arr[left(k) + next_child]){
                minVal = arr[left(k) + next_child];
                minChild = left(k) + next_child;
            }
            next_child++;
        }
        //verify if heap property is fulfilled
        if (arr[k] < minVal )
            return;

        //propery not fulfilled, swap elements
        swap(arr, k, minChild);
        k = minChild;
    }
}

void minHeapInsert(THeap *h, int data){
    if (h->size == h->capacity){
        printf("ERROR: full capacity\n");
        return;
    }
    h->data[(h->size)++] = data;
    //verify heap property
    minBottomUpHeapify(h->data, h->size - 1);
}

int removeMin(THeap *h){
    int max = h->data[0];
    h->data[0] = h->data[--(h->size)];
    minTopDownHeapify(h->data, 0, h->size);
    return max;
}

int getMin(THeap *h){
    if (h->size==0){
        printf("HEAP EMPTY\n");
        return 0;
    }
    return h->data[0];
}

void verifyMinHeapProperty(THeap *h){
    int n = topNonLeafNode(h);

    for (int i = 0; i<n; i++){
        if (left(i)<n && h->data[i] > h->data[left(i)]) {
            printf("HEAP PROPERTY VIOLATED at index %d \n", i);
            return;
        }else if(right(i)<n && h->data[i] > h->data[right(i)]){
            printf("HEAP PROPERTY VIOLATED at index %d \n", i);
            return;
        }else if (middle(i) < n && h->data[i] > h->data[middle(i)]){
            printf("HEAP PROPERTY VIOLATED at index %d \n", i);
            return;
        }
    }
    printf("HEAP OK\n");
}


