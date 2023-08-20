#include <stdio.h>
#include <stdint.h>

void printBinary(uint16_t num);
void swapBytes(uint16_t* word);

int main(){
    uint16_t number = 0b00001111;

    printf("Before swap: ");
    printBinary(number);
    swapBytes(&number);
    printf("\nAfter swap:  ");
    printBinary(number);
    printf("\n");
    return 0;
}
void printBinary(uint16_t num){
    for(int i = sizeof(uint16_t)*8-1; i >= 0; i--) printf("%d", (num >> i)&1);
}
void swapBytes(uint16_t* word){
    *word = ((*word & 255)<<8 | (*word & 255)>>8);
}
