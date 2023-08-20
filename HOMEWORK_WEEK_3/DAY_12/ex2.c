#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(double *arr, int size){
    for(int i = 0; i < size; i++) printf("%.2lf ", arr[i]);
    printf("\n");
}

int main(){
    srand(time(NULL));
    int n, m, p;

    printf("Enter the initial size of the array (n): ");
    scanf("%d", &n);

    double *arr = malloc(n * sizeof(double));
    if(arr == NULL) exit(EXIT_FAILURE);
    for(int i = 0; i < n; i++) arr[i] = (double)rand() / RAND_MAX;


    printf("Enter the number of elements to add (m): ");
    scanf("%d", &m);

    double *temp = realloc(arr, (n + m) * sizeof(double));
    if(temp == NULL) free(arr);  
    arr = temp;
    for(int i = n; i < n + m; i++) arr[i] = 1.0 + (double)rand() / RAND_MAX;
    n += m;


    printf("Enter the number of additional elements (p): ");
    scanf("%d", &p);

    temp = realloc(arr, (n + p) * sizeof(double));
    if(temp == NULL) free(arr);
    arr = temp;
    for(int i = n; i < n + p; i++) arr[i] = 2.0 + (double)rand() / RAND_MAX;
    n += p;

    printf("Array contents:\n");
    printArray(arr, n);

    free(arr);

    return 0;
}