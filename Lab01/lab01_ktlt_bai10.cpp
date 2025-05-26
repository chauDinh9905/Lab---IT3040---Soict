#include <iostream>
#include<stdlib.h>

int main()
{
  int n;
  printf("Input:\n");
  scanf("%d", &n);
  int tong[n][n], tich[n][n];
  int** a = (int**)calloc(n , sizeof(int*));
  for(int i = 0; i < n; i++){
    a[i] = (int*)calloc(n,sizeof(int));
  }
  int** b = (int**)calloc(n , sizeof(int*));
  for(int i = 0; i < n; i++){
    b[i] = (int*)calloc(n , sizeof(int));
  }
  for (int i = 0; i != n; ++i)
  {
    for (int j = 0; j != n; ++j)
    {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 0; i != n; ++i)
  {
    for (int j = 0; j != n; ++j)
    {
      scanf("%d", &b[i][j]);
    }
  }
  for (int i = 0; i != n; ++i)
  {
    for (int j = 0; j != n; ++j)
    {
      tong[i][j] = a[i][j] + b[i][j];
    }
  }
  for (int i = 0; i != n; ++i)
  {
    for (int j = 0; j != n; ++j)
    {
      tich[i][j] = 0;
      for (int k = 0; k != n; ++k)
      {
        tich[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  printf("Output:\n");
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      printf("%d ",tong[i][j]);
    }
    printf("\n");
  }
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      printf("%d ",tich[i][j]);
    }
    printf("\n");
  }
}