#include <stdio.h>
#include <stdint.h>

#define MAX(x, y, z) (((x) > (y)) ? (((x) > (z)) ? (x) : (z)) : (((y) > (z)) ? (y) : (z)))
#define MIN(x, y, z) (((x) < (y)) ? (((x) < (z)) ? (x) : (z)) : (((y) < (z)) ? (y) : (z)))
#define SETBIT(mask, bit) ((mask) |= (1 << (bit)))
#define CLEARBIT(mask, bit) ((mask) &= ~(1 << (bit)))
#define INVERSEBIT(mask, bit) ((mask) ^= (1 << (bit)))
#define CHECKBIT(mask, bit) (((mask) >> (bit)) & 1)
#define SWAP(a, b) do { (a) ^= (b); (b) ^= (a); (a) ^= (b); } while (0)
#define PRINT_BINARY_UINT8(mask) do{ for(int i = 7; i >= 0; i--){ printf("%d", (mask >> i)&1);} printf("\n"); } while(0)

int main(){
    int x = 5, y = 10, z = 3;
    printf("MAX: %d\n", MAX(x, y, z));
    printf("MIN: %d\n", MIN(x, y, z));
    
    uint8_t mask = 0b01101001;
    printf("Before SETBIT: ");
    PRINT_BINARY_UINT8(mask);
    SETBIT(mask, 4);
    printf("After  SETBIT: ");
    PRINT_BINARY_UINT8(mask);
    
    printf("Before CLEARBIT: ");
    PRINT_BINARY_UINT8(mask);
    CLEARBIT(mask, 4);
    printf("After  CLEARBIT: ");
    PRINT_BINARY_UINT8(mask);
    
    printf("Before INVERSEBIT: ");
    PRINT_BINARY_UINT8(mask);
    INVERSEBIT(mask, 4);
    printf("After  INVERSEBIT: ");
    PRINT_BINARY_UINT8(mask);
    
    printf("CHECKBIT: %d\n", CHECKBIT(mask, 4));

    int a = 5, b = 10;
    SWAP(a, b);
    printf("SWAP: a = %d, b = %d\n", a, b);

    return 0;
}