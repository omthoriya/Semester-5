#include <stdio.h>

#define INF 9999

int main()
{
    int G[10][10],n,i,j,start;
    int cost[10][10],dist[10],visited[10]={0},pred[10];
    int count,mind,next;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&G[i][j]);

    scanf("%d",&start);

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j]==0)
                cost[i][j]=INF;
            else
                cost[i][j]=G[i][j];

    for(i=0;i<n;i++)
    {
        dist[i]=cost[start][i];
        pred[i]=start;
    }

    dist[start]=0;
    visited[start]=1;
    count=1;

    while(count<n-1)
    {
        mind=INF;

        for(i=0;i<n;i++)
            if(dist[i]<mind && !visited[i])
            {
                mind=dist[i];
                next=i;
            }

        visited[next]=1;

        for(i=0;i<n;i++)
            if(!visited[i])
                if(mind+cost[next][i]<dist[i])
                {
                    dist[i]=mind+cost[next][i];
                    pred[i]=next;
                }

        count++;
    }

    for(i=0;i<n;i++)
        if(i!=start)
            printf("%d ",dist[i]);

    return 0;
}