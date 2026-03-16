#include <stdio.h>

int a[100],t[100];

void merge(int low,int mid,int high)
{
    int i=low,j=mid+1,k=low;

    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
            t[k++]=a[i++];
        else
            t[k++]=a[j++];
    }

    while(i<=mid)
        t[k++]=a[i++];

    while(j<=high)
        t[k++]=a[j++];

    for(i=low;i<=high;i++)
        a[i]=t[i];
}

void msort(int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        msort(low,mid);
        msort(mid+1,high);
        merge(low,mid,high);
    }
}

int main()
{
    int n,i;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    msort(0,n-1);

    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}