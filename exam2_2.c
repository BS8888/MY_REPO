#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define MODEL_LENGTH 20

typedef struct Car{
    char model[MODEL_LENGTH + 1];
    uint8_t maxspeed;
    double price;
}C;

int cmpModelAsc(const void *p1, const void *p2){
    return strcmp(((C*)p1)->model, ((C*)p2)->model);
}
int cmpModelDesc(const void *p1, const void *p2){
    return strcmp(((C*)p2)->model, ((C*)p1)->model);
}
int cmpSpeedAsc(const void *p1, const void *p2){
    return ((C*)p1)->maxspeed - ((C*)p2)->maxspeed;
}
int cmpSpeedDesc(const void *p1, const void *p2){
    return ((C*)p2)->maxspeed - ((C*)p1)->maxspeed;
}
int cmpPriceAsc(const void *p1, const void *p2) {
    return (((C*)p1)->price > ((C*)p2)->price)?1:-1;
}
int cmpPriceDesc(const void *p1, const void *p2) {
    return (((C*)p1)->price > ((C*)p2)->price)?-1:1;
}

int(*getComparator(int n))(const void *, const void *){
    switch(n){
    case 1:
        return cmpModelAsc;
    case 2:
        return cmpModelDesc;
    case 3:
        return cmpSpeedAsc;
    case 4:
        return cmpSpeedDesc;
    case 5:
        return cmpPriceAsc;
    case 6:
        return cmpPriceDesc;
    default:
        return NULL;
    }
}