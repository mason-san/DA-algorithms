#include <stdio.h> 
#include <limits.h>
#include <stdbool.h>
#define V 4

int minKey(int *, bool *);
void printMst(int *, int graph[V][V]);
void primMST(int graph[V][V]); 

int main(){
    //Hard-coding the graph
    int graph[V][V] = { 
        {0, 2, INT_MAX, 9},
        {2, 0, 6, 4}, 
        {INT_MAX, 6, 0, 11}, 
        {9, 4, 11, 0} }; 

    printf("Minimum Spanning Tree using Prim's Algorithm: \n"); 
    primMST(graph);
    return 0; 
}

int minKey(int *key, bool *mstSet){
    //Function to find the vertex with minimum key value
    int min = INT_MAX, min_idx; 
    for(int i = 0 ; i < V; i++){
        if (mstSet[i] == 0 &&  key[i] < min){
            min = key[i]; 
            min_idx = i; 
        }
    }
    return min_idx; 
}

void printMst(int *parents, int graph[V][V]){
    //Function to print the constructed MST
    printf("\nMinimum Spanning Tree (MST):\n\nEdge \tWeight\n"); 
    for(int i = 1 ; i < V; i++){
        printf("%d-%d\t%d\n", parents[i], i, graph[parents[i]][i]);
    }
}

void primMST(int graph[V][V]){
    //Function to construct and print MST using PRIM's algorithm
    int parent[V]; 
    bool mstSet[V]; 
    int key[V];
    //initializing both the sets
    for(int i = 0 ; i < V; i++){
        key[i] = INT_MAX; 
        mstSet[i] = false; 
    } 
    //Setting first key value to 0
    key[0] = 0; 
    parent[0] = -1; //Root of MST 
    
    for(int count = 0; count < V-1; count++){
        int u = minKey(key, mstSet); 
        mstSet[u] = true; 
        for(int i = 0 ; i < V; i++){
            if(graph[u][i] && mstSet[i] == 0 && graph[u][i] < key[i]){
                parent[i] = u; 
                key[i] = graph[u][i]; 
            }
        }
    }

    float sum = 0; 
    for(int count = 0 ; count < V; count++){
        sum += key[count]; 
    }
    //print the mst set.  
    printMst(parent, graph);  
    printf("\nCost of MST is %.2f\n", sum); 
}