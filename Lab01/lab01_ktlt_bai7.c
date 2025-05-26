#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("Enter the number of elements: ");
    int n, tmp; // Khai báo kích cỡ mảng và một biến tạm thời
    scanf("%d",&n); // Nhập vào kích cỡ mảng
    int* a = (int*)calloc(n, sizeof(int));  // Cấp phát động n phần tử nguyên cho mảng, con trỏ a trỏ tới phần tử đầu tiên
    for(int i = 0; i != n; ++i){
        scanf("%d", &a[i]);  // Nhập vào giá trị các phần tử của mảng
    }
    printf("The input array is:\n");
    for(int i = 0; i != n; ++i){
        printf("%d ", *(a + i));  // In ra các phần tử của mảngmảng
    }
    for(int i = 0; i != n - 1; ++i){
        for(int j = i + 1; j != n; ++j ){
             if(*(a + i) > *(a + j)){   // nếu phần tử trước đó (ko nhất thiết phải liền kề trước) lớn hơn thì đổi 
                 tmp = *(a+i);
                 *(a + i) = *(a + j);
                 *(a + j) = tmp;
             }
        }
    }
    printf("\nThe sorted array is:\n");
    for(int i = 0; i != n; ++i){
        printf("%d ", *(a + i)); // In mảng sau khi sắp xếp
    }
}