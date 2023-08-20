#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define COUNT 5

typedef struct Book{
    char title[150];
    char author[100];
    int pageCount;
    double price;
    struct Book* next;
}B;

void generateRandomData(B* book){    
    int titleLength = rand() % 11 + 10; 
    int authorLength = rand() % 11 + 10;

    for(int i = 0; i < titleLength - 1; i++){
        char randomChar = rand() % 26;
        book->title[i] = (i % 2 == 0) ? ('A' + randomChar) : ('a' + randomChar);
    }
    book->title[titleLength - 1] = '\0';

    for(int i = 0; i < authorLength - 1; i++){
        char randomChar = rand() % 26;
        book->author[i] = (i % 2 == 0) ? ('A' + randomChar) : ('a' + randomChar);
    }
    book->author[authorLength - 1] = '\0';

    book->pageCount = rand() % 1996 + 5;
    book->price = (rand() % 100000) / 100.0 - 1.0;
}

void insertBookSorted(B** head, B* newBook){
    if(*head == NULL || strcmp(newBook->title, (*head)->title) < 0){
        newBook->next = *head;
        *head = newBook;
    } 
    else{
        B* current = *head;
        while (current->next != NULL && strcmp(newBook->title, current->next->title) >= 0) current = current->next;
        newBook->next = current->next;
        current->next = newBook;
    }
}

void printBookList(B* head){
    B* current = head;
    while(current != NULL){
        printf("\t\t\t\t\tTitle: %s\nAuthor: %s\nPage Count: %d\nPrice: %.2lf\n",
        current->title, current->author, current->pageCount, current->price);
        current = current->next;
    }
}

void freeBookList(B* head){
    while(head != NULL){
        B* temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){
    srand(time(NULL));

    B* bookList = NULL;

    for(int i = 0; i < COUNT; i++){
        B* newBook = malloc(sizeof(B));
        generateRandomData(newBook);
        insertBookSorted(&bookList, newBook);
    }
    printf("Sorted Book List:\n");
    printBookList(bookList);

    freeBookList(bookList);

    return 0;
}