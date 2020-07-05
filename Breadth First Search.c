#include <stdio.h>
#include <stdlib.h>
int q[50],front=1,rear=0,n,a[10][10],visited[20],i,j,count=0;
void bfs(int v)
{
    int w;
    count=count+1;
    visited[v]=count;
    printf("%d vis\n",v);
    q[++rear]=v;
    while(front<=rear)
    {
        v=q[front];
        for(w=1;w<=n;w++)
        {
            if(a[v][w]==1 && visited[w]==0)
            {
                count++;
                visited[w]=count;
                printf("%d vis\n",w);
                q[++rear]=w;
            }
        }
        front++;
    }
}

int main()
{
    int v1,v2,k,e;
    printf("Enter no of vert\n");
    scanf("%d",&n);
    printf("Enter no of edge\n");
    scanf("%d",&e);
    for(i=1;i<=n;i++)
    {


        for(j=1;j<=n;j++)
        {


        a[i][j]=0;
        }
    }
    printf("Enter edges one by one\n");
    for(i=1;i<=e;i++)
    {
        scanf("%d%d",&v1,&v2);
        a[v1][v2]=a[v2][v1]=1;
    }
    printf("Adjacency mat is:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    for(i=1;i<=n;i++)
        visited[i]=0;
    for(k=1;k<=n;k++)
    {
        if(visited[k]==0)
            bfs(k);
    }
    return 0;
}
