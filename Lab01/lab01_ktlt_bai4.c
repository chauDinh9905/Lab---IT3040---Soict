#include<stdio.h>
 // hàm tính số lượng số chẵn trong một mảngmảng
int counteven(int* a, int n){ // tham số là một con trỏ, kích cỡ của mảngmảng
    int count = 0; // biến để lưu giữ tổngtổng
    for(int i = 0; i != n; ++i){
        if(*(a+i) % 2 == 0) ++count;  // nếu phần tử thứ i là chẵn thì thêm nó vào tổngtổng
    }
    return count; // trả về giá trị tổng sau cùng thu được
}

