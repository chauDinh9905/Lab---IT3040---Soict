#include<stdio.h>
#include<stdlib.h>

void allocate_mem(int*** mt, int m, int n){
    *mt = (int**)calloc(m, sizeof(int*));  // Cấp phát m con trỏ và con trỏ mt trỏ tới con trỏ đầu tiêntiên
    for(int i = 0; i!= m; ++i){
        (*mt)[i] = (int*)calloc(n, sizeof(int)); // ở mỗi con trỏ lại cấp phát thêm n phần tử kiểu nguyênnguyên
    }
}

void intput(int** mt, int m, int n){
    for(int i = 0; i != m; ++i){
        for(int j = 0; j != n; ++j){
            printf("mt[%d][%d] = ", i, j);  // Nhập các phần tử cho mảng 2 chiềuchiều
            scanf("%d", &mt[i][j]);
        }
    }
}

void print_arr(int** mt, int m, int n){
    for(int i = 0; i != m; ++i){
        for(int j = 0; j != n; ++j){  // In ra các phần tử của mảng 2 chiềuchiều
            printf("%d ", mt[i][j]);
            
        }
        printf("\n");
    }
}

int sum(int** mt, int m, int n){
    int count = 0;                // Tính tổng giá trị các phần tử chẵn trong mảng 2 chiềuchiều
    for(int i = 0; i != m; ++i){
        for(int j = 0; j != n; ++j){
            if(mt[i][j] % 2 == 0) count += mt[i][j];
        }
        
    }
    return count;
}

int main(){
  
  int m, n, **mt;
  printf("Enter m, n = ");
  scanf("%d%d", &m, &n);
  allocate_mem(&mt, m, n);
  intput(mt, m, n);
  print_arr(mt,m,n);
  printf("The sum of all even elements is %d", sum(mt, m,n));
  for(int i = 0; i!= m; ++i){
      free(mt[i]);  // Giải phóng các mảng con
  }
  free(mt);   // giải phóng con trỏ chính
}