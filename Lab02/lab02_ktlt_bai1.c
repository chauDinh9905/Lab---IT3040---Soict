#include<stdio.h>
#include<math.h>

double canh_huyen(double a, double b){
    double c;
    c = sqrt(a*a + b*b);
    return c;
}

int main(){
    double a,b;
    scanf("%lf%lf", &a, &b);
    double c = canh_huyen(a,b);
    printf("z = %.2lf",c);
}