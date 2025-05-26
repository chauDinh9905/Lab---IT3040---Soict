#include<bits/stdc++.h>
using namespace std;
const int MAX = 10000;
int n, r;
int price[MAX][MAX];
int x[MAX]; // Mảng lưu trữ lịch trình di chuyển của mỗi người
bool visited[MAX]; // Mảng kiểm tra xem một đỉnh đã được thăm chưa
vector<int> vt; // Vector lưu trữ danh sách các địa điểm mỗi người muốn chụp ảnh
int best; // Biến lưu trữ chi phí đi lại nhỏ nhất
int sum_price; // Biến lưu trữ tổng chi phí đi lại của một lịch trình
int start, des, numOfPoint; // Biến lưu trữ điểm xuất phát, điểm đến, và số điểm cần đi qua

// Hàm nhập dữ liệu
void input(){
    cout << "input:";
    cin >> n >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> price[i][j]; // ma trận đầu vào
        }
    }

}

// Hàm kiểm tra xem một điểm có thể chọn để đi tiếp không
bool check(int a, int i){
    if(visited[vt[i]]) return false; // Nếu đã thăm điểm đó rồi thì trả về false
    if(price[x[a-1]][vt[i]] == 0) return false; // Nếu giá trị chi phí là 0 thì trả về false
    return true;
}

// Hàm xử lý khi một lịch trình hoàn thành
void solution(){
    if(price[x[numOfPoint-2]][des] == 0) return; // Nếu giá trị chi phí cuối cùng là 0 thì không tính
    best = min(best, sum_price + price[x[numOfPoint-2]][des]); // Cập nhật giá trị chi phí nhỏ nhất
}

// Hàm quay lui để thử nghiệm các lịch trình
void TRY(int a){
    for(int i=1; i<numOfPoint-1; i++){
        if(check(a, i)){
            visited[vt[i]] = true; // đánh dấu đã thăm điểm i
            sum_price += price[x[a-1]][vt[i]]; // cập nhật lại tổng chi phí (tính cả tới điểm i)

            x[a] = vt[i]; // cập nhật lịch di chuyển
            if(a == numOfPoint-2)
                solution(); // Nếu đã đi qua tất cả các điểm, thì xem lịch trình có hợp lệ không
            else
                TRY(a+1); // Nếu chưa, thử nghiệm tiếp điểm kế tiếp

            visited[vt[i]] = false; // Đặt lại trạng thái visited để thử nghiệm các lựa chọn khác
            sum_price -= price[x[a-1]][vt[i]]; // Giảm chi phí đi lại
        }
    }
}

int main(){
    input(); // Nhập dữ liệu
    
    // Duyệt qua từng người trong đoàn
    while(r > 0){
        best = INT_MAX;
        sum_price = 0;

        // Đọc danh sách các địa điểm từng người muốn chụp ảnh
        int location;
        while (cin >> location){
            vt.push_back(location - 1);

            if (cin.get() == '\n'){
                break;
            }
        }

        // Khởi tạo dữ liệu trước khi thực hiện quay lui
        start = vt[0];
        des = vt[vt.size()-1];
        numOfPoint = vt.size();
        x[0] = start; x[numOfPoint-1] = des;
        for(int i=0; i<n; i++)
            visited[i] = false;

        TRY(1); // Thực hiện quay lui để tìm lịch trình

        // In ra kết quả
        if(best == INT_MAX)
            cout << "0" << endl;
        else
            cout << best << endl;

        // Xóa vector để chuyển sang người tiếp theo trong đoàn
        vt.erase(vt.begin(), vt.end());
        r--;
    }
}
