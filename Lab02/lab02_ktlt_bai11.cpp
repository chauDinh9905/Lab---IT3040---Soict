#include<iostream>
#include<vector>
using namespace std;

void nhap_mang( vector<int>& a, int n){
    a.resize(n);
    for(int i = n - 1; i >= 0; --i){
        scanf("%d", &a[i]);
    }
}

void nhan_da_thuc( vector<int>& a, int n, vector<int>& b, int m, vector<int>& c, int k ){
    c.resize(k,0);
    
        for(int j = 0; j < m; j++){
            for(int l = 0; l < n; l++){
                
                    c[j + l] += a[l] * b[j];
                
            }
        }
    
}

int value(vector<int>& c, int n){
    int value_xor = c[0];
    for(int i = 1; i < n; i++){
        value_xor ^= c[i];
    }
    return value_xor;
}

void print_vect(vector<int>& c, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", c[i]);
    }
    printf("\n");
}

int main(){
    int n, m;
    scanf("%d",&n); ++n;
    vector<int> a;
    nhap_mang(a,n);
    //print_vect(a,n);
    scanf("%d",&m); ++m;
    vector<int> b;
    nhap_mang(b,m);
    //print_vect(b,m);
    vector<int> c;
    ///
    nhan_da_thuc(a,n,b,m,c,n+m-1);
    //print(c,n+m-1);
    int value_xor = value(c,n+m-1);
    printf("%d", value_xor);
    return 0;
}