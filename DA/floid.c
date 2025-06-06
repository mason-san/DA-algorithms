#include <stdio.h>
#include <limits.h>
#define V 4
#define INF 99999

void printSolution(int dist[][V]);
void floydWarshall(int dist[][V]);

int main(){
    int graph[V][V] = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, INF},
        {INF, INF, 1, 0}
    };

    floydWarshall(graph);

    return 0;
}

void printSolution(int dist[][V]){
    printf("The following matrix shows the shortest distance between every pair of Vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s","INF");
            else
                printf("%7d ", dist[i][j]);
        }
        printf("\n");
    }
}
void floydWarshall(int dist[][V])
{
    int i,j,k;
    for(k=0;k<V;k++){
        for(i=0;i<V;i++){
            for(j=0;j<V;j++){
                if(dist[i][k]+dist[k][j]<dist[i][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
    printSolution(dist);
}
