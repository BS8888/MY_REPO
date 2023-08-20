#include <stdio.h>

typedef struct double_comp{
    unsigned long mantissa:52;
    unsigned int exponent:11;
    unsigned int sign:1;
} double_comp;

typedef union D{
    double d;
    double_comp c;
} D;

void printBinaryDouble(double_comp dc){
    for(int i = 63; i >= 0; i--){
        int bit = (dc.sign >> i) & 1;
        printf("%d", bit);
    }
    printf(" ");
    for(int i = 10; i >= 0; i--){
        int bit = (dc.exponent >> i) & 1;
        printf("%d", bit);
    }
    printf(" ");
    for(int i = 51; i >= 0; i--){
        int bit = (dc.mantissa >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

int main() {
    D d1;
    scanf("%lf", &(d1.d));
    unsigned long mantissa_value = d1.c.mantissa;
    printf("Sign: %u\nExponent: %u\nMantissa: %lu\n", d1.c.sign, d1.c.exponent, mantissa_value);

    printf("Binary representation:\n");
    printBinaryDouble(d1.c);

    return 0;
}
//-32.40625