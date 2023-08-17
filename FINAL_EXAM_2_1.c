#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

void write_numbers(const char *filename, int N) {
    FILE *file = fopen(filename, "w");
    if(file == NULL) perror("could not open file\n");

    for(int i=0; i<N; i++){
        uint64_t random_number = rand();
        fwrite(&random_number, sizeof(uint64_t), 1, file);
    }

    fclose(file);
    printf("%d nums were written in %s\n", N, filename);
}

int main(int argc, char *argv[]) {
    if(argc != 3) perror("invalid args\n");
    
    srand(time(NULL));
    const char *filename = argv[1];
    int N = atoi(argv[2]);

    write_numbers(filename, N);

    return 0;
}

//./a.out numbers.bin 100