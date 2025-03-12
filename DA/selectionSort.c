//Selection sort program
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   

void makeArray(int n, int *a); 
void selectionSort(int n, int *a); 
void displayArray(int n, int *a); 

int main(){
    //init 
    int numberOfElements, elements[100000];
    clock_t start, end; 
    double CPU_TIME_USED; 

    printf("Enter number of elements: "); 
    scanf("%d", &numberOfElements); 
    makeArray(numberOfElements, elements); 

    printf("Before Sorting: \n");  
    displayArray(numberOfElements, elements); 
    printf("\n"); 

    start = clock(); 
    selectionSort(numberOfElements, elements); 
    end =  clock(); 
    //to get the time in seconds. 
    CPU_TIME_USED = ((double)(end - start)) / CLOCKS_PER_SEC;  

    printf("\n\nCPU time taken for Selection Sort: %g seconds\n", CPU_TIME_USED); 

    return 0;
}

void makeArray(int n, int *a){
    printf("Enter array elements of size %d: ", n); 
    for(int i = 0 ; i < n ; i++){ 
        a[i] = rand(); 
    }
}

void selectionSort(int n, int *a){
    for(int i = 0 ; i < (n-1); i++){
        for(int j = i+1; j < n; j++){
            if (a[i] > a[j]){
                int tmp = a[i]; 
                a[i] = a[j]; 
                a[j] = tmp; 
            }
        }
    } 

}

void displayArray(int n, int *a){ 
    for(int i = 0 ; i < n; i++){
        printf("%d\t", a[i]); 
    }
}
