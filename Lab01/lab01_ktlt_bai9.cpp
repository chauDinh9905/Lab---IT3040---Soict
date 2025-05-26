#include<iostream>

int main(){
  int n;
  printf("Input:\n");
  scanf("%d", &n);
  int a[n];
  int loop = 1;
  for(int i = 0; i != n; ++i){
    scanf("%d", &a[i]);
  }
  printf("Output:\n");
  for(int i = 0; i != n; ++i){
    int loop = 1;
    while(loop <= n - i){
      int index = i, tmp_loop = 1;
      while(tmp_loop <= loop){
          printf("%d ",a[index++]);
          ++tmp_loop;
      }
      printf("\n");
      ++loop;
    }
  }
}