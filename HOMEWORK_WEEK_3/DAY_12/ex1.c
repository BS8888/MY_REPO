#include <stdio.h>
#include <stdarg.h>
#include <time.h>

void print_time(){
    time_t current_time;
    struct tm *timeinfo;
    char time_str[30];

    time(&current_time);
    timeinfo = localtime(&current_time);
    
    strftime(time_str, sizeof(time_str), "[%d.%m.%Y - %H:%M:%S]", timeinfo);
    
    printf("%s", time_str);
}

int printf_time(const char *format, ...){
    print_time();
    va_list args;
    va_start(args, format);
    int result = vprintf(format, args);
    va_end(args);
    return result;
}

int main(){
    printf_time(" %d %d\n", 10, 20);

    return 0;
}