#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define MAX_ROW_LENGTH 100

unsigned int N, M;

typedef struct RowData{
    char row[MAX_ROW_LENGTH];
    int rowNum;
    int values[100];
    double average;
}RD;

void *calculate_average(void *arg) {
    RD *row_data =arg;
    double sum = 0;
    for(int i=0; i<M; i++) sum += row_data->values[i];
    row_data->average = sum/M;
    return NULL;
}

int main() {
    
    scanf("%d %d", &N, &M);

    RD *rows = malloc(N*sizeof(RD));
    for(int i=0; i<N; i++){
        scanf("%s %d", rows[i].row, &rows[i].rowNum);
        for(int j=0; j<M; j++) scanf("%d", &rows[i].values[j]);      
    }

    char output_filename[100];
    scanf("%s", output_filename);

    FILE *result_file = fopen(output_filename, "w");
    if(result_file == NULL) perror("could not open file\n");
    

    pthread_t threads[N];
    for(int i = 0; i < N; i++) if(pthread_create(&threads[i], NULL, calculate_average, (void *)&rows[i])==-1) perror("could not create thread\n");
    
    for(int i=0; i<N; i++){
        pthread_join(threads[i], NULL);
        fprintf(result_file, "%s %d %.3f\n", rows[i].row, rows[i].rowNum, rows[i].average);
    }

    fclose(result_file);
    free(rows);

    return 0;
}

/*
input:
5 6
ROW 1 21 14 31 -51 33 1
ROW 2 41 56 74 -21 42 -52
ROW 3 51 61 17 37 97 39
ROW 4 19 -1 85 -9 51 2
ROW 5 71 26 43 36 22 99
file1

output in file:
ROW 1 8.167
ROW 2 23.333
ROW 3 50.333
ROW 4 24.500
ROW 5 49.500

*/