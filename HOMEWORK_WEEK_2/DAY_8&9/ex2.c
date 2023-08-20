#include <stdio.h>
#include <stddef.h>

void* findMax(void* arr, size_t n, size_t elem_s, int (*cmp)(const void*, const void*));
int cmpInt(const void* a, const void* b);

int main(){
    int arr[] = {1, 2, -1, 3, 5, 11, 12, 13, 2, 100, 22};
    size_t arrSize = sizeof(arr)/sizeof(int);
    int* max = findMax(arr, arrSize, sizeof(int), cmpInt);
    printf("%d\n", *max);

    return 0;
}

void* findMax(void* arr, size_t n, size_t elem_s, int (*cmp)(const void*, const void*)){
    void* maxElement = arr;
    for(size_t i = 1; i < n; i++) if(cmp(arr + i*elem_s, maxElement) > 0) maxElement = arr + i*elem_s;
    return maxElement;
}
int cmpInt(const void* a, const void* b){
    return (*(int*)a > *(int*)b) ? 1 : -1;
}
