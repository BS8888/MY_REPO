#include <stdio.h>
#include <stdint.h>
#include <math.h>

void* findMax(void* arr, size_t n, size_t elem_s, int (*cmp)(const void*, const void*));
int cmpUint64(const void* a, const void* b);
int cmpPoint(const void* a, const void* b);
int cmpHuman(const void* a, const void* b);
int countBits(float num);
int cmpFloatBits(const void* a, const void* b);

typedef struct Point{
    double x;
    double y;
    double z;
}P;
typedef struct Human{
    double weight_kg;
    uint16_t height_cm;
}H;

int main(){
    
    uint64_t uintArr[] = {10, 1000, 50, 500};
    size_t uintArrSize = sizeof(uintArr)/sizeof(uint64_t);
    uint64_t* maxUint = findMax(uintArr, uintArrSize, sizeof(uint64_t), cmpUint64);
    printf("Max uint64_t: %lu\n", *maxUint);

    
    P pointArr[] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {0.5, 0.5, 0.5}};
    size_t pointArrSize = sizeof(pointArr)/sizeof(P);
    P* maxPoint = findMax(pointArr, pointArrSize, sizeof(P), cmpPoint);
    printf("Max Point distance: (%lf, %lf, %lf)\n", maxPoint->x, maxPoint->y, maxPoint->z);

    
    H humanArr[] = {{70.0, 175}, {75.0, 180}, {60.0, 160}};
    size_t humanArrSize = sizeof(humanArr)/sizeof(H);
    H* minBmiHuman = findMax(humanArr, humanArrSize, sizeof(H), cmpHuman);
    printf("Human with lowest BMI: Weight: %lf kg, Height: %u cm\n", minBmiHuman->weight_kg, minBmiHuman->height_cm);

    
    float floatArr[] = {1.0, 2.5, 3.25, 4.0};
    size_t floatArrSize = sizeof(floatArr)/sizeof(float);
    float* maxBitsFloat = findMax(floatArr, floatArrSize, sizeof(float), cmpFloatBits);
    printf("Float with most set bits: %f\n", *maxBitsFloat);

    return 0;
}

void* findMax(void* arr, size_t n, size_t elem_s, int (*cmp)(const void*, const void*)) {
    if (n == 0) return NULL;

    void* maxElement = arr;
    for (size_t i = 1; i < n; i++) {
        if (cmp(arr + i * elem_s, maxElement) > 0) {
            maxElement = arr + i * elem_s;
        }
    }
    return maxElement;
}

int cmpUint64(const void* a, const void* b){
    return (*(uint64_t*)a > *(uint64_t*)b) ? 1 : -1;
}

int cmpPoint(const void* a, const void* b){
    double A = sqrt((((P*)a)->x * ((P*)a)->x) + (((P*)a)->y * ((P*)a)->y) + (((P*)a)->z * ((P*)a)->z));
    double B = sqrt((((P*)b)->x * ((P*)b)->x) + (((P*)b)->y * ((P*)b)->y) + (((P*)b)->z * ((P*)b)->z));
    return (A > B) ? 1 : -1;
}

int cmpHuman(const void* a, const void* b){
    double A = ((H*)a)->weight_kg / (((((H*)a)->height_cm / 100.0) * (((H*)a)->height_cm / 100.0)));
    double B = ((H*)b)->weight_kg / (((((H*)b)->height_cm / 100.0) * (((H*)b)->height_cm / 100.0)));
    return (A < B) ? 1 : -1;
}

int countBits(float num){
    union{
        float f;
        uint32_t i;
    }u;
    u.f = num;
    int count = 0;
    while(u.i){
        count += u.i&1;
        u.i >>= 1;
    }
    return count;
}

int cmpFloatBits(const void* a, const void* b){
    int A = countBits(*(float*)a);
    int B = countBits(*(float*)b);
    return (A > B) ? 1 : -1;
}
