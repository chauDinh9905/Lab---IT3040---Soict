#include<bits/stdc++.h>
using namespace std;
const int MAX = 100;
int n, k;
int m;
vector<vector<int> > vt; // Chuyển từ lưu trữ các cạnh sang lưu trữ danh sách kề
int x[MAX];
bool visited[MAX];
int res;

void input(){
    cout << "input:";
    cin >> n >> k; // nhập dữ liệu
    cin >> m;
    vt.resize(n+1); // Resize vector vt để có thể lưu trữ danh sách kề của từng đỉnh (từ 0 đến n)
    for(int i=0; i<m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        vt[tmp1-1].push_back(tmp2-1); // Đỉnh tmp2 kề với đỉnh tmp1
        vt[tmp2-1].push_back(tmp1-1); // Đỉnh tmp1 kề với đỉnh tmp2
    }

    for(int i=0; i<n; i++){
        visited[i] = false; // Duyệt qua các đỉnh và đánh dấu là chưa thăm
    }
    res = 0; // Khởi tạo biến res để đếm số lượng đường đi
}

bool check(int a, int i){ // Hàm kiểm tra
    if(a == 0) return true; // Nếu a = 0, tức là đỉnh xuất phát, luôn là một đường đi hợp lệ
    if(visited[i]) return false; // Nếu đã thăm đỉnh i thì trả về false

    int index = 0;
    for(int j=0; j<vt[x[a-1]].size(); j++){
        if(i == vt[x[a-1]][j]) index++; // Kiểm tra xem i có kề với đỉnh trước đó không
    }
    if(index == 0) return false; // Nếu không kề, trả về false

    return true; // Ngược lại, trả về true
}

void solution(){
    res++; // Khi tìm thấy một đường đi hợp lệ, tăng biến đếm res lên 1
}

void TRY(int a){
    for(int i=0; i<n; i++){
        if(check(a, i)){
            visited[i] = true;
            x[a] = i;

            if(a == k) solution(); // Nếu đã đi qua k_viduc đỉnh, gọi hàm solution để tăng biến đếm
            else TRY(a+1); // Ngược lại, thử đi đến đỉnh tiếp theo

            visited[i] = false; // Đánh dấu đỉnh i đã được thăm
        }
    }
}

int main(){
    input(); // Nhập dữ liệu
    TRY(0); // Gọi hàm TRY để bắt đầu thử nghiệm các đường đi
    cout << "output: " << res / 2; // Kết quả được in ra là res chia 2 vì mỗi đường đi được đếm hai lần (u -> v và v -> u)
}
