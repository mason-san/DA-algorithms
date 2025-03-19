#include <stdio.h> 
#include <stdlib.h> 

void swap(float *, float *);
void sort(float [], float [], float [], int); 
float knapsack(float, int, float [], float [], float[]); 
void disp(float [], int, float); 

int main(){
    int i, n; float m;

    printf("\nEnter the no of objects and the knapsack weight: "); 
    scanf("%d %f", &n, &m); 

    float w[50], p[50], ratio[50], x[50], tp=0; 

    printf("\nEnter the profits and weights for %d objects: ", n);
    for(i = 0 ; i < n ; i++){
        scanf("%f %f", &p[i], &w[i]); 
        ratio[i] = p[i] / w[i];
        x[i] = 0.0; 
    }

    //Sort the knapsack elements according to p/w
    sort(p, w, ratio, n); 

    tp = knapsack(m, n, p, w, x); 

    disp(x, n, tp);
    
    return 0; 
}

void swap(float *x, float *y){
    float tmp = *x; 
    *x = *y; 
    *y = tmp; 
}

void sort(float p[], float w[], float ratio[], int n){
    for(int i = 0 ; i < n - 1; i++){
        for(int j = 0 ; j < n - 1 - i; j++){
            if (ratio[j] < ratio[j + 1]){
                //swap profits 
                swap(&p[j], &p[j+1]);  
                //swap weights
                swap(&w[j], &w[j+1]); 
                //swap ratio
                swap(&ratio[j], &ratio[j+1]); 
            }
        }
    }

    printf("\nProfts\tWeights\tRatios\n"); 
    for(int i = 0 ; i < n ; i++){
        printf("%f\t%f\t%f\n", p[i], w[i], ratio[i]); 
    }
}

float knapsack(float m, int n, float *p, float *w, float *x){
    int i; 
    float totalProfit = 0.0; 
    float remainingWeight = m;  

    for(i = 0 ; i < n ; i++){ 
        if (w[i] > remainingWeight){
            break; 
        } 
        x[i] = 1; 
        remainingWeight -= w[i]; 
        totalProfit += p[i]; 
    }

    if (i < n){
        x[i] = remainingWeight / w[i]; 
    } 
    totalProfit += (x[i] * p[i]); 
    return totalProfit; 
}

void disp(float *x, int n, float tp){
    printf("\nNow, displaying the result vector\n");  
    int i; 
    for(i = 0 ; i < n ; i++){
        printf("%f\t", x[i]); 
    } 
    printf("\nThe Total profit is: %f", tp); 
}