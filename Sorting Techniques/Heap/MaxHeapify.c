void maxHeapify(int *A, int root, int heapsize)
{
    int l,r, temp, largest=root;

    l=2*root+1;
    r=2*root+2;

    if(A[l]>A[largest] && l<heapsize)
        largest=l;
    if (A[r]>A[largest] && r<heapsize)
        largest=r;

    if(largest!=root)
    {
        temp=A[root];
        A[root]=A[largest];
        A[largest]=temp;
        maxHeapify(A,largest,heapsize);
    }
}

void main()
{
    int n,i,root;
    printf("\nEnter array size: ");
    scanf("%d", &n);
    int A[n];
    printf("\nEnter elements into array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
        printf("\n");
    }
    printf("\n enter root index\n");
    scanf("%d", &root);
    maxHeapify(A,root, n);
    printf("\nOutput is:\n");
    for(i=0;i<n;i++)
        printf("\n%d\n",A[i]);
}
