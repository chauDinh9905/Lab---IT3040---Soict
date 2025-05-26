void reversearray(int arr[], int size){

    int l = 0, r = size - 1, tmp;
     while(l < r){
        tmp = arr[l];  // tráo đổi giá trị 2 phần tử cho nhau thông qua indexindex
        arr[l] = arr[r];
        arr[r] = tmp;
        ++l; --r;
     }

}



void ptr_reversearray(int *arr, int size){

    int l, r, tmp;
    l = 0; r = size - 1;

    while(l < r){
        tmp = *(arr + l);  // tráo đổi giá trị 2 phần tử cho nhau thông qua con trỏ và toán tử tham chiếu ngược *
        *(arr + l) = *(arr + r);
        *(arr + r) = tmp;
        l++; r--;
    }

}