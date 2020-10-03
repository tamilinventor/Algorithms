#include<stdio.h>
int a,b,u,v,n,i,j,ne=1;
int visited[10]={0}, min, minCos = 0, cost[10][10];
int main()
{
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    printf("\nEnter the cost matrix\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = 999; 
        }
    }
    visited[1] = 1;   
    printf("\n");
    while(ne<n){
        for(i=1,min=999;i<=n;i++){
            if(visited[1] == 1){
                for(j=1;j<=n;j++){
                    if(cost[i][j] < min){
                        min = cost[i][j];
                        a = i;       //retains row
                        b = j;       //retains col
                    }
                }
            }
        }
        if(visited[b] == 0){
            printf("\n  Edge %d:(%d %d) cost = %d", ne++, a, b, min);
            minCos += min;
            visited[b] = 1;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\n Minimum cost = %d", minCos);
    return 0;
}