#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

int ary[100][100], completed[100], n, cost=0;

void takeInput(){
    int i, j;

    printf("Enter the number of villages: ");
    scanf("%d", &n);

    printf("\nEnter the Cost Matrix.\n");

    for(i = 0 ; i < n ;i++){
        for(j = 0 ; j < n ; j++){
            if (i != j){
                ary[i][j] = rand() % 10;
            }
        }
        ary[i][i] = 0;
        completed[i] = 0;
    }

    printf("\tThe Entered Adjacency Cost Matrix is: \n");
    for(i = 0 ; i < n ; i++){
        printf("\t");
        for(j = 0 ; j < n ; j++){
            printf("%d\t", ary[i][j]);
        }
        printf("\n");
    }
}

void mincost(int city){
    int i, ncity;

    completed[city] = 1;

    printf("%d ->", city+1);
    ncity = least(city);

    if (ncity == -1){
        ncity = 0;
        printf("%d", ncity+1);
        cost += ary[city][ncity];
        return;
    }

    cost += ary[city][ncity];
    mincost(ncity);

}

int least(int c){
    int i, nc = -1;
    int min = INT_MAX;

    for(i = 0 ; i < n; i++){
        if ((ary[c][i] != 0) && (completed[i] == 0)){
            if (ary[c][i] < min){
                min = ary[c][i];
                nc = i;
            }
        }
    }
    return nc;
}

int main(){

    clock_t start, end;
    double CPU_TIME_USED;
    start=clock();
    takeInput();

    printf("\n\nThe Path is: \n");
    mincost(0);
    end =  clock();

    printf("\n\nMinimum cost is %d\n", cost);

    printf("\n\nCPU time taken for used for solve the problem: %g seconds\n", CPU_TIME_USED);
    return 0;
}