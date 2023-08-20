#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int expression();
int term();
int factor();
int exponent();

char *input_expr;
int indx = 0;

int main() {
    input_expr = malloc(100);
    fgets(input_expr, 100, stdin);
    input_expr[strlen(input_expr) - 1] = '\0';

    int result = expression();
    printf("%d\n", result);

    free(input_expr);

    return 0;
}

int expression(){
    int result = term();
    while(input_expr[indx] == '+' || input_expr[indx] == '-'){
        char operator = input_expr[indx];
        indx++;
        int value = term();
        if(operator == '+') result += value;
        else result -= value;
    }
    return result;
}

int term(){
    int result = factor();
    while(input_expr[indx] == '*' || input_expr[indx] == '/'){
        char operator = input_expr[indx];
        indx++;
        int value = factor();
        if(operator == '*') result *= value;
        else result /= value;
    }
    return result;
}

int factor(){
    int result;
    if(input_expr[indx] == '('){
        indx++;
        result = expression();
        indx++;
    } 
    else result = exponent();
    
    return result;
}

int exponent(){
    int result = 0;
    while(isdigit(input_expr[indx])){
        result = result * 10 + (input_expr[indx] - '0');
        indx++;
    }
    if(input_expr[indx] == '^'){
        indx++;
        int power = factor();
        result = pow(result, power);
    }
    return result;
}

// ((5+(3+(4+2)))+(2^10))
// 1038