#include <stdio.h>

typedef struct Student{
    char name[16];
    double avg_grade;
}S;

int main() {
    S students[1000];

    for(int i = 0; i < 1000; i++){
        snprintf(students[i].name, sizeof(students[i].name), "Student %d", i + 1);
        students[i].avg_grade = 2.0 + (i * 0.1);
    }

    FILE *f = fopen("students.bin", "w");
    if(f){
        fwrite(students, sizeof(S), 1000, f);
        fclose(f);
        printf("Binary file 'students.bin' created.\n");
    } 
    else printf("Error creating binary file.\n");
    

    return 0;
}
