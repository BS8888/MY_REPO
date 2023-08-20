#include <stdio.h>
#include <stdbool.h>
#include <time.h>

typedef struct MyTime{
    unsigned int year : 12;     // 12 bits for year (up to 4095)
    unsigned int month : 4;     // 4 bits for month (up to 15)
    unsigned int day : 5;       // 5 bits for day (up to 31)
    unsigned int hour : 5;      // 5 bits for hour (up to 31)
    unsigned int minute : 6;    // 6 bits for minute (up to 63)
    unsigned int second : 6;    // 6 bits for second (up to 63)
}T;
int isLeapYear(T t);
int totalDaysInYear(T t);
void printMonth(T t);
int secondsPassed();

int main() {
    T t;
    time_t currentTime;
    struct tm* localTime;

    time(&currentTime);
    localTime = localtime(&currentTime);
    
    t.year = localTime->tm_year + 1900; 
    t.month = localTime->tm_mon + 1;
    t.day = localTime->tm_mday;
    t.hour = localTime->tm_hour;
    t.minute = localTime->tm_min;
    t.second = localTime->tm_sec;

    printf("Size of MyTime: %zu bytes\n", sizeof(T));
    printf("Is leap year: %d\n", isLeapYear(t));
    printf("Total days in year: %d\n", totalDaysInYear(t));
    printf("Month: ");
    printMonth(t);
    printf("Seconds passed since 1970: %d\n", secondsPassed());

    return 0;
}

int isLeapYear(T t){
    if((t.year % 4 == 0 && t.year % 100 != 0) || (t.year % 400 == 0)) return 1; // Leap year
    return 0; // Not a leap year
}

int totalDaysInYear(T t){
    return isLeapYear(t) ? 366 : 365;
}

void printMonth(T t){
    const char* months[] = {"January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November", "December"};
    printf("%s\n", months[t.month - 1]);
}

int secondsPassed(){
    time_t currentTime;
    time(&currentTime);
    struct tm epochTime = {0};
    epochTime.tm_year=70;
    epochTime.tm_mon=0;
    epochTime.tm_mday=1;
    epochTime.tm_hour=0;
    epochTime.tm_min=0;
    epochTime.tm_sec=0;
    int totalSeconds = difftime(currentTime, mktime(&epochTime));
    return totalSeconds;
}