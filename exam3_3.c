#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Product {
    double old_price;
    double new_price;
    unsigned int id;
    char product_type;
    char product_name[8];
}Product;

char getRandomProductType(){
    char types[]= {'A', 'B', 'C', 'D'};
    int index = rand()%4;
    return types[index];
}

void generateRandomProductName(char* name){
    const char* products[]= {"Product A", "Product B", "Product C", "Product D"};
    int index = rand()%4;
    strcpy(name, products[index]);
}

int main() {
    const int numProducts = 40;
    srand(time(NULL));

    Product products[numProducts];

    for(int i = 0; i < numProducts; i++){
        products[i].old_price = 4.99+((double)rand()/RAND_MAX)*(100.4-4.99);
        products[i].new_price = 4.99+((double)rand()/RAND_MAX)*(100.4-4.99);
        products[i].id = i + 1;
        products[i].product_type = getRandomProductType();
        generateRandomProductName(products[i].product_name);
    }

    for(int i = 0; i < numProducts; ++i){
        printf("Product %d:\n", i + 1);
        printf("  Old Price: $%.2lf\n", products[i].old_price);
        printf("  New Price: $%.2lf\n", products[i].new_price);
        printf("  ID: %u\n", products[i].id);
        printf("  Product Type: %c\n", products[i].product_type);
        printf("  Product Name: %s\n", products[i].product_name);
        printf("\n");
    }

    return 0;
}