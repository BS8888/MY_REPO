#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define COUNT 10

typedef struct Book{
    char title[151];
    char author[101];
    int pages;
    float price;
}B;

int compareTitlesASC(const void *a, const void *b){
    return strcmp(((B *)a)->title, ((B *)b)->title);
}

int compareTitlesDESC(const void *a, const void *b){
    return strcmp(((B *)b)->title, ((B *)a)->title);
}

int compareAuthorsASC(const void *a, const void *b){
    return strcmp(((B *)a)->author, ((B *)b)->author);
}

int compareAuthorsDESC(const void *a, const void *b){
    return strcmp(((B *)b)->author, ((B *)a)->author);
}

int comparePagesASC(const void *a, const void *b){
    return ((B *)a)->pages - ((B *)b)->pages;
}

int comparePagesDESC(const void *a, const void *b){
    return ((B *)b)->pages - ((B *)a)->pages;
}

int comparePriceASC(const void *a, const void *b){
    return ((B *)a)->price - ((B *)b)->price;
}

int comparePriceDESC(const void *a, const void *b){
    return ((B *)b)->price - ((B *)a)->price;
}

void generateRandomData(B *books, int count){
    srand(time(NULL));
    char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for(int i = 0; i < count; i++){
        for(int j = 0; j < 10 + rand() % 11; j++){
            books[i].title[j] = letters[rand() % (sizeof(letters) - 1)];
            books[i].author[j] = letters[rand() % (sizeof(letters) - 1)];
        }
        books[i].title[10 + rand() % 11] = '\0';
        books[i].author[10 + rand() % 11] = '\0';

        books[i].pages = 5 + rand() % 1996;
        books[i].price = 1.0 + (float)rand() / RAND_MAX * 999.0;
    }
}

void printBooks(B *books, int count){
    for(int i = 0; i < count; i++){
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Pages: %d\n", books[i].pages);
        printf("Price: %.2f\n", books[i].price);
        printf("\n");
    }
}

int main() {
    B books[COUNT];
    generateRandomData(books, COUNT);

    qsort(books, COUNT, sizeof(B), compareTitlesASC);
    printf("SORTED BY TITLE(ASC):\n");
    printBooks(books, COUNT);

    qsort(books, COUNT, sizeof(B), compareTitlesDESC);
    printf("SORTED BY TITLE(DESC):\n");
    printBooks(books, COUNT);

    qsort(books, COUNT, sizeof(B), compareAuthorsASC);
    printf("SORTED BY AUTHOR(ASC):\n");
    printBooks(books, COUNT);

    qsort(books, COUNT, sizeof(B), compareAuthorsDESC);
    printf("SORTED BY AUTHOR(DESC):\n");
    printBooks(books, COUNT);

    qsort(books, COUNT, sizeof(B), comparePagesASC);
    printf("SORTED BY PAGES(ASC):\n");
    printBooks(books, COUNT);

    qsort(books, COUNT, sizeof(B), comparePagesDESC);
    printf("SORTED BY PAGES(DESC):\n");
    printBooks(books, COUNT);

    qsort(books, COUNT, sizeof(B), comparePriceASC);
    printf("SORTED BY PRICE(ASC):\n");
    printBooks(books, COUNT);

    qsort(books, COUNT, sizeof(B), comparePriceDESC);
    printf("SORTED BY PRICE(DESC):\n");
    printBooks(books, COUNT);

    return 0;
}