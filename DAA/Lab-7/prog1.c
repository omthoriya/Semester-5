#include <stdio.h>

int parent[10];

int find(int i)
{
    while(parent[i])
        i=parent[i];
    return i;
}

int uni(int i,int j)
{
    if(i!=j)
    {
        parent[j]=i;
        return 1;
    }
    return 0;
}

int main()
{
    int cost[10][10],min,mincost=0,n,i,j,a,b,u,v,ne=1;

    scanf("%d",&n);

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }

    while(ne<n)
    {
        for(i=1,min=999;i<=n;i++)
            for(j=1;j<=n;j++)
                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }

        u=find(u);
        v=find(v);

        if(uni(u,v))
        {
            printf("%d %d %d\n",a,b,min);
            mincost+=min;
            ne++;
        }

        cost[a][b]=cost[b][a]=999;
    }

    printf("%d",mincost);
}