#include<bits/stdc++.h>
using namespace std;
const int MAX = 100;
int S[MAX], H[MAX]; // Khai báo mảng lưu giá trị n và H cho từng testcase
int n; // Khai báo biến n để lưu số lượng testcase
int x[20]; // Khai báo mảng lưu kết quả xâu nhị phân
int L; // Khai báo biến L để lưu giá trị khoảng cách Hamming tạm thời

// Hàm kiểm tra điều kiện để thực hiện bước đi tiếp hay không
bool check(int a, int i, int N_k, int H_k) {
    if (i == 1) {
        // Nếu i bằng 1 (đang xét giá trị 1 trong xâu nhị phân)
        // và việc tăng giá trị khoảng cách Haming L lên 1 vượt quá H_k (khoảng cách Hamming đã đặt ra),
        // thì không thể thực hiện bước đi tiếp được nữa.
        if (L + 1 > H_k) return false;
        else return true;
    } else {
        // Nếu i không phải là 1 (đang xét giá trị 0 trong xâu nhị phân),
        // và N_k - a + L (số lượng chữ số 1 còn lại sau a và số lượng đã đặt trước đó)
        // nhỏ hơn H_k (khoảng cách Hamming đã đặt ra),
        // thì không thể thực hiện bước đi tiếp được nữa.
        if (N_k - a + L < H_k) return false;
        else return true;
    }
}

// Hàm in ra kết quả xâu nhị phân
void solution(int N_k) {
    for (int i = 1; i <= N_k; i++)
        cout << x[i];
    cout << endl;
}

// Hàm thực hiện thuật toán quay lui
void TRY(int a, int N_k, int H_k) {
    for (int i = 0; i <= 1; i++) {
        if (check(a, i, N_k, H_k)) { // gọi hàm check để kiểm tra xem có thực hiện đi tiếp được không
            x[a] = i; // nếu được thì gắn giá trị tại a ở xâu nhị phân có giá trị là i
            int pre_val = L; // lưu lại giá trị khoảng cách Haming
            if (i == 1) L = L + 1; // nếu i = 1 thì tăng khoảng cách Haming L lên 1
            if (a == N_k) solution(N_k); // nếu a là vị trí cuối cùng của xâu, in ra kết quả
            else {
                TRY(a + 1, N_k, H_k); // nếu không, gọi đệ quy tăng lên với vị trí tiếp theo
            }
            L = pre_val; // cập nhật lại giá trị khoảng cách Haming
        }
    }
}

// Hàm chính
int main() {
    cin >> n; // Nhập số lượng testcase
    for (int i = 0; i < n; ++i) {
        cin >> S[i] >> H[i]; // Nhập giá trị n và H cho từng testcase
    }
    cout << endl;

    // Duyệt qua từng testcase để thực hiện thuật toán
    for (int i = 0; i < n; ++i) {
        TRY(1, S[i], H[i]); // Gọi hàm TRY với tham số là a = 1, n = S[i], H = H[i]
        cout << endl; 
    }
}
