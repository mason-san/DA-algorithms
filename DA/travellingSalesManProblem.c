#include <stdio.h>
#include <limits.h>

int ary[10][10], completed[10], n, cost=0;

void takeInput(){
    int i, j;

    printf("Enter the number of villages: ");
    scanf("%d", &n);

    printf("\nEnter the Cost Matrix.\n");

    for(i = 0 ; i < n ;i++){
        printf("Enter row %d: \n", i+1);
        for(j = 0 ; j < n ; j++){
            scanf("%d", &ary[i][j]);
        }
        printf("\n");
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
    takeInput();

    printf("\n\nThe Path is: \n");
    mincost(0);

    printf("\n\nMinimum cost is %d\n", cost);
    return 0;
}