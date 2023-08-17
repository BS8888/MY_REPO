#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int sum_of_digits(uint64_t number){
    int sum = 0;
    while(number > 0){
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int main(int argc, char *argv[]) {
    if (argc < 2) perror("invalid args\n");

    int total_sum = 0;

    for(int i = 1; i<argc; i++){
        FILE *file = fopen(argv[i], "r");
        if(file == NULL){
            perror("could not open file\n");
            continue;
        }
        uint64_t number;
        int file_sum = 0;
        while(fread(&number, sizeof(uint64_t), 1, file)) file_sum += sum_of_digits(number);
        fclose(file);
        printf("Sum in %s is %d\n", argv[i], file_sum);
        total_sum += file_sum;
    }

    printf("Total sum is %d\n", total_sum);

    return 0;
}
