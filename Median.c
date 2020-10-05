//
// Created by juan on 05/10/20.
//

#include "Median.h"

double theap_median(THeap * thmin, THeap * thmax, int data){
    double currentMedian;
    double updatedMedian;

    if (thmin->size == thmax->size){
        if (thmin->size == 0)
            currentMedian = 0;
        else
            currentMedian = (getMin(thmin) + getMax(thmax))/2.0;

        if (data < currentMedian){
            insert(thmax, data);
            updatedMedian = getMax(thmax);
        }else{
            minHeapInsert(thmin, data);
            updatedMedian = getMin(thmin);
        }
    }else if (thmin->size < thmax->size){
        currentMedian = getMax(thmax);
        if (data<currentMedian){
            int max = removeMax(thmax);
            minHeapInsert(thmin, max);
            insert(thmax, data);
        }else{
            minHeapInsert(thmin, data);
        }
        updatedMedian = (getMin(thmin) + getMax(thmax))/2.0;
    } else{
        currentMedian = getMin(thmin);
        if (data>currentMedian){
            int min = removeMin(thmin);
            insert(thmax, min);
            minHeapInsert(thmin, data);
        }else{
            insert(thmax, data);
        }
        updatedMedian = (getMin(thmin) + getMax(thmax))/2.0;
    }
    return updatedMedian;
}