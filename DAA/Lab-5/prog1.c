#include <stdio.h>

int main()
{
    int a[100],n,i,x;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    scanf("%d",&x);

    for(i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            printf("%d",i);
            return 0;
        }
    }

    printf("-1");
    return 0;
}