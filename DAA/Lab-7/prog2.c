#include <stdio.h>

int main()
{
    int cost[10][10],visited[10]={0};
    int n,i,j,min,mincost=0,a,b,u,v,ne=1;

    scanf("%d",&n);

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }

    visited[1]=1;

    while(ne<n)
    {
        for(i=1,min=999;i<=n;i++)
            for(j=1;j<=n;j++)
                if(cost[i][j]<min)
                    if(visited[i]!=0)
                    {
                        min=cost[i][j];
                        a=u=i;
                        b=v=j;
                    }

        if(visited[u]==0 || visited[v]==0)
        {
            printf("%d %d %d\n",a,b,min);
            mincost+=min;
            visited[b]=1;
            ne++;
        }

        cost[a][b]=cost[b][a]=999;
    }

    printf("%d",mincost);
}