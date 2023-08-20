#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
    char name[16];
    double avg_grade;
}S;

int main(){
    FILE *file = fopen("students.bin", "r");
    if (file == NULL) perror("Error opening file");
    S students[1000];
    size_t count = fread(students, sizeof(S), 1000, file);
    fclose(file);

    if(count < 1000){
        fprintf(stderr, "Error reading from file\n");
        return 1;
    }

    double max_avg_grade = students[0].avg_grade;
    int max_avg_index = 0;

    for(int i = 1; i < 1000; i++){
        if(students[i].avg_grade > max_avg_grade){
            max_avg_grade = students[i].avg_grade;
            max_avg_index = i;
        }
    }

    printf("Student with the highest average grade:\n");
    printf("Name: %s\n", students[max_avg_index].name);
    printf("Average Grade: %.2lf\n", students[max_avg_index].avg_grade);

    return 0;
}
