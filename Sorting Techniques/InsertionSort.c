#include<stdio.h>
void main(){
    int a[10];
    int i,j,k,key;
    printf("\n Enter 10 numbers to sort \n");
    //Take Inputs
    for(i=0;i<10;i++)
    {
        printf("\nFOR CELL#%d ",i+1);
        scanf("%d",&a[i]);
    }
    //Sort
    for(j=1;j<10;j++)
    {
        key=a[j];
        i=j-1;
        while(i>=0 && a[i]>key)
        {
            a[i+1]=a[i];
            i=i-1;
        }
        a[i+1]=key;
    }
    //Show outputs
    printf("\n-----:Sorting done:-----\n");
    for(k=0;k<10;k++)
    {
        printf("\n%d",a[k]);
    }

}
