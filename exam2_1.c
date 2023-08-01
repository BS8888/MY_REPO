#include <stdio.h>
#include <stdlib.h>

char* str(const char* ptr);

int main() {
    char number_str[501]; 
    printf("Enter the number: ");
    scanf("%500s", number_str); 

    char* result = str(number_str);
    printf("Encoded string: %s\n", result);

    free(result);

    return 0;
}

char* str(const char* ptr){
    char symbols[10] = {'!', '#', '/', '~', '=', '`', '\\', '>', '.', ','};

    int lenght = 0;
    while(ptr[lenght] != '\0') lenght++;

    char* new_str = malloc((lenght+1)*sizeof(char));

    for(int i=0; i<lenght; i++){
        char digit = ptr[i];
        if(i%2 == 0) new_str[i] = 'A' + (digit - '0');
        else new_str[i] = symbols[digit - '0'];
    }
    new_str[lenght] = '\0';

    return new_str;
}
//Enter the number: 10296126782646987676234
//Encoded string: B!C,G#C\H.C\E\J.H\H\C~E