#include<stdio.h>
#include<math.h>
#include "MaxHeapify.h"

void buildHeap(int *A, int heapsize)
{
    int i,x=floor(heapsize/2)-1;
    for(i=x;i>=0;i--)
        maxHeapify(A,i,heapsize);
}

void main()
{
    int n,i;
    printf("Enter number of elements to array\n");
    scanf("%d",&n);
    int A[n];
    printf("\nEnter %d elements to array\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
        printf("\n");
    }

    buildHeap(A,n);

    printf("\n=============Max Heap build successful===============\n",n);
    for(i=0;i<n;i++)
        printf("%d\n",A[i]);

}
