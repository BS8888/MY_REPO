#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

int clearBits(uint32_t* maskArr, size_t nitems, size_t bit_index);
int setBits(uint32_t* maskArr, size_t nitems, size_t bit_index);
int checkBits(uint32_t* maskArr, size_t len, size_t bit_index);
void printBin(const uint32_t *arr, size_t n);

int main() {
    uint32_t maskArr[] = {0b10101010, 0b11001100, 0b11110000};
    size_t nitems = sizeof(maskArr)/sizeof(uint32_t);
    size_t bit_index = 3; //for example

    printf("Original maskArr:\n");
    printBin(maskArr, nitems);

    int clearResult = clearBits(maskArr, nitems, bit_index);
    if(clearResult == 0){
        printf("clearBits success:\n");
        printBin(maskArr, nitems);
    } 
    else printf("clearBits error\n");
    
    int setResult = setBits(maskArr, nitems, bit_index);
    if(setResult == 0){
        printf("setBits success:\n");
        printBin(maskArr, nitems);        
    } 
    else printf("setBits error\n");
    
    int checkResult = checkBits(maskArr, nitems, bit_index);
    if(checkResult == -1) printf("checkBits mismatch\n");
    else printf("checkBits success, common bit value: %d\n", checkResult);
    
    return 0;
}

int clearBits(uint32_t* maskArr, size_t nitems, size_t bit_index){
    if(bit_index >= 32) return -1;
    for(size_t i = 0; i < nitems; i++) maskArr[i] &= ~(1u << bit_index);
    return 0;
}

int setBits(uint32_t* maskArr, size_t nitems, size_t bit_index){
    if(bit_index >= 32) return -1; 
    for(size_t i = 0; i < nitems; i++) maskArr[i] |= (1u << bit_index);
    return 0;
}

int checkBits(uint32_t* maskArr, size_t len, size_t bit_index) {
    if(bit_index >= 32) return -1;
    int bitValue = (maskArr[0] >> bit_index) & 1; 
    for(size_t i = 1; i < len; i++){
        int currentBitValue = (maskArr[i] >> bit_index) & 1;
        if(currentBitValue != bitValue) return -1;
    }
    return bitValue;
}
void printBin(const uint32_t *arr, size_t n){
    for(size_t i = 0; i < n; i++){
        for(int j = sizeof(uint32_t)*8-1; j >= 0; j--) printf("%d",(arr[i]>>j)&1);
        printf("\n");
    }
    printf("\n");
}