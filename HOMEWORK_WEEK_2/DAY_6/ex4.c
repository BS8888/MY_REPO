#include <stdio.h>
#include <stdlib.h>

int isPositive(int a);
int addOne(int a);
void filter_and_map(const int arr[], size_t n, int (*filter_f)(int), int (*map_f)(int), int dest[], size_t* dest_cnt);
int isEven(int num);
int isPrime(int num);
int square(int num);
int countSetBits(int num);
int element(int num);

int main(){
    int arr[8] = {1, 2, 3, 4, -1, -2, 11, -100};
    int dest[10];
    size_t new_size;

    filter_and_map(arr, 8, isPositive, addOne, dest, &new_size);
    printf("new_size = %zu\n", new_size);
    printf("dest = {");
    for(size_t i = 0; i < new_size; i++){
        printf("%d", dest[i]);
        if(i < new_size-1) printf(", ");
    }
    printf("}\n");


    filter_and_map(arr, 8, isEven, element, dest, &new_size);
    printf("Even numbers: ");
    for(size_t i = 0; i < new_size; i++) printf("%d ", dest[i]);
    printf("\n");


    filter_and_map(arr, 8, isPrime, square, dest, &new_size);
    printf("Squares of prime numbers: ");
    for(size_t i = 0; i < new_size; i++) printf("%d ", dest[i]);
    printf("\n");

    
    filter_and_map(arr, 8, isPositive, countSetBits, dest, &new_size);
    printf("Count of set bits for positive numbers: ");
    for(size_t i = 0; i < new_size; i++) printf("%d ", dest[i]);
    printf("\n");

    return 0;
}

int isPositive(int a){
    return a > 0;
}

int addOne(int a){
    return a + 1;
}

void filter_and_map(const int arr[], size_t n, int (*filter_f)(int), int (*map_f)(int), int dest[], size_t* dest_cnt){
    size_t count = 0;

    for(size_t i = 0; i < n; i++){
        if(filter_f(arr[i])){
            if(dest != NULL) dest[count] = map_f(arr[i]);
            count++;
        }
    }
    if(dest_cnt != NULL) *dest_cnt = count;
    
}

int isEven(int num){
    return num % 2 == 0;
}

int isPrime(int num){
    if(num <= 1) return 0;
    if(num <= 3) return 1;
    if(num%2 == 0 || num%3 == 0) return 0;    
    for(int i = 5; i * i <= num; i += 6) if(num %i == 0 || num % (i+2) == 0) return 0;
    
    return 1;
}

int square(int num){
    return num*num;
}

int countSetBits(int num){
    int count = 0;
    while(num > 0){
        count += num&1;
        num >>= 1;
    }
    return count;
}

int element(int num){
    return num;
}