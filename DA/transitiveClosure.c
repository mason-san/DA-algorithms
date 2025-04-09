#include <stdio.h>
#include <limits.h>
#define V 3
#define INF 99999

void printSolution(int dist[][V]);
void warshall(int dist[][V]);

int main(){
    int graph[V][V] = {
        {0, 1, 0}, 
        {0, 0, 1}, 
        {1, 0, 0}
    };

    warshall(graph);

    return 0;
}

void printSolution(int dist[][V]){

    printf("the solution matrix is:\n");

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

void warshall(int dist[][V])
{
    int i,j,k;

    for(k=0;k<V;k++){
        for(i=0;i<V;i++){
            for(j=0;j<V;j++){
                dist[i][j] = dist[i][j] || (dist[i][k] && dist[k][j]);
            }
        }
    }
    printSolution(dist);
}
