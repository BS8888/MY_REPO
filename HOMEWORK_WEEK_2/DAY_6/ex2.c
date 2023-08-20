#include <stdio.h>
#include <stdint.h>
#define TINT 1
#define TDOUBLE 2
#define TCHAR 3

void printValue(const void* valuePtr, uint8_t flag);
int main(){
    int num_int = 23;
    double num_double = 3.14;
    char symbol = 'A';

    printValue(&num_int, TINT);
    printValue(&num_double, TDOUBLE);
    printValue(&symbol, TCHAR);

    return 0;
}
void printValue(const void* valuePtr, uint8_t flag){
    switch(flag){
        case TINT:
            printf("Value: %d\n", *((int*)valuePtr));
            break;
        case TDOUBLE:
            printf("Value: %lf\n", *((double*)valuePtr));
            break;
        case TCHAR:
            printf("Value: %c\n", *((char*)valuePtr));
            break;
        default:
            printf("Invalid type\n");
            break;
    }
}
