#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    int hex;
    float f;
    int i;
    double sum;

    for(int j = 1; j < argc; j++){
        char *arg = argv[j];
        if(arg[0] == '0' && (arg[1] == 'x' || arg[1] == 'X')){
            sscanf(arg, "%x", &hex);
            sum += hex;
        } 
        else if(strchr(arg, '.') != NULL){
            f = strtof(arg, NULL);
            sum += f;
        } 
        else{
            i = atoi(arg);
            sum += i;
        }
    }
    printf("Sum is %.2f\n", sum);

    return 0;
}
//$ ./program 10 12.5 0xff -21 55 0XA 3.14
//Sum is 324.64