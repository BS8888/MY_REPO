#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_strings(const void *a, const void *b){
    return strcmp(*(const char **)a, *(const char **)b);
}

int main(int argc, char *argv[]) {
    if(argc < 2) exit(EXIT_FAILURE);
    
    qsort(&argv[1], argc - 1, sizeof(char *), compare_strings);

    char output_filename[100];
    printf("Enter the output filename: ");
    scanf("%s", output_filename);

    FILE *output_file = fopen(output_filename, "w");
    if(output_file == NULL) perror("Error opening file");

    for(int i = 1; i < argc; i++) fprintf(output_file, "%s\n", argv[i]);
    
    fclose(output_file);
    printf("Sorted arguments written to %s\n", output_filename);

    return 0;
}
