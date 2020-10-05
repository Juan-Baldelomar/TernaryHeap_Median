#include <stdio.h>
#include "TernaryHeap.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Median.h"

int getRandom(int base, int limit) {
    return base + rand() % (limit - base + 1);
}


void medianDriver() {
    THeap *thmax = createTHeap(100);
    THeap *thmin = createTHeap(100);

    printf("median: %f\n", theap_median(thmin, thmax, 1));
    printf("median: %f\n", theap_median(thmin, thmax, 4));
    printf("median: %f\n", theap_median(thmin, thmax, 6));
    printf("median: %f\n", theap_median(thmin, thmax, 2));
    printf("median: %f\n", theap_median(thmin, thmax, 8)); //4
    printf("median: %f\n", theap_median(thmin, thmax, 15)); //5
    printf("median: %f\n", theap_median(thmin, thmax, 20)); //6
    printf("median: %f\n", theap_median(thmin, thmax, 3)); //5
    printf("median: %f\n", theap_median(thmin, thmax, 5)); //5

}

void testMinHeap() {
    srand(time(0));

    THeap *h = createTHeap(100);

    for (int i = 0; i < 30; i++) {
        int data = getRandom(0, 200);
        printf("%d ", data);
        minHeapInsert(h, data);
    }
    printf("\n");
    verifyMinHeapProperty(h);
    printHeap(h);

    printf("max: %d\n", getMin(h));
    printf("removing min: %d\n", removeMin(h));

    verifyMinHeapProperty(h);
    printHeap(h);

    printf("removing min: %d\n", removeMin(h));

    verifyMinHeapProperty(h);
    printHeap(h);
}

int main() {
    //testMinHeap();
    medianDriver();

    return 0;
}
