#include <stdio.h>
#include <stdarg.h>

int my_printf(const char *fmt, ...){
    va_list args;
    va_start(args, fmt);
    
    int printed_chars = 0;
    
    while(*fmt){
        if(*fmt == '%'){
            fmt++;
            switch(*fmt){
                case 'd': {
                    int value = va_arg(args, int);
                    printed_chars += printf("%d", value);
                    break;
                }
                case 'f': {
                    double value = va_arg(args, double);
                    printed_chars += printf("%f", value);
                    break;
                }
                case 'c': {
                    char value = va_arg(args, int);
                    putc(value, stdout);
                    printed_chars++;
                    break;
                }
                default:
                    putc(*fmt, stdout);
                    printed_chars++;
            }
        } 
        else{
            putc(*fmt, stdout);
            printed_chars++;
        }
        fmt++;
    }

    va_end(args);

    return printed_chars;
}

int main(){
    int a = 42;
    double b = 3.14;
    char c = 'X';

    int total_printed = my_printf("%d %f %c", a, b, c);
    printf("\nTotal printed characters: %d\n", total_printed);

    return 0;
}