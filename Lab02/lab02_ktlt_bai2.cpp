#include<stdio.h>

void change(int& a, int&b, int&c){
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

int main(){
    int a,b,c;
    scanf("%d%d%d", &a, &b, &c);
    printf("Before: %d, %d, %d\n",a,b,c);
    change(a,b,c);
    printf("After: %d, %d, %d",a,b,c);
}