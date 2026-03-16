#include <stdio.h>

int a[1000];

int partition(int low,int high)
{
    int pivot=a[low];
    int i=low,j=high,temp;

    while(i<j)
    {
        while(a[i]<=pivot && i<high) i++;
        while(a[j]>pivot) j--;

        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }

    temp=a[low];
    a[low]=a[j];
    a[j]=temp;

    return j;
}

void quick(int low,int high)
{
    if(low<high)
    {
        int p=partition(low,high);
        quick(low,p-1);
        quick(p+1,high);
    }
}

int main()
{
    int n,i;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    quick(0,n-1);

    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}