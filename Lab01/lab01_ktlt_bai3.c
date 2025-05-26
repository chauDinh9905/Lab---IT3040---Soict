#include <stdio.h>

int main() {

    int x, y, z; // Khai báo 3 biếnbiến

    int *ptr; // Khai báo con trỏ ptrptr

    scanf("%d %d %d", &x, &y, &z); // Nhập giá trị 3 biến từ bàn phím

    printf("Here are the values of x, y, and z:\n");

    printf("%d %d %d\n", x, y, z); // in ra giá trị 3 biếnbiến

    ptr = &x; // Gán cho con trỏ p giá trị địa chỉ của biến x
    *ptr = *ptr + 100; // Tăng giá trị của x thêm 100 thông qua con trỏ ptrr
    ptr = &y; // Gán cho con trỏ p giá trị địa chỉ của biến y
    *ptr = *ptr + 100;  // Tăng giá trị của y thêm 100 thông qua con trỏ ptr
    ptr = &z; // Gán cho con trỏ p giá trị địa chỉ của biến z
    *ptr = *ptr + 100;   // Tăng giá trị của zz thêm 100 thông qua con trỏ ptr 

    printf("Once again, here are the values of x, y, and z:\n");

    printf("%d %d %d\n", x, y, z); // in ra giá trị 3 biến sau khi biến đổi

    return 0;

}   