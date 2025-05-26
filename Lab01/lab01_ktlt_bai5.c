#include<stdio.h>

// Hàm trả về con trỏ trỏ đên giá trị lớn nhất trong mảng
double* maximum(double* a, int size){

    double *max;   // Khai báo con trỏ để trỏ tới phần tử lớn nhất trong mảng

    max = a; // Gán con trỏ bởi giá trị địa chỉ của phần tử đầu tiên a[0]

    if (a == NULL) return NULL;  // Nếu mảng rỗng trả về NULLNULL
    for(int i = 1; i != size; ++i){
        if(*(a + i) > *max) max = (a + i);  // Duyệt qua mảng, nếu có phần tử nào lớn hơn max thì con trỏ max sẽ trỏ tới đóđó 
    }
    return max; // trả về con trỏ sau cùng thu được

}