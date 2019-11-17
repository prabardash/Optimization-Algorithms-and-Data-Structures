#include<stdio.h>
#include<math.h>

int partition(int *A, int p, int r)
{
    int key, i,j=p-1;
    int temp;
    key=A[r];
    for(i=p;i<=r-1;i++)
    {
        if(A[i]<=key)
        {
            j++;
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }

    j++;
    temp=A[j];
    A[j]=key;
    A[r]=temp;
    return j;
}

void quicksort(int *A, int p, int r)
{
    if(p<r)
    {
        int q=partition(A, p, r);
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
    }
}

void main()
{
    int n;
    printf("************************Quick Sort*************************\n\n\n");
    printf("Set array size to: ");
    scanf("%d",&n);
    //declare array
    int A[n];
    int i;
    printf("\nEnter %d numbers to array\n", n);
    for(i=0;i<n;i++)
    {
        printf("\n");
        scanf("%d",&(A[i]));
    }
    quicksort(A,0,n-1);
    printf("\nThe elements after Quicksort are :\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",A[i]);
    }
}
