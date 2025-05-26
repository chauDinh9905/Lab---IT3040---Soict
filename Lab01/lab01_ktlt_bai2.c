#include<stdio.h>

int main(){
    int a[7] = {13, -355, 235, 47, 67, 943, 1222}; // Khởi tạo một mảng 
    for(int i = 0; i != 5; ++i){
        printf("Address of the element %d:", i+1 );
        printf("%p\n", a + i); // in gia giá chị địa chỉ của phần tử thứ i + 1
    }
}