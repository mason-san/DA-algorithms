#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

void makeArray(int n, int *a);
void quickSort(int size, int a[], int low, int high);
int partition(int size, int a[], int low, int high);
void swap(int a[], int i , int j);
void displayArray(int n, int *a);


int main(){
    //init
    int a[100000];
    int size; 
    clock_t start, end;
    double CPU_TIME_USED;
    //make array
    printf("Enter Array SIze: "); 
    scanf("%d", &size); 
    makeArray(size, a);

    //calling the sort function
    start = clock();
    printf("IT enters here.\n"); 
    quickSort(size, a, 0, size-1);
    end = clock();

    //cpu time
    CPU_TIME_USED = ((double)(end - start)) / CLOCKS_PER_SEC;

    //Printing the sorting function
    displayArray(size, a);

    printf("\n\nCPU time taken for Quick Sort: %g seconds\n", CPU_TIME_USED);

    return 0;
}

void makeArray(int n, int *a){
    printf("Enter array elements of size %d: ", n);
    for(int i = 0 ; i < n ; i++){
        a[i] = rand();
    }
}

void displayArray(int n, int *a){
    for(int i = 0 ; i < n; i++){
        printf("%d\t", a[i]);
    }
}

int partition(int size, int a[], int low, int high){
    //Return the position of the pivot element (which is j)

    int i, j, pivot;
    i = low;
    j = high;
    pivot = a[low];

    while(i < j){
        i+=1;
        //i condition
        while((a[i] <= pivot) && (i < size)){
            i++;
        }
        //j condition
        while((a[j] > pivot) && (j > 0)){
            j--;
        }

        //check if i and j are still in the correct position
        if (i < j){
            swap(a, i, j);
        }
    }
    //Now swap low and j
    swap(a, low, j);
    return j;
}

void swap(int a[], int i, int j){
    //Swap two numbers by their pointers
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
}

void quickSort(int size, int a[], int low, int high){
    //RECURSIVE FUNCTION
    int j;
    //Checking the condition of recursion
    if (low < high){
        j = partition(size, a, low, high);
        quickSort(size, a, low, j-1); //left list
        quickSort(size, a, j+1, high);  //right list
    }
}

