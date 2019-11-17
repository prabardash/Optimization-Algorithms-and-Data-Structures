
#include<stdio.h>
#include<math.h>
#include<limits.h>

void merge(int *A, int p, int q, int r)
{
    int n1=q-p+2;
    int n2=r-q+1;
    int arr1[n1], arr2[n2];
    arr1[n1-1]=INT_MAX;
    arr2[n2-1]=INT_MAX;
    int i,j=0,k=0;

    for(i=0;i<n1-1;i++)
        arr1[i]=A[p+i];
    for(i=0;i<n2-1;i++)
        arr2[i]=A[q+i+1];

    i=0; j=0;

    for(k=p;k<=r;k++)
    {
        if(arr1[i]<=arr2[j]){ A[k]=arr1[i]; i++;}
        else {A[k]=arr2[j]; j++;}
    }

}

void mergesort(int *A, int p, int r)
{
    int q;
    if(p<r)
    {
    q=floor((p+r)/2);
    mergesort(A,p,q);
    mergesort(A,q+1,r);
    merge(A,p,q,r);
    }

}

void main()
{
    int n;
    printf("************************Merge Sort*************************\n\n\n");
    printf("Set array size to: ");
    scanf("%d",&n);
    //declare array
    int A[n];
    int i;
    printf("Enter 10 numbers to array\n");
    for(i=0;i<n;i++)
    {
        printf("\n");
        scanf("%d",&(A[i]));
    }

    mergesort(A,0,n-1);

    printf("\nArray after mergesort is: \n");
    for(i=0;i<n;i++) printf("%d\n",A[i]);
}
