#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct BankAccount {
    uint16_t number;
    char ownerName[100];
    double balance;
    char currency[4];
    struct BankAccount* next;
}BA;

// ;/