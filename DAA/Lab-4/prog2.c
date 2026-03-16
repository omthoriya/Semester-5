#include <stdio.h>

int main()
{
    int arr[100], n, i, j, c, root, temp;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    for(i=1;i<n;i++)
    {
        c=i;
        do
        {
            root=(c-1)/2;
            if(arr[root]<arr[c])
            {
                temp=arr[root];
                arr[root]=arr[c];
                arr[c]=temp;
            }
            c=root;
        }
        while(c!=0);
    }

    for(j=n-1;j>=0;j--)
    {
        temp=arr[0];
        arr[0]=arr[j];
        arr[j]=temp;
        root=0;

        do
        {
            c=2*root+1;
            if((arr[c]<arr[c+1]) && c<j-1)
                c++;
            if(arr[root]<arr[c] && c<j)
            {
                temp=arr[root];
                arr[root]=arr[c];
                arr[c]=temp;
            }
            root=c;
        }
        while(c<j);
    }

    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    return 0;
}