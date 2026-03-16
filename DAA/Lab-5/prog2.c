#include <stdio.h>

int main()
{
    int a[100],n,i,x,low,high,mid;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    scanf("%d",&x);

    low=0;
    high=n-1;

    while(low<=high)
    {
        mid=(low+high)/2;

        if(a[mid]==x)
        {
            printf("%d",mid);
            return 0;
        }
        else if(x<a[mid])
            high=mid-1;
        else
            low=mid+1;
    }

    printf("-1");
    return 0;
}