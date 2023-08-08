#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binary_dump(char *filename);
void hex_dump(char *filename);

int main(int argc,char *argv[]){

    char *filename = argv[1];
    char *print_mode = argv[2];

    if(strcmp(print_mode, "-H") == 0) hex_dump(filename);
    else if(strcmp(print_mode, "-B") == 0) binary_dump(filename);
    else return 1;

    return 0;
}

void binary_dump(char *filename){
    FILE *file = fopen(filename, "r");
    
    int c;
    while((c = fgetc(file))!= EOF){
        for(int i = 7; i >= 0; i--) printf("%d", (c >> i)&1);
        printf(" ");
    }
    fclose(file);
    printf("\n");
}

void hex_dump(char *filename){
    FILE *file = fopen(filename, "r");
    
    int c;
    while((c = fgetc(file)) != EOF) printf("%02X ", c);
    fclose(file);
    printf("\n");
}
//test_file "HELLO WORLD!"

//./exam1 test_file.txt -H
//48 45 4C 4C 4F 20 57 4F 52 4C 44 21
//xxd test_file.txt
//00000000: 4845 4c4c 4f20 574f 524c 4421            HELLO WORLD!

//./exam1 test_file.txt -B
//01001000 01000101 01001100 01001100 01001111 00100000 01010111 01001111 01010010 01001100 01000100 00100001
//xxd -b test_file.txt
/*
00000000: 01001000 01000101 01001100 01001100 01001111 00100000  HELLO 
00000006: 01010111 01001111 01010010 01001100 01000100 00100001  WORLD!
*/