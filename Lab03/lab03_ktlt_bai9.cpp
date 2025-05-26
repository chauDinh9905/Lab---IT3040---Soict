#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000;
const int MOD = 1000000000 + 7;
int n, k1, k2;
int x[MAX];
int so1 = 0;

// Hàm nhập dữ liệu
void inputData(){
    cout << "input: ";
    cin >> n >> k1 >> k2;
}


// Hàm kiểm tra điều kiện cho việc đặt giá trị cho bit tại vị trí a
bool check(int a, int i){
    if(a == 1) return true;
    else {
        if(i == 0){
            // Nếu bit trước đó là 0, không thể có 2 ngày nghỉ liên tiếp
            if(x[a - 1] == 0) return false;
            else {
                // Nếu bit trước đó là 1, cần đảm bảo số ngày làm việc liên tiếp không vượt quá k1
                if(so1 < k1) return false;
            }
        } else {
            // i == 1
            if(x[a - 1] == 0){
                // Nếu bit trước đó là 0, cần đảm bảo số ngày làm việc liên tiếp từ a đến n không ít hơn k1
                if(n - a + 1 < k1) return false;
            } else {
                // Nếu bit trước đó là 1, cần đảm bảo số ngày làm việc liên tiếp không vượt quá k2
                if(so1 >= k2) return false;
            }
        }
        return true;
    }
}

// Hàm in ra một lịch làm việc tốt
void solution(){
    for(int i = 1; i <= n; i++)
        cout << x[i];
    cout << endl;
}

// Hàm thử tất cả các trường hợp
void TRY(int k){
    for(int i = 0; i <= 1; i++){
        if(check(k, i)){
            x[k] = i;
            int pre = so1;
            if(i == 1){
                // Nếu đặt bit là 1, cập nhật số ngày làm việc liên tiếp
                if(x[k - 1] == 1) so1++;
                else so1 = 1;
            } else {
                // Nếu đặt bit là 0, không có ngày làm việc liên tiếp
                so1 = 0;
            }
            if(k == n) solution(); // Nếu đã đặt giá trị cho tất cả các bit, in ra kết quả
            else TRY(k + 1); // Ngược lại, thử đặt giá trị cho bit tiếp theo
            so1 = pre; // Khôi phục số ngày làm việc liên tiếp sau khi thử một giá trị
        }
    }
}

int main(){
    inputData();
    cout << "output: " << endl;
    TRY(1); // Bắt đầu thử với bit đầu tiên
    return 0;
}
