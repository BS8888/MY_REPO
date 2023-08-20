#include <stdio.h>

double cubicRoot(double num, double epsilon);
int main(){
    double num;
    printf("Enter a number: ");
    scanf("%lf", &num);

    double epsilon = 0.000001;
    double result = cubicRoot(num, epsilon);

    printf("Cubic root of %.2lf is: %.4lf\n", num, result);

    return 0;
}
double cubicRoot(double num, double epsilon){
    double lower = 0.0;
    double upper = num;
    double approx = (upper+lower) / 2.0;

    while(upper-lower > epsilon){
        if(approx*approx*approx > num) upper = approx;
        else lower = approx;
        approx = (upper+lower) / 2.0;
    }

    return approx;
}