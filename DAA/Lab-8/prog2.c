#include <stdio.h>

int max(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    int val[100],wt[100],W,n,i,w,k[100][100];

    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&val[i]);

    for(i=0;i<n;i++)
        scanf("%d",&wt[i]);

    scanf("%d",&W);

    for(i=0;i<=n;i++)
        for(w=0;w<=W;w++)
        {
            if(i==0 || w==0)
                k[i][w]=0;
            else if(wt[i-1]<=w)
                k[i][w]=max(val[i-1]+k[i-1][w-wt[i-1]],k[i-1][w]);
            else
                k[i][w]=k[i-1][w];
        }

    printf("%d",k[n][W]);

    return 0;
}