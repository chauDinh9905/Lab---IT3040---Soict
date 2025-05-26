#include<stdio.h>

int main(){
    int x, y, z; // Khai báo 3 biến 
    //int* p;
    printf("Enter three integers:\n");
    scanf("%d %d %d", &x, &y, &z); // Nhập vào từ bàn phím giá trị 3 biến
    int* p; // Khai bá0 con trỏ p trỏ tới kiểu integer
    printf("The three integers are:\n");
    p = &x; printf("x = %d\n",*p); // Gán cho p giá trị địa chỉ của biến x rồi in giá trị của x thông qua toán tử tham chiếu ngược *
    p = &y; printf("y = %d\n",*p); // Gán cho p giá trị địa chỉ của biến y rồi in giá trị của y thông qua toán tử tham chiếu ngược *
    p = &z; printf("z = %d\n",*p); // Gán cho p giá trị địa chỉ của biến z rồi in giá trị của z thông qua toán tử tham chiếu ngược *
}