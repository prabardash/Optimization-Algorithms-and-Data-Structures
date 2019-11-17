#include<stdio.h>
#include"MaxHeapify.h"

int extractMax(int *A, int heapsize)
{
    int target=heapsize-1;
    int maximum=A[0];
    A[0]=target;
    heapsize=heapsize-1;
    maxHeapify(A,0,heapsize);
    return maximum;
}
