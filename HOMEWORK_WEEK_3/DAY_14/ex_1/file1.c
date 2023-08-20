#include <stdio.h>
#include "file.h"
void swap(int*, int*);

int main(void){
    int num1, num2;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    printf("Before swap: Num1 = %d, Num2 = %d\n", num1, num2);
    swap(&num1, &num2);
    printf("After swap: Num1 = %d, Num2 = %d\n", num1, num2);
    return 0;
}
/*
Step                    File 1                     File 2
Preprocessing    gcc -E file1.c -o file1.i  gcc -E file2.c -o file2.i
Compilation      gcc -S file1.i -o file1.s  gcc -S file2.i -o file2.s
Assemble         gcc -c file1.s -o file1.o  gcc -c file2.s -o file2.o
Linking                 gcc file1.o file2.o -o program
*/