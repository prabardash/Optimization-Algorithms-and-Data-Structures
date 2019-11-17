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
