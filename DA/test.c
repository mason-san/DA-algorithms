#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX 20

int ary[MAX][MAX], completed[MAX], n, cost;

void generateRandomMatrix(int n) {
    for (int i = 0; i < n; i++) {
        completed[i] = 0;
        for (int j = 0; j < n; j++) {
            if (i == j)
                ary[i][j] = 0;
            else
                ary[i][j] = rand() % 100 + 1;
        }
    }
}

int least(int c) {
    int i, nc = -1;
    int min = INT_MAX;
    for (i = 0; i < n; i++) {
        if ((ary[c][i] != 0) && (completed[i] == 0)) {
            if (ary[c][i] < min) {
                min = ary[c][i];
                nc = i;
            }
        }
    }
    return nc;
}

void mincost(int city) {
    int ncity;

    completed[city] = 1;
    ncity = least(city);

    if (ncity == -1) {
        ncity = 0;
        cost += ary[city][ncity];
        return;
    }

    cost += ary[city][ncity];
    mincost(ncity);
}

int main() {
    FILE *fp = fopen("tsp_time.csv", "w");
    fprintf(fp, "Nodes,Time(ms)\n");

    for (int size = 4; size <= 20; size += 4) {
        n = size;
        generateRandomMatrix(n);
        cost = 0;

        clock_t start = clock();
        mincost(0);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        fprintf(fp, "%d,%.4f\n", n, time_taken);
        printf("Nodes: %d -> Time: %.2f ms\n", n, time_taken);
    }

    fclose(fp);
    return 0;
}
