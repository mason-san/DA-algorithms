#include <stdio.h>
#include <stdlib.h> 
#include <time.h>  

void readArray(int a[], int n); 
void displayArray(int a[], int n); 
void insertionSort(int a[], int n); 

int main(){
    clock_t start, end; 
    double CPU_TIME_USED; 
    int n; 
    printf("Enter the number of Elements: "); 
    scanf("%d", &n); 
    int arr[100000]; 
    
    //reading array 
    readArray(arr, n); 

    printf("Original Array: "); 
    displayArray(arr, n); 

    //sorting
    start = clock();  
    insertionSort(arr, n); 
    end = clock();
    
    //cpu 
    CPU_TIME_USED = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nCPU time taken for Quick Sort: %g seconds\n", CPU_TIME_USED);    

    return 0; 
}

void readArray(int a[], int n){
    for(int i = 0 ; i < n ; i++){
        a[i] = rand(); 
    }
}

void displayArray(int a[], int n){
    for(int i = 0 ; i < n ; i++){
        printf("%d\t", a[i]); 
    }
    printf("\n"); 
}

void insertionSort(int a[], int n){
    int j, i, tmp; 
    for(i = 1; i < n ; i++){
        tmp = a[i]; 
        for(j = i - 1; j >= 0 && a[j] > tmp; j--){
            a[j+1] = a[j]; 
        } 
        a[j+1] = tmp; 
    }
}