#include <stdio.h>
#define MAX 100
#include <time.h>

void makeArray(int n, int *a);
void quickSort(int a[], int low, int high);
int partition(int a[], int low, int high);
void swap(int a[], int i , int j);
void displayArray(int n, int *a);


int main(){
    //init
    int a[MAX];
    clock_t start, end;
    double CPU_TIME_USED;
    //make array
    makeArray(100, a);

    //calling the sort function
    start = clock();
    quickSort(a, 0, 100);
    end = clock();

    //cpu time
    CPU_TIME_USED = ((double)(end - start)) / CLOCKS_PER_SEC;

    //Printing the sorting function
    displayArray(100, a);

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

int partition(int a[], int low, int high){
    //Return the position of the pivot element (which is j)

    int i, j, pivot;
    i = low;
    j = high;
    pivot = a[low];

    while(i < j){
        i+=1;
        //i condition
        while(a[i] <= pivot){
            i++;
        }
        //j condition
        while(a[j] > pivot){
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

void quickSort(int a[], int low, int high){
    //RECURSIVE FUNCTION
    int j;
    //Checking the condition of recursion
    if (low < high){
        j = partition(a, low, high);
        quickSort(a, low, j-1); //left list
        quickSort(a, j+1, high);  //right list
    }
}
